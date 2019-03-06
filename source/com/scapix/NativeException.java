/*
	com/scapix/NativeException.java

	Copyright (c) 2018 Boris Rasin (boris@scapix.com)
*/

package com.scapix;

import java.lang.RuntimeException;

public class NativeException extends RuntimeException
{
	private NativeException(long p)
	{
		ptr = p;
	}

	private long ptr;
}
