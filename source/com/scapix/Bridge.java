/*
	com/scapix/Bridge.java

	Copyright (c) 2018 Boris Rasin (boris@scapix.com)
*/

package com.scapix;
import com.scapix.NativeException; // force compilation

public class Bridge
{
	protected class Tag {}
	protected Bridge() {}
	protected void finalize() { _finalize(); ptr = 0; }

    private native void _finalize();
	private long ptr;

//  private java.lang.ref.SoftReference<Bridge> softSelf = new java.lang.ref.SoftReference<Bridge>(this);
}
