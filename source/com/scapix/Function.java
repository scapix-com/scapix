/*
	com/scapix/Function.java

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

package com.scapix;

public class Function
{
	private long ptr;

	@SuppressWarnings({"deprecation","removal"})
	@Override
	protected native void finalize();

	protected Function(long p) { ptr = p; }
}
