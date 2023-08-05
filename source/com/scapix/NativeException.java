/*
	com/scapix/NativeException.java

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

package com.scapix;

public final class NativeException extends java.lang.RuntimeException
{
	private long ptr;

	private NativeException(long p) { ptr = p; }

	@SuppressWarnings({"deprecation","removal"})
	@Override
	protected native void finalize();

	@Override
	public native String getMessage();
}
