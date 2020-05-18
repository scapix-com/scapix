using System;
using System.Runtime.InteropServices;
using System.Reflection;

namespace Scapix.Link
{
    public class CppException : System.Exception, IDisposable
    {
        public CppException(IntPtr cpp) { this.cpp = cpp; }
        public override String Message { get { return API.FromNative<string>(API.cppApi.GetExceptionMessage(cpp)); } }

        ~CppException()
        {
            Dispose();
        }

        public void Dispose()
        {
            if (cpp != IntPtr.Zero)
            {
                API.cppApi.DeleteException(cpp);
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

    static class API
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

        static IntPtr CopyRef(IntPtr p, GCHandleType t)
        {
            var obj = GCHandle.FromIntPtr(p).Target;

            if (obj == null)
                return IntPtr.Zero;

            return GCHandle.ToIntPtr(GCHandle.Alloc(obj, t));
        }

        static void ReleaseRef(IntPtr r)
        {
            GCHandle.FromIntPtr(r).Free();
        }

        static IntPtr CreateString(IntPtr data, int size)
        {
            // Marshal.PtrToStringUTF8() not in .NET Framework 4.7.2
            // return ToNative(Marshal.PtrToStringUTF8(data, size));

            byte[] buff = new byte[size];
            Marshal.Copy(data, buff, 0, size);
            return ToNative(System.Text.UTF8Encoding.UTF8.GetString(buff));
        }

        static void SetString(IntPtr str, IntPtr data)
        {
            cppApi.SetString((string)GCHandle.FromIntPtr(str).Target, data);
        }

        static IntPtr GetFunc(IntPtr d)
        {
            return Marshal.GetFunctionPointerForDelegate((Delegate)GCHandle.FromIntPtr(d).Target);
        }

        static int GetArraySize(IntPtr arr)
        {
            return ((Array)GCHandle.FromIntPtr(arr).Target).Length;
        }

        static IntPtr GetObjectArrayElement(IntPtr arr, int index)
        {
            return ToNative(((object[])GCHandle.FromIntPtr(arr).Target)[index]);
        }

        static void SetObjectArrayElement(IntPtr arr, int index, IntPtr value)
        {
            ((object[])GCHandle.FromIntPtr(arr).Target)[index] = GCHandle.FromIntPtr(value).Target;
        }

        static ClassCsApi RegisterClass(string className, IntPtr classCppApi)
        {
            MethodInfo method = Type.GetType(className).GetMethod("ScapixRegister", BindingFlags.NonPublic | BindingFlags.Static);
            return (ClassCsApi)method.Invoke(null, new object[] { classCppApi });
        }

        static IntPtr GetCpp(IntPtr obj)
        {
            return ((Bridge.Object)GCHandle.FromIntPtr(obj).Target).cpp;
        }

        static IntPtr AddrOfPinnedObject(IntPtr obj)
        {
            return GCHandle.FromIntPtr(obj).AddrOfPinnedObject();
        }

        static IntPtr CreateStructArray<T>(int size) where T : struct
        {
            return ToNative(new T[size], GCHandleType.Pinned);
        }

        static void SetException(IntPtr e, bool cpp)
        {
            if (cpp)
                exception = new CppException(e);
            else
                exception = FromNative<Exception>(e);
        }

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
        class CsApi
        {
            delegate IntPtr CopyRefDelegate(IntPtr r, GCHandleType t);
            readonly CopyRefDelegate copyRef = new CopyRefDelegate(CopyRef);

            delegate void ReleaseRefDelegate(IntPtr r);
            readonly ReleaseRefDelegate releaseRef = new ReleaseRefDelegate(ReleaseRef);

            delegate IntPtr CreateStringDelegate(IntPtr data, int size);
            readonly CreateStringDelegate createString = new CreateStringDelegate(CreateString);

            delegate void SetStringDelegate(IntPtr str, IntPtr data);
            readonly SetStringDelegate setString = new SetStringDelegate(SetString);

            delegate IntPtr GetFuncDelegate(IntPtr d);
            readonly GetFuncDelegate getFunc = new GetFuncDelegate(GetFunc);

            delegate int GetArraySizeDelegate(IntPtr a);
            readonly GetArraySizeDelegate getArraySize = new GetArraySizeDelegate(GetArraySize);

            delegate IntPtr GetObjectArrayElementDelegate(IntPtr arr, int index);
            readonly GetObjectArrayElementDelegate getObjectArrayElement = new GetObjectArrayElementDelegate(GetObjectArrayElement);

            delegate void SetObjectArrayElementDelegate(IntPtr arr, int index, IntPtr value);
            readonly SetObjectArrayElementDelegate setObjectArrayElement = new SetObjectArrayElementDelegate(SetObjectArrayElement);

            delegate ClassCsApi RegisterClassDelegate(string className, IntPtr classCppApi);
            readonly RegisterClassDelegate registerClass = new RegisterClassDelegate(RegisterClass);

            delegate IntPtr GetCppDelegate(IntPtr obj);
            readonly GetCppDelegate getCpp = new GetCppDelegate(GetCpp);

            delegate IntPtr AddrOfPinnedObjectDelegate(IntPtr obj);
            readonly AddrOfPinnedObjectDelegate addrOfPinnedObject = new AddrOfPinnedObjectDelegate(AddrOfPinnedObject);

            delegate IntPtr CreateBoolArrayDelegate(int size);
            readonly CreateBoolArrayDelegate createBoolArray = new CreateBoolArrayDelegate(CreateStructArray<bool>);

            delegate IntPtr CreateSbyteArrayDelegate(int size);
            readonly CreateSbyteArrayDelegate createSbyteArray = new CreateSbyteArrayDelegate(CreateStructArray<sbyte>);

            delegate IntPtr CreateShortArrayDelegate(int size);
            readonly CreateShortArrayDelegate createShortArray = new CreateShortArrayDelegate(CreateStructArray<short>);

            delegate IntPtr CreateIntArrayDelegate(int size);
            readonly CreateIntArrayDelegate createIntArray = new CreateIntArrayDelegate(CreateStructArray<int>);

            delegate IntPtr CreateLongArrayDelegate(int size);
            readonly CreateLongArrayDelegate createLongArray = new CreateLongArrayDelegate(CreateStructArray<long>);

            delegate IntPtr CreateFloatArrayDelegate(int size);
            readonly CreateFloatArrayDelegate createFloatArray = new CreateFloatArrayDelegate(CreateStructArray<float>);

            delegate IntPtr CreateDoubleArrayDelegate(int size);
            readonly CreateDoubleArrayDelegate createDoubleArray = new CreateDoubleArrayDelegate(CreateStructArray<double>);

            delegate void SetExceptionDelegate(IntPtr exception, bool cpp);
            readonly SetExceptionDelegate setException = new SetExceptionDelegate(SetException);

            delegate void GetExceptionMessageDelegate(IntPtr exception, IntPtr data);
            readonly GetExceptionMessageDelegate getExceptionMessage = new GetExceptionMessageDelegate(GetExceptionMessage);
        };

        readonly static CsApi csApi = new CsApi();

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

        public readonly static CppApi cppApi = Marshal.PtrToStructure<CppApi>(ScapixInit(csApi));

        [DllImport(Scapix.Native.Dll)]
        static extern IntPtr ScapixInit(CsApi funcTable);

        static API() {}
        public static void Init() {}
    }
}
