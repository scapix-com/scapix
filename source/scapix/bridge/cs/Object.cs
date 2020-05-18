/*
	scapix/bridge/cs/Object.cs

	Copyright (c) 2020 Boris Rasin (boris@scapix.com)
*/

using System;
using System.Runtime.InteropServices;

namespace Scapix.Bridge
{
    public abstract class Object
    {
        internal protected /*protected*/ IntPtr cpp;

        protected static void ScapixInit()
        {
            Link.API.Init();
        }

        ~Object()
        {
            if (!Link.API.cppApi.Finalize(cpp))
                GC.ReRegisterForFinalize(this);
        }

        protected struct Nop {}
        protected static readonly Nop nop;
        protected Object(Nop nop) {}

        protected IntPtr ScapixWeak() { return Link.API.ToNative(this, GCHandleType.WeakTrackResurrection); }
        protected void ScapixInit(IntPtr cpp) { this.cpp = cpp; }
        protected void ScapixInitCheck(IntPtr cpp) { ScapixCheck(); this.cpp = cpp; }

        protected static T ScapixCpp<T>(T v) where T : struct { return v; }
        protected static IntPtr ScapixCpp(object v) { return Link.API.ToNative(v); }
        protected static IntPtr ScapixCpp<T>(T[] v) where T : struct { return Link.API.ToNative(v, GCHandleType.Pinned); }

        protected static T ScapixCs<T>(T v) where T : struct { return v; }
        protected static T ScapixCs<T>(IntPtr v) where T : class { return Link.API.FromNative<T>(v); }

        protected static void ScapixCheck() { Link.API.CheckException(); }
        protected static T ScapixCheck<T>(T v) where T : struct { ScapixCheck(); return v; }
        protected static T ScapixCheck<T>(IntPtr v) where T : class { ScapixCheck(); return Link.API.FromNative<T>(v); }

        protected static T ScapixCallback<T>(Func<T> func)
        {
            try
            {
                return func();
            }
            catch (Link.CppException e)
            {
                Link.API.cppApi.SetException(e.Release(), true);
            }
            catch (Exception e)
            {
                Link.API.cppApi.SetException(ScapixCpp(e), false);
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
                Link.API.cppApi.SetException(e.Release(), true);
            }
            catch (Exception e)
            {
                Link.API.cppApi.SetException(ScapixCpp(e), false);
            }
        }
    }
}
