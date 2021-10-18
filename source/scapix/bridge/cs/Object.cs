/*
	scapix/bridge/cs/Object.cs

	Copyright (c) 2020 Boris Rasin (boris@scapix.com)
*/

#if ENABLE_IL2CPP
#define SCAPIX_NO_RESURRECTION
#endif

using System;
using System.Runtime.InteropServices;

namespace Scapix.Bridge
{
    public abstract class Object
    {
        internal protected /*protected*/ IntPtr cpp;

#if SCAPIX_NO_RESURRECTION
        ~Object()
        {
            Link.API.Finalize(cpp);
        }

        const GCHandleType weakType = GCHandleType.Weak;
#else
        ~Object()
        {
            if (!Link.API.Finalize(cpp))
                GC.ReRegisterForFinalize(this);
        }

        const GCHandleType weakType = GCHandleType.WeakTrackResurrection;
#endif

        protected struct Nop {}
        protected static readonly Nop nop;
        protected Object(Nop nop) {}

        protected IntPtr ScapixWeak() { return Link.API.ToNative(this, weakType); }
        protected void ScapixInit(IntPtr cpp) { this.cpp = cpp; }
        protected void ScapixInitCheck(IntPtr cpp) { Link.API.CheckException(); this.cpp = cpp; }

        // duplicated in API.cs

        protected static T ScapixCpp<T>(T v) where T : struct { return v; }
        protected static IntPtr ScapixCpp(object v) { return Link.API.ToNative(v); }
        protected static IntPtr ScapixCpp<T>(T[] v) where T : struct { return Link.API.ToNative(v, GCHandleType.Pinned); }
        protected static byte ScapixCpp(bool v) { return v ? (byte)1 : (byte)0; }

        protected static T ScapixCs<T>(T v) where T : struct { return v; }
        protected static T ScapixCs<T>(IntPtr v) where T : class { return Link.API.FromNative<T>(v); }
        protected static bool ScapixCs<T>(byte v) { return v != 0; }

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
    }
}
