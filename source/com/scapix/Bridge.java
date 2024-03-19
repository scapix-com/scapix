/*
	com/scapix/Bridge.java

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

package com.scapix;

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
