/*
	com/scapix/NativeException.java

	Copyright (c) 2018-2022 Boris Rasin (boris@scapix.com)
*/

package com.scapix;

public class NativeException extends java.lang.RuntimeException
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
	protected void finalize()
	{
		if (ptr != 0)
			finalize(ptr);
	}
}
