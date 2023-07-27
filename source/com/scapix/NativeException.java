/*
	com/scapix/NativeException.java

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

package com.scapix;

public final class NativeException extends java.lang.RuntimeException
{
	private long ptr;

	private NativeException(long p)
	{
		ptr = p;
	}

	private long release()
	{
		long p = ptr;
		ptr = 0;
		return p;
	}

	private static native void finalize(long p);

	@SuppressWarnings({"deprecation","removal"})
	@Override
	protected void finalize()
	{
		if (ptr != 0)
			finalize(ptr);
	}
}
