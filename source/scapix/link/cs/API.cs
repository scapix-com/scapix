using System;
using System.Runtime.InteropServices;
using System.Reflection;

namespace Scapix.Link
{
    public class CppException : System.Exception, IDisposable
    {
        public CppException(IntPtr cpp) { this.cpp = cpp; }
        public override String Message { get { return API.GetExceptionMessage(cpp); } }

        ~CppException()
        {
            Dispose();
        }

        public void Dispose()
        {
            if (cpp != IntPtr.Zero)
            {
                API.DeleteException(cpp);
                cpp = IntPtr.Zero;
            }
        }

        internal IntPtr Release()
        {
            IntPtr temp = cpp;
            cpp = IntPtr.Zero;
            return temp;
        }

        IntPtr cpp;
    }

    [StructLayout(LayoutKind.Sequential)]
    struct NativeObject<T> where T : class
    {
        public void Set(T obj, GCHandleType type = GCHandleType.Normal)
        {
            ptr = GCHandle.ToIntPtr(GCHandle.Alloc(obj, type));
        }

        public T Get()
        {
            if (ptr == IntPtr.Zero)
                return null;

            GCHandle gch = GCHandle.FromIntPtr(ptr);
            T obj = (T)gch.Target;
            gch.Free();
            return obj;
        }

        private IntPtr ptr;
    }

    /* static */ abstract class API
    {
        [ThreadStatic]
        static Exception exception;

        public static void CheckException()
        {
            var e = exception;

            if (e != null)
            {
                exception = null;
                throw e;
            }
        }

        // duplicated in Bridge.Object

        protected static T ScapixCpp<T>(T v) where T : struct { return v; }
        protected static IntPtr ScapixCpp(object v) { return ToNative(v); }
        protected static IntPtr ScapixCpp<T>(T[] v) where T : struct { return ToNative(v, GCHandleType.Pinned); }
        protected static byte ScapixCpp(bool v) { return v ? (byte)1 : (byte)0; }

        protected static T ScapixCs<T>(T v) where T : struct { return v; }
        protected static T ScapixCs<T>(IntPtr v) where T : class { return FromNative<T>(v); }
        protected static bool ScapixCs<T>(byte v) { return v != 0 ; }

        protected static T ScapixCallback<T>(Func<T> func)
        {
            try
            {
                return func();
            }
            catch (Link.CppException e)
            {
                Link.API.CppSetException(e.Release(), true);
            }
            catch (Exception e)
            {
                Link.API.CppSetException(ScapixCpp(e), false);
            }

            return default;
        }

        protected static void ScapixCallback(Action func)
        {
            try
            {
                func();
            }
            catch (Link.CppException e)
            {
                Link.API.CppSetException(e.Release(), true);
            }
            catch (Exception e)
            {
                Link.API.CppSetException(ScapixCpp(e), false);
            }
        }

        // logic duplicated in Bridge.Object

        public static To Convert<From, To>(From v)
        {
            if (typeof(From) == typeof(To))
                return (To)(object)v;

            if (typeof(To) == typeof(IntPtr))
                return (To)(object)ToNative(v);

            if (typeof(From) == typeof(IntPtr))
                return FromNative<To>((IntPtr)(object)v);

            System.Diagnostics.Debug.Assert(false);

            return default;
        }

        public sealed class ObjectMarshaler : ICustomMarshaler
        {
            static readonly ObjectMarshaler instance = new ObjectMarshaler();

            public static ICustomMarshaler GetInstance(string cookie)
            {
                return instance;
            }

            public IntPtr MarshalManagedToNative(object obj)
            {
                return ToNative(obj);
            }

            public object MarshalNativeToManaged(IntPtr ptr)
            {
                return FromNative<object>(ptr);
            }

            public void CleanUpNativeData(IntPtr ptr)
            {
            }

            public void CleanUpManagedData(object obj)
            {
            }

            public int GetNativeDataSize()
            {
                return -1;
            }
        }

        delegate IntPtr ArrayCreateDelegate(int size);

        [StructLayout(LayoutKind.Sequential)]
        public struct Array<T>
        {
            public static Array<T> Init()
            {
                return new Array<T>(0);
            }

            static IntPtr Create(int size)
            {
                return ToNative(new T[size]);
            }

            readonly ArrayCreateDelegate create;

            Array(int unused)
            {
                create = new ArrayCreateDelegate(Create);
            }
        }

        delegate IntPtr DictionaryCreateDelegate();
        delegate void DictionaryAddDelegate<CppKey, CppValue>(IntPtr dictionary, CppKey key, CppValue value);
        delegate void DictionaryIterateDelegate(IntPtr dictionary, IntPtr data, IntPtr callback);
        delegate void DictionaryIterateCallbackDelegate<CppKey, CppValue>(CppKey key, CppValue value, IntPtr data);

        [StructLayout(LayoutKind.Sequential)]
        public struct Dictionary<TKey, TValue, CppKey, CppValue>
        {
            public static Dictionary<TKey, TValue, CppKey, CppValue> Init()
            {
                return new Dictionary<TKey, TValue, CppKey, CppValue>(0);
            }

            static IntPtr Create()
            {
                return ToNative(new System.Collections.Generic.Dictionary<TKey, TValue>());
            }

            public static void Add(IntPtr dictionary, CppKey key, CppValue value)
            {
                FromNative<System.Collections.Generic.Dictionary<TKey, TValue>>(dictionary).Add(Convert<CppKey, TKey>(key), Convert<CppValue, TValue>(value));
            }

            static void Iterate(IntPtr dictionary, IntPtr data, IntPtr callback)
            {
                var call = Marshal.GetDelegateForFunctionPointer<DictionaryIterateCallbackDelegate<CppKey, CppValue>>(callback);

                foreach (var pair in FromNative<System.Collections.Generic.Dictionary<TKey, TValue>>(dictionary))
                    call(Convert<TKey, CppKey>(pair.Key), Convert<TValue, CppValue>(pair.Value), data);
            }

            readonly DictionaryCreateDelegate create;
            readonly DictionaryAddDelegate<CppKey, CppValue> add;
            readonly DictionaryIterateDelegate iterate;

            Dictionary(int unused)
            {
                create = new DictionaryCreateDelegate(Create);
                add = new DictionaryAddDelegate<CppKey, CppValue>(Add);
                iterate = new DictionaryIterateDelegate(Iterate);
            }
        }

        // Marshal.PtrToStringUTF8() not in .NET Framework 4.7.2

        //static string PtrToStringUTF8(IntPtr ptr, int length)
        //{
        //    if (ptr == IntPtr.Zero)
        //        return null;

        //    byte[] buff = new byte[length];
        //    Marshal.Copy(ptr, buff, 0, length);
        //    return System.Text.UTF8Encoding.UTF8.GetString(buff);
        //}

        //static string PtrToStringUTF8(IntPtr ptr)
        //{
        //    if (ptr == IntPtr.Zero)
        //        return null;

        //    int len = 0;

        //    while (Marshal.ReadByte(ptr, len) != 0)
        //        ++len;

        //    if (len == 0)
        //        return string.Empty;

        //    byte[] buffer = new byte[len];
        //    Marshal.Copy(ptr, buffer, 0, buffer.Length);
        //    return System.Text.Encoding.UTF8.GetString(buffer);
        //}

        // ToNative() allocates object reference and must be matched with FromNative() or ReleaseRef() to free the reference.

        public static IntPtr ToNative(object obj)
        {
            if (obj == null)
                return IntPtr.Zero;

            return GCHandle.ToIntPtr(GCHandle.Alloc(obj));
        }

        public static IntPtr ToNative(object obj, GCHandleType type)
        {
            if (obj == null)
                return IntPtr.Zero;

            return GCHandle.ToIntPtr(GCHandle.Alloc(obj, type));
        }

        public static T FromNative<T>(IntPtr p) // where T : class
        {
            System.Diagnostics.Debug.Assert(typeof(T).IsClass);

            if (p == IntPtr.Zero)
                return default; // null

            var gch = GCHandle.FromIntPtr(p);
            T obj = (T)gch.Target;
            gch.Free();
            return obj;
        }

#if ENABLE_IL2CPP
        [AOT.MonoPInvokeCallback(typeof(CsApi.CopyRefDelegate))]
#endif
        static IntPtr CopyRef(IntPtr p, GCHandleType t)
        {
            var obj = GCHandle.FromIntPtr(p).Target;

            if (obj == null)
                return IntPtr.Zero;

            return GCHandle.ToIntPtr(GCHandle.Alloc(obj, t));
        }

#if ENABLE_IL2CPP
        [AOT.MonoPInvokeCallback(typeof(CsApi.ReleaseRefDelegate))]
#endif
        static void ReleaseRef(IntPtr r)
        {
            GCHandle.FromIntPtr(r).Free();
        }

#if ENABLE_IL2CPP
        [AOT.MonoPInvokeCallback(typeof(CsApi.CreateStringDelegate))]
#endif
        static IntPtr CreateString(IntPtr data, int size)
        {
            // Marshal.PtrToStringUTF8() not in .NET Framework 4.7.2
            // return ToNative(Marshal.PtrToStringUTF8(data, size));

            byte[] buff = new byte[size];
            Marshal.Copy(data, buff, 0, size);
            return ToNative(System.Text.UTF8Encoding.UTF8.GetString(buff));
        }

#if ENABLE_IL2CPP
        [AOT.MonoPInvokeCallback(typeof(CsApi.SetStringDelegate))]
#endif
        static void SetString(IntPtr str, IntPtr data)
        {
            cppApi.SetString((string)GCHandle.FromIntPtr(str).Target, data);
        }

#if ENABLE_IL2CPP
        [AOT.MonoPInvokeCallback(typeof(CsApi.GetFuncDelegate))]
#endif
        static IntPtr GetFunc(IntPtr d)
        {
            return Marshal.GetFunctionPointerForDelegate((Delegate)GCHandle.FromIntPtr(d).Target);
        }

#if ENABLE_IL2CPP
        [AOT.MonoPInvokeCallback(typeof(CsApi.GetArraySizeDelegate))]
#endif
        static int GetArraySize(IntPtr arr)
        {
            return ((Array)GCHandle.FromIntPtr(arr).Target).Length;
        }

#if ENABLE_IL2CPP
        [AOT.MonoPInvokeCallback(typeof(CsApi.GetObjectArrayElementDelegate))]
#endif
        static IntPtr GetObjectArrayElement(IntPtr arr, int index)
        {
            return ToNative(((object[])GCHandle.FromIntPtr(arr).Target)[index]);
        }

#if ENABLE_IL2CPP
        [AOT.MonoPInvokeCallback(typeof(CsApi.SetObjectArrayElementDelegate))]
#endif
        static void SetObjectArrayElement(IntPtr arr, int index, IntPtr value)
        {
            ((object[])GCHandle.FromIntPtr(arr).Target)[index] = GCHandle.FromIntPtr(value).Target;
        }

#if ENABLE_IL2CPP
        [AOT.MonoPInvokeCallback(typeof(CsApi.RegisterClassDelegate))]
#endif
        static ClassCsApi RegisterClass(string className, IntPtr classCppApi)
        {
            MethodInfo method = Type.GetType(className).GetMethod("ScapixRegister", BindingFlags.NonPublic | BindingFlags.Static);
            return (ClassCsApi)method.Invoke(null, new object[] { classCppApi });
        }

#if ENABLE_IL2CPP
        [AOT.MonoPInvokeCallback(typeof(CsApi.GetCppDelegate))]
#endif
        static IntPtr GetCpp(IntPtr obj)
        {
            return ((Bridge.Object)GCHandle.FromIntPtr(obj).Target).cpp;
        }

#if ENABLE_IL2CPP
        [AOT.MonoPInvokeCallback(typeof(CsApi.AddrOfPinnedObjectDelegate))]
#endif
        static IntPtr AddrOfPinnedObject(IntPtr obj)
        {
            return GCHandle.FromIntPtr(obj).AddrOfPinnedObject();
        }

#if ENABLE_IL2CPP
        [AOT.MonoPInvokeCallback(typeof(CsApi.CreateStructArrayDelegate))]
#endif
        static IntPtr CreateStructArrayBool(int size)
        {
            return ToNative(new bool[size], GCHandleType.Pinned);
        }

#if ENABLE_IL2CPP
        [AOT.MonoPInvokeCallback(typeof(CsApi.CreateStructArrayDelegate))]
#endif
        static IntPtr CreateStructArraySbyte(int size)
        {
            return ToNative(new sbyte[size], GCHandleType.Pinned);
        }

#if ENABLE_IL2CPP
        [AOT.MonoPInvokeCallback(typeof(CsApi.CreateStructArrayDelegate))]
#endif
        static IntPtr CreateStructArrayShort(int size)
        {
            return ToNative(new short[size], GCHandleType.Pinned);
        }

#if ENABLE_IL2CPP
        [AOT.MonoPInvokeCallback(typeof(CsApi.CreateStructArrayDelegate))]
#endif
        static IntPtr CreateStructArrayInt(int size)
        {
            return ToNative(new int[size], GCHandleType.Pinned);
        }

#if ENABLE_IL2CPP
        [AOT.MonoPInvokeCallback(typeof(CsApi.CreateStructArrayDelegate))]
#endif
        static IntPtr CreateStructArrayLong(int size)
        {
            return ToNative(new long[size], GCHandleType.Pinned);
        }

#if ENABLE_IL2CPP
        [AOT.MonoPInvokeCallback(typeof(CsApi.CreateStructArrayDelegate))]
#endif
        static IntPtr CreateStructArrayByte(int size)
        {
            return ToNative(new byte[size], GCHandleType.Pinned);
        }

#if ENABLE_IL2CPP
        [AOT.MonoPInvokeCallback(typeof(CsApi.CreateStructArrayDelegate))]
#endif
        static IntPtr CreateStructArrayUshort(int size)
        {
            return ToNative(new ushort[size], GCHandleType.Pinned);
        }

#if ENABLE_IL2CPP
        [AOT.MonoPInvokeCallback(typeof(CsApi.CreateStructArrayDelegate))]
#endif
        static IntPtr CreateStructArrayUint(int size)
        {
            return ToNative(new uint[size], GCHandleType.Pinned);
        }

#if ENABLE_IL2CPP
        [AOT.MonoPInvokeCallback(typeof(CsApi.CreateStructArrayDelegate))]
#endif
        static IntPtr CreateStructArrayUlong(int size)
        {
            return ToNative(new ulong[size], GCHandleType.Pinned);
        }

#if ENABLE_IL2CPP
        [AOT.MonoPInvokeCallback(typeof(CsApi.CreateStructArrayDelegate))]
#endif
        static IntPtr CreateStructArrayFloat(int size)
        {
            return ToNative(new float[size], GCHandleType.Pinned);
        }

#if ENABLE_IL2CPP
        [AOT.MonoPInvokeCallback(typeof(CsApi.CreateStructArrayDelegate))]
#endif
        static IntPtr CreateStructArrayDouble(int size)
        {
            return ToNative(new double[size], GCHandleType.Pinned);
        }

#if ENABLE_IL2CPP
        [AOT.MonoPInvokeCallback(typeof(CsApi.SetExceptionDelegate))]
#endif
        static void SetException(IntPtr e, bool cpp)
        {
            if (cpp)
                exception = new CppException(e);
            else
                exception = FromNative<Exception>(e);
        }

#if ENABLE_IL2CPP
        [AOT.MonoPInvokeCallback(typeof(CsApi.GetExceptionMessageDelegate))]
#endif
        static void GetExceptionMessage(IntPtr e, IntPtr data)
        {
            cppApi.SetString(FromNative<Exception>(e).Message, data);
        }

        [StructLayout(LayoutKind.Sequential)]
        public class ClassCsApi
        {
            public ClassCsApi(CreateDelegate c) { create = c; }
            public delegate IntPtr CreateDelegate(IntPtr cpp);
            readonly CreateDelegate create;
        }

        [StructLayout(LayoutKind.Sequential)]
        public class CsApi
        {
            public delegate IntPtr CopyRefDelegate(IntPtr r, GCHandleType t);
            readonly CopyRefDelegate copyRef = new CopyRefDelegate(CopyRef);

            public delegate void ReleaseRefDelegate(IntPtr r);
            readonly ReleaseRefDelegate releaseRef = new ReleaseRefDelegate(ReleaseRef);

            public delegate IntPtr CreateStringDelegate(IntPtr data, int size);
            readonly CreateStringDelegate createString = new CreateStringDelegate(CreateString);

            public delegate void SetStringDelegate(IntPtr str, IntPtr data);
            readonly SetStringDelegate setString = new SetStringDelegate(SetString);

            public delegate IntPtr GetFuncDelegate(IntPtr d);
            readonly GetFuncDelegate getFunc = new GetFuncDelegate(GetFunc);

            public delegate int GetArraySizeDelegate(IntPtr a);
            readonly GetArraySizeDelegate getArraySize = new GetArraySizeDelegate(GetArraySize);

            public delegate IntPtr GetObjectArrayElementDelegate(IntPtr arr, int index);
            readonly GetObjectArrayElementDelegate getObjectArrayElement = new GetObjectArrayElementDelegate(GetObjectArrayElement);

            public delegate void SetObjectArrayElementDelegate(IntPtr arr, int index, IntPtr value);
            readonly SetObjectArrayElementDelegate setObjectArrayElement = new SetObjectArrayElementDelegate(SetObjectArrayElement);

            public delegate ClassCsApi RegisterClassDelegate(string className, IntPtr classCppApi);
            readonly RegisterClassDelegate registerClass = new RegisterClassDelegate(RegisterClass);

            public delegate IntPtr GetCppDelegate(IntPtr obj);
            readonly GetCppDelegate getCpp = new GetCppDelegate(GetCpp);

            public delegate IntPtr AddrOfPinnedObjectDelegate(IntPtr obj);
            readonly AddrOfPinnedObjectDelegate addrOfPinnedObject = new AddrOfPinnedObjectDelegate(AddrOfPinnedObject);

            public delegate IntPtr CreateStructArrayDelegate(int size);

            readonly CreateStructArrayDelegate createBoolArray = new CreateStructArrayDelegate(CreateStructArrayBool);
            readonly CreateStructArrayDelegate createSbyteArray = new CreateStructArrayDelegate(CreateStructArraySbyte);
            readonly CreateStructArrayDelegate createShortArray = new CreateStructArrayDelegate(CreateStructArrayShort);
            readonly CreateStructArrayDelegate createIntArray = new CreateStructArrayDelegate(CreateStructArrayInt);
            readonly CreateStructArrayDelegate createLongArray = new CreateStructArrayDelegate(CreateStructArrayLong);
            readonly CreateStructArrayDelegate createByteArray = new CreateStructArrayDelegate(CreateStructArrayByte);
            readonly CreateStructArrayDelegate createUshortArray = new CreateStructArrayDelegate(CreateStructArrayUshort);
            readonly CreateStructArrayDelegate createUintArray = new CreateStructArrayDelegate(CreateStructArrayUint);
            readonly CreateStructArrayDelegate createUlongArray = new CreateStructArrayDelegate(CreateStructArrayUlong);
            readonly CreateStructArrayDelegate createFloatArray = new CreateStructArrayDelegate(CreateStructArrayFloat);
            readonly CreateStructArrayDelegate createDoubleArray = new CreateStructArrayDelegate(CreateStructArrayDouble);

            public delegate void SetExceptionDelegate(IntPtr exception, bool cpp);
            readonly SetExceptionDelegate setException = new SetExceptionDelegate(SetException);

            public delegate void GetExceptionMessageDelegate(IntPtr exception, IntPtr data);
            readonly GetExceptionMessageDelegate getExceptionMessage = new GetExceptionMessageDelegate(GetExceptionMessage);
        };

        static readonly CsApi csApi = new CsApi();

        [StructLayout(LayoutKind.Sequential)]
        public struct CppApi
        {
            public delegate void SetStringDelegate([MarshalAs(UnmanagedType.LPUTF8Str)]string str, IntPtr data);
            public readonly SetStringDelegate SetString;

            public delegate bool FinalizeDelegate(IntPtr obj);
            public readonly FinalizeDelegate Finalize;

            public delegate IntPtr GetExceptionMessageDelegate(IntPtr exception);
            public readonly GetExceptionMessageDelegate GetExceptionMessage;

            public delegate void DeleteExceptionDelegate(IntPtr exception);
            public readonly DeleteExceptionDelegate DeleteException;

            public delegate void SetExceptionDelegate(IntPtr exception, bool cpp);
            public readonly SetExceptionDelegate SetException;
        };

        static CppApi cppApi;

        static API() {}
        public delegate System.IntPtr ScapixInitDelegate(Scapix.Link.API.CsApi funcTable);
        public static void Init(ScapixInitDelegate init) { cppApi = Marshal.PtrToStructure<CppApi>(init(csApi)); }

        public static void SetString(string str, IntPtr data) { cppApi.SetString(str, data); }
        public static bool Finalize(IntPtr obj) { return cppApi.Finalize(obj); }
        public static string GetExceptionMessage(IntPtr exception) { return FromNative<string>(cppApi.GetExceptionMessage(exception)); }
        public static void DeleteException(IntPtr exception) { cppApi.DeleteException(exception); }
        public static void CppSetException(IntPtr exception, bool cpp) { cppApi.SetException(exception, cpp); }
    }
}
