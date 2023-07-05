/*
	scapix/link/java/detail/api/type.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_DETAIL_API_TYPE_H
#define SCAPIX_LINK_JAVA_DETAIL_API_TYPE_H

#include <scapix/link/java/ref.h>

namespace scapix::link::java::detail::api {

template <typename T>
struct type;

template <typename T>
struct type<java::ref<T>>
{
	static local_ref<T> get_field(jobject obj, jfieldID id) noexcept { return local_ref<T>(env()->GetObjectField(obj, id)); }
	static void set_field(jobject obj, jfieldID id, java::ref<T> value) noexcept { env()->SetObjectField(obj, id, value.handle()); }
	static local_ref<T> get_static_field(jclass cls, jfieldID id) noexcept { return local_ref<T>(env()->GetStaticObjectField(cls, id)); }
	static void set_static_field(jclass cls, jfieldID id, java::ref<T> value) noexcept { env()->SetStaticObjectField(cls, id, value.handle()); }

	template <typename ...Args> static local_ref<T> call_method(jobject obj, jmethodID id, Args... args) noexcept { return local_ref<T>(env()->CallObjectMethod(obj, id, args...)); }
	template <typename ...Args> static local_ref<T> call_nonvirtual_method(jobject obj, jclass cls, jmethodID id, Args... args) noexcept { return local_ref<T>(env()->CallNonvirtualObjectMethod(obj, cls, id, args...)); }
	template <typename ...Args> static local_ref<T> call_static_method(jclass cls, jmethodID id, Args... args) noexcept { return local_ref<T>(env()->CallStaticObjectMethod(cls, id, args...)); }

	template <typename ...Args> static local_ref<T> new_object(jclass cls, jmethodID id, Args... args) noexcept { return local_ref<T>(env()->NewObject(cls, id, args...)); }
	static local_ref<java::array<T>> new_array(jsize len, java::ref<T> init) noexcept { return local_ref<java::array<T>>(env()->NewObjectArray(len, detail::befriend<T, type>::class_object().handle(), init.handle())); }
	static local_ref<T> get_array_element(java::ref<java::array<T>> array, jsize index) noexcept { return local_ref<T>(env()->GetObjectArrayElement(array.handle(), index)); }
	static void set_array_element(java::ref<java::array<T>> array, jsize index, java::ref<T> value) noexcept { env()->SetObjectArrayElement(array.handle(), index, value.handle()); }
};

template <>
struct type<jboolean>
{
	static jboolean get_field(jobject obj, jfieldID id) noexcept { return env()->GetBooleanField(obj, id); }
	static void set_field(jobject obj, jfieldID id, jboolean value) noexcept { env()->SetBooleanField(obj, id, value); }
	static jboolean get_static_field(jclass cls, jfieldID id) noexcept { return env()->GetStaticBooleanField(cls, id); }
	static void set_static_field(jclass cls, jfieldID id, jboolean value) noexcept { env()->SetStaticBooleanField(cls, id, value); }

	template <typename ...Args> static jboolean call_method(jobject obj, jmethodID id, Args... args) noexcept { return env()->CallBooleanMethod(obj, id, args...); }
	template <typename ...Args> static jboolean call_nonvirtual_method(jobject obj, jclass cls, jmethodID id, Args... args) noexcept { return env()->CallNonvirtualBooleanMethod(obj, cls, id, args...); }
	template <typename ...Args> static jboolean call_static_method(jclass cls, jmethodID id, Args... args) noexcept { return env()->CallStaticBooleanMethod(cls, id, args...); }

	static jbooleanArray new_array(jsize len) noexcept { return env()->NewBooleanArray(len); }
	static jboolean* get_array_elements(jbooleanArray array, jboolean* isCopy) noexcept { return env()->GetBooleanArrayElements(array, isCopy); }
	static void release_array_elements(jbooleanArray array, jboolean* elems, jint mode) noexcept { env()->ReleaseBooleanArrayElements(array, elems, mode); }
	static void get_array_region(jbooleanArray array, jsize start, jsize len, jboolean* buf) noexcept { env()->GetBooleanArrayRegion(array, start, len, buf); }
	static void set_array_region(jbooleanArray array, jsize start, jsize len, const jboolean *buf) noexcept { env()->SetBooleanArrayRegion(array, start, len, buf); }
};

template <>
struct type<jbyte>
{
	static jbyte get_field(jobject obj, jfieldID id) noexcept { return env()->GetByteField(obj, id); }
	static void set_field(jobject obj, jfieldID id, jbyte value) noexcept { env()->SetByteField(obj, id, value); }
	static jbyte get_static_field(jclass cls, jfieldID id) noexcept { return env()->GetStaticByteField(cls, id); }
	static void set_static_field(jclass cls, jfieldID id, jbyte value) noexcept { env()->SetStaticByteField(cls, id, value); }

	template <typename ...Args> static jbyte call_method(jobject obj, jmethodID id, Args... args) noexcept { return env()->CallByteMethod(obj, id, args...); }
	template <typename ...Args> static jbyte call_nonvirtual_method(jobject obj, jclass cls, jmethodID id, Args... args) noexcept { return env()->CallNonvirtualByteMethod(obj, cls, id, args...); }
	template <typename ...Args> static jbyte call_static_method(jclass cls, jmethodID id, Args... args) noexcept { return env()->CallStaticByteMethod(cls, id, args...); }

	static jbyteArray new_array(jsize len) noexcept { return env()->NewByteArray(len); }
	static jbyte* get_array_elements(jbyteArray array, jboolean* isCopy) noexcept { return env()->GetByteArrayElements(array, isCopy); }
	static void release_array_elements(jbyteArray array, jbyte* elems, jint mode) noexcept { env()->ReleaseByteArrayElements(array, elems, mode); }
	static void get_array_region(jbyteArray array, jsize start, jsize len, jbyte* buf) noexcept { env()->GetByteArrayRegion(array, start, len, buf); }
	static void set_array_region(jbyteArray array, jsize start, jsize len, const jbyte *buf) noexcept { env()->SetByteArrayRegion(array, start, len, buf); }
};

template <>
struct type<jchar>
{
	static jchar get_field(jobject obj, jfieldID id) noexcept { return env()->GetCharField(obj, id); }
	static void set_field(jobject obj, jfieldID id, jchar value) noexcept { env()->SetCharField(obj, id, value); }
	static jchar get_static_field(jclass cls, jfieldID id) noexcept { return env()->GetStaticCharField(cls, id); }
	static void set_static_field(jclass cls, jfieldID id, jchar value) noexcept { env()->SetStaticCharField(cls, id, value); }

	template <typename ...Args> static jchar call_method(jobject obj, jmethodID id, Args... args) noexcept { return env()->CallCharMethod(obj, id, args...); }
	template <typename ...Args> static jchar call_nonvirtual_method(jobject obj, jclass cls, jmethodID id, Args... args) noexcept { return env()->CallNonvirtualCharMethod(obj, cls, id, args...); }
	template <typename ...Args> static jchar call_static_method(jclass cls, jmethodID id, Args... args) noexcept { return env()->CallStaticCharMethod(cls, id, args...); }

	static jcharArray new_array(jsize len) noexcept { return env()->NewCharArray(len); }
	static jchar* get_array_elements(jcharArray array, jboolean* isCopy) noexcept { return env()->GetCharArrayElements(array, isCopy); }
	static void release_array_elements(jcharArray array, jchar* elems, jint mode) noexcept { env()->ReleaseCharArrayElements(array, elems, mode); }
	static void get_array_region(jcharArray array, jsize start, jsize len, jchar* buf) noexcept { env()->GetCharArrayRegion(array, start, len, buf); }
	static void set_array_region(jcharArray array, jsize start, jsize len, const jchar *buf) noexcept { env()->SetCharArrayRegion(array, start, len, buf); }
};

template <>
struct type<jshort>
{
	static jshort get_field(jobject obj, jfieldID id) noexcept { return env()->GetShortField(obj, id); }
	static void set_field(jobject obj, jfieldID id, jshort value) noexcept { env()->SetShortField(obj, id, value); }
	static jshort get_static_field(jclass cls, jfieldID id) noexcept { return env()->GetStaticShortField(cls, id); }
	static void set_static_field(jclass cls, jfieldID id, jshort value) noexcept { env()->SetStaticShortField(cls, id, value); }

	template <typename ...Args> static jshort call_method(jobject obj, jmethodID id, Args... args) noexcept { return env()->CallShortMethod(obj, id, args...); }
	template <typename ...Args> static jshort call_nonvirtual_method(jobject obj, jclass cls, jmethodID id, Args... args) noexcept { return env()->CallNonvirtualShortMethod(obj, cls, id, args...); }
	template <typename ...Args> static jshort call_static_method(jclass cls, jmethodID id, Args... args) noexcept { return env()->CallStaticShortMethod(cls, id, args...); }

	static jshortArray new_array(jsize len) noexcept { return env()->NewShortArray(len); }
	static jshort* get_array_elements(jshortArray array, jboolean* isCopy) noexcept { return env()->GetShortArrayElements(array, isCopy); }
	static void release_array_elements(jshortArray array, jshort* elems, jint mode) noexcept { env()->ReleaseShortArrayElements(array, elems, mode); }
	static void get_array_region(jshortArray array, jsize start, jsize len, jshort* buf) noexcept { env()->GetShortArrayRegion(array, start, len, buf); }
	static void set_array_region(jshortArray array, jsize start, jsize len, const jshort *buf) noexcept { env()->SetShortArrayRegion(array, start, len, buf); }
};

template <>
struct type<jint>
{
	static jint get_field(jobject obj, jfieldID id) noexcept { return env()->GetIntField(obj, id); }
	static void set_field(jobject obj, jfieldID id, jint value) noexcept { env()->SetIntField(obj, id, value); }
	static jint get_static_field(jclass cls, jfieldID id) noexcept { return env()->GetStaticIntField(cls, id); }
	static void set_static_field(jclass cls, jfieldID id, jint value) noexcept { env()->SetStaticIntField(cls, id, value); }

	template <typename ...Args> static jint call_method(jobject obj, jmethodID id, Args... args) noexcept { return env()->CallIntMethod(obj, id, args...); }
	template <typename ...Args> static jint call_nonvirtual_method(jobject obj, jclass cls, jmethodID id, Args... args) noexcept { return env()->CallNonvirtualIntMethod(obj, cls, id, args...); }
	template <typename ...Args> static jint call_static_method(jclass cls, jmethodID id, Args... args) noexcept { return env()->CallStaticIntMethod(cls, id, args...); }

	static jintArray new_array(jsize len) noexcept { return env()->NewIntArray(len); }
	static jint* get_array_elements(jintArray array, jboolean* isCopy) noexcept { return env()->GetIntArrayElements(array, isCopy); }
	static void release_array_elements(jintArray array, jint* elems, jint mode) noexcept { env()->ReleaseIntArrayElements(array, elems, mode); }
	static void get_array_region(jintArray array, jsize start, jsize len, jint* buf) noexcept { env()->GetIntArrayRegion(array, start, len, buf); }
	static void set_array_region(jintArray array, jsize start, jsize len, const jint *buf) noexcept { env()->SetIntArrayRegion(array, start, len, buf); }
};

template <>
struct type<jlong>
{
	static jlong get_field(jobject obj, jfieldID id) noexcept { return env()->GetLongField(obj, id); }
	static void set_field(jobject obj, jfieldID id, jlong value) noexcept { env()->SetLongField(obj, id, value); }
	static jlong get_static_field(jclass cls, jfieldID id) noexcept { return env()->GetStaticLongField(cls, id); }
	static void set_static_field(jclass cls, jfieldID id, jlong value) noexcept { env()->SetStaticLongField(cls, id, value); }

	template <typename ...Args> static jlong call_method(jobject obj, jmethodID id, Args... args) noexcept { return env()->CallLongMethod(obj, id, args...); }
	template <typename ...Args> static jlong call_nonvirtual_method(jobject obj, jclass cls, jmethodID id, Args... args) noexcept { return env()->CallNonvirtualLongMethod(obj, cls, id, args...); }
	template <typename ...Args> static jlong call_static_method(jclass cls, jmethodID id, Args... args) noexcept { return env()->CallStaticLongMethod(cls, id, args...); }

	static jlongArray new_array(jsize len) noexcept { return env()->NewLongArray(len); }
	static jlong* get_array_elements(jlongArray array, jboolean* isCopy) noexcept { return env()->GetLongArrayElements(array, isCopy); }
	static void release_array_elements(jlongArray array, jlong* elems, jint mode) noexcept { env()->ReleaseLongArrayElements(array, elems, mode); }
	static void get_array_region(jlongArray array, jsize start, jsize len, jlong* buf) noexcept { env()->GetLongArrayRegion(array, start, len, buf); }
	static void set_array_region(jlongArray array, jsize start, jsize len, const jlong *buf) noexcept { env()->SetLongArrayRegion(array, start, len, buf); }
};

template <>
struct type<jfloat>
{
	static jfloat get_field(jobject obj, jfieldID id) noexcept { return env()->GetFloatField(obj, id); }
	static void set_field(jobject obj, jfieldID id, jfloat value) noexcept { env()->SetFloatField(obj, id, value); }
	static jfloat get_static_field(jclass cls, jfieldID id) noexcept { return env()->GetStaticFloatField(cls, id); }
	static void set_static_field(jclass cls, jfieldID id, jfloat value) noexcept { env()->SetStaticFloatField(cls, id, value); }

	template <typename ...Args> static jfloat call_method(jobject obj, jmethodID id, Args... args) noexcept { return env()->CallFloatMethod(obj, id, args...); }
	template <typename ...Args> static jfloat call_nonvirtual_method(jobject obj, jclass cls, jmethodID id, Args... args) noexcept { return env()->CallNonvirtualFloatMethod(obj, cls, id, args...); }
	template <typename ...Args> static jfloat call_static_method(jclass cls, jmethodID id, Args... args) noexcept { return env()->CallStaticFloatMethod(cls, id, args...); }

	static jfloatArray new_array(jsize len) noexcept { return env()->NewFloatArray(len); }
	static jfloat* get_array_elements(jfloatArray array, jboolean* isCopy) noexcept { return env()->GetFloatArrayElements(array, isCopy); }
	static void release_array_elements(jfloatArray array, jfloat* elems, jint mode) noexcept { env()->ReleaseFloatArrayElements(array, elems, mode); }
	static void get_array_region(jfloatArray array, jsize start, jsize len, jfloat* buf) noexcept { env()->GetFloatArrayRegion(array, start, len, buf); }
	static void set_array_region(jfloatArray array, jsize start, jsize len, const jfloat *buf) noexcept { env()->SetFloatArrayRegion(array, start, len, buf); }
};

template <>
struct type<jdouble>
{
	static jdouble get_field(jobject obj, jfieldID id) noexcept { return env()->GetDoubleField(obj, id); }
	static void set_field(jobject obj, jfieldID id, jdouble value) noexcept { env()->SetDoubleField(obj, id, value); }
	static jdouble get_static_field(jclass cls, jfieldID id) noexcept { return env()->GetStaticDoubleField(cls, id); }
	static void set_static_field(jclass cls, jfieldID id, jdouble value) noexcept { env()->SetStaticDoubleField(cls, id, value); }

	template <typename ...Args> static jdouble call_method(jobject obj, jmethodID id, Args... args) noexcept { return env()->CallDoubleMethod(obj, id, args...); }
	template <typename ...Args> static jdouble call_nonvirtual_method(jobject obj, jclass cls, jmethodID id, Args... args) noexcept { return env()->CallNonvirtualDoubleMethod(obj, cls, id, args...); }
	template <typename ...Args> static jdouble call_static_method(jclass cls, jmethodID id, Args... args) noexcept { return env()->CallStaticDoubleMethod(cls, id, args...); }

	static jdoubleArray new_array(jsize len) noexcept { return env()->NewDoubleArray(len); }
	static jdouble* get_array_elements(jdoubleArray array, jboolean* isCopy) noexcept { return env()->GetDoubleArrayElements(array, isCopy); }
	static void release_array_elements(jdoubleArray array, jdouble* elems, jint mode) noexcept { env()->ReleaseDoubleArrayElements(array, elems, mode); }
	static void get_array_region(jdoubleArray array, jsize start, jsize len, jdouble* buf) noexcept { env()->GetDoubleArrayRegion(array, start, len, buf); }
	static void set_array_region(jdoubleArray array, jsize start, jsize len, const jdouble *buf) noexcept { env()->SetDoubleArrayRegion(array, start, len, buf); }
};

template <>
struct type<void>
{
	template <typename ...Args> static void call_method(jobject obj, jmethodID id, Args... args) noexcept { env()->CallVoidMethod(obj, id, args...); }
	template <typename ...Args> static void call_nonvirtual_method(jobject obj, jclass cls, jmethodID id, Args... args) noexcept { env()->CallNonvirtualVoidMethod(obj, cls, id, args...); }
	template <typename ...Args> static void call_static_method(jclass cls, jmethodID id, Args... args) noexcept { env()->CallStaticVoidMethod(cls, id, args...); }
};

} // namespace scapix::link::java::detail::api

#endif // SCAPIX_LINK_JAVA_DETAIL_API_TYPE_H
