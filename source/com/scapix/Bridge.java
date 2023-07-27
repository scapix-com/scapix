/*
	com/scapix/Bridge.java

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

package com.scapix;
import com.scapix.NativeException; // force compilation

public class Bridge
{
	private long ptr;

	@SuppressWarnings({"deprecation","removal"})
	@Override
	protected native void finalize();

	protected static final class Nop {}
	protected static final Nop nop = null;
	protected Bridge(Nop nop) {}
}
