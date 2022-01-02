/*
	com/scapix/Bridge.java

	Copyright (c) 2018 Boris Rasin (boris@scapix.com)
*/

package com.scapix;
import com.scapix.NativeException; // force compilation

public class Bridge
{
	private long ptr;

	@SuppressWarnings("deprecation")
	protected native void finalize();

	protected static final class Nop {}
	protected static final Nop nop = null;
	protected Bridge(Nop nop) {}
}
