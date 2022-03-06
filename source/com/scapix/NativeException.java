/*
	com/scapix/NativeException.java

	Copyright (c) 2018 Boris Rasin (boris@scapix.com)
*/

package com.scapix;

import java.lang.RuntimeException;

public class NativeException extends RuntimeException
{
	private long ptr;
	private NativeException(long p) { ptr = p; }

//	@SuppressWarnings("deprecation")
//	protected native void finalize();
}
