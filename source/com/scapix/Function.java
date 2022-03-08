/*
	com/scapix/Function.java

	Copyright (c) 2022 Boris Rasin (boris@scapix.com)
*/

package com.scapix;

public class Function
{
	private long ptr;

	@SuppressWarnings("deprecation")
	protected native void finalize();

	protected Function(long p) { ptr = p; }
}
