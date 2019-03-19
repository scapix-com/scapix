// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Number.h>
#include <scapix/java_api/java/lang/Comparable.h>
#include <scapix/java_api/java/io/Serializable.h>

#ifndef SCAPIX_JAVA_MATH_BIGINTEGER_H
#define SCAPIX_JAVA_MATH_BIGINTEGER_H

namespace scapix::java_api {

namespace java::lang { class Object; }
namespace java::lang { class String; }
namespace java::util { class Random; }

namespace java::math {

class BigInteger : public object_base<SCAPIX_META_STRING("java/math/BigInteger"),
	java::lang::Number,
	java::lang::Comparable,
	java::io::Serializable>
{
public:

	static ref<java::math::BigInteger> ONE_();
	static ref<java::math::BigInteger> TEN_();
	static ref<java::math::BigInteger> ZERO_();

	static ref<BigInteger> new_object(jint numBits, ref<java::util::Random> random);
	static ref<BigInteger> new_object(jint bitLength, jint certainty, ref<java::util::Random> random);
	static ref<BigInteger> new_object(ref<java::lang::String> value);
	static ref<BigInteger> new_object(ref<java::lang::String> value, jint radix);
	static ref<BigInteger> new_object(jint signum, ref<link::java::array<jbyte>> magnitude);
	static ref<BigInteger> new_object(ref<link::java::array<jbyte>> value);
	static ref<java::math::BigInteger> valueOf(jlong value);
	ref<link::java::array<jbyte>> toByteArray();
	ref<java::math::BigInteger> abs();
	ref<java::math::BigInteger> negate();
	ref<java::math::BigInteger> add(ref<java::math::BigInteger> value);
	ref<java::math::BigInteger> subtract(ref<java::math::BigInteger> value);
	jint signum();
	ref<java::math::BigInteger> shiftRight(jint n);
	ref<java::math::BigInteger> shiftLeft(jint n);
	jint bitLength();
	jboolean testBit(jint n);
	ref<java::math::BigInteger> setBit(jint n);
	ref<java::math::BigInteger> clearBit(jint n);
	ref<java::math::BigInteger> flipBit(jint n);
	jint getLowestSetBit();
	jint bitCount();
	ref<java::math::BigInteger> not_();
	ref<java::math::BigInteger> and_(ref<java::math::BigInteger> value);
	ref<java::math::BigInteger> or_(ref<java::math::BigInteger> value);
	ref<java::math::BigInteger> xor_(ref<java::math::BigInteger> value);
	ref<java::math::BigInteger> andNot(ref<java::math::BigInteger> value);
	jint intValue();
	jlong longValue();
	jfloat floatValue();
	jdouble doubleValue();
	jint compareTo(ref<java::math::BigInteger> value);
	ref<java::math::BigInteger> min(ref<java::math::BigInteger> value);
	ref<java::math::BigInteger> max(ref<java::math::BigInteger> value);
	jint hashCode();
	jboolean equals(ref<java::lang::Object> x);
	ref<java::lang::String> toString();
	ref<java::lang::String> toString(jint radix);
	ref<java::math::BigInteger> gcd(ref<java::math::BigInteger> value);
	ref<java::math::BigInteger> multiply(ref<java::math::BigInteger> value);
	ref<java::math::BigInteger> pow(jint exp);
	ref<link::java::array<java::math::BigInteger>> divideAndRemainder(ref<java::math::BigInteger> divisor);
	ref<java::math::BigInteger> divide(ref<java::math::BigInteger> divisor);
	ref<java::math::BigInteger> remainder(ref<java::math::BigInteger> divisor);
	ref<java::math::BigInteger> modInverse(ref<java::math::BigInteger> m);
	ref<java::math::BigInteger> modPow(ref<java::math::BigInteger> exponent, ref<java::math::BigInteger> modulus);
	ref<java::math::BigInteger> mod(ref<java::math::BigInteger> m);
	jboolean isProbablePrime(jint certainty);
	ref<java::math::BigInteger> nextProbablePrime();
	static ref<java::math::BigInteger> probablePrime(jint bitLength, ref<java::util::Random> random);

protected:

	BigInteger(handle_type h) : base_(h) {}

};

} // namespace java::math
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/java/util/Random.h>

namespace scapix::java_api {
namespace java::math {

inline ref<java::math::BigInteger> BigInteger::ONE_() { return get_static_field<SCAPIX_META_STRING("ONE"), ref<java::math::BigInteger>>(); }
inline ref<java::math::BigInteger> BigInteger::TEN_() { return get_static_field<SCAPIX_META_STRING("TEN"), ref<java::math::BigInteger>>(); }
inline ref<java::math::BigInteger> BigInteger::ZERO_() { return get_static_field<SCAPIX_META_STRING("ZERO"), ref<java::math::BigInteger>>(); }
inline ref<BigInteger> BigInteger::new_object(jint numBits, ref<java::util::Random> random) { return base_::new_object(numBits, random); }
inline ref<BigInteger> BigInteger::new_object(jint bitLength, jint certainty, ref<java::util::Random> random) { return base_::new_object(bitLength, certainty, random); }
inline ref<BigInteger> BigInteger::new_object(ref<java::lang::String> value) { return base_::new_object(value); }
inline ref<BigInteger> BigInteger::new_object(ref<java::lang::String> value, jint radix) { return base_::new_object(value, radix); }
inline ref<BigInteger> BigInteger::new_object(jint signum, ref<link::java::array<jbyte>> magnitude) { return base_::new_object(signum, magnitude); }
inline ref<BigInteger> BigInteger::new_object(ref<link::java::array<jbyte>> value) { return base_::new_object(value); }
inline ref<java::math::BigInteger> BigInteger::valueOf(jlong value) { return call_static_method<SCAPIX_META_STRING("valueOf"), ref<java::math::BigInteger>>(value); }
inline ref<link::java::array<jbyte>> BigInteger::toByteArray() { return call_method<SCAPIX_META_STRING("toByteArray"), ref<link::java::array<jbyte>>>(); }
inline ref<java::math::BigInteger> BigInteger::abs() { return call_method<SCAPIX_META_STRING("abs"), ref<java::math::BigInteger>>(); }
inline ref<java::math::BigInteger> BigInteger::negate() { return call_method<SCAPIX_META_STRING("negate"), ref<java::math::BigInteger>>(); }
inline ref<java::math::BigInteger> BigInteger::add(ref<java::math::BigInteger> value) { return call_method<SCAPIX_META_STRING("add"), ref<java::math::BigInteger>>(value); }
inline ref<java::math::BigInteger> BigInteger::subtract(ref<java::math::BigInteger> value) { return call_method<SCAPIX_META_STRING("subtract"), ref<java::math::BigInteger>>(value); }
inline jint BigInteger::signum() { return call_method<SCAPIX_META_STRING("signum"), jint>(); }
inline ref<java::math::BigInteger> BigInteger::shiftRight(jint n) { return call_method<SCAPIX_META_STRING("shiftRight"), ref<java::math::BigInteger>>(n); }
inline ref<java::math::BigInteger> BigInteger::shiftLeft(jint n) { return call_method<SCAPIX_META_STRING("shiftLeft"), ref<java::math::BigInteger>>(n); }
inline jint BigInteger::bitLength() { return call_method<SCAPIX_META_STRING("bitLength"), jint>(); }
inline jboolean BigInteger::testBit(jint n) { return call_method<SCAPIX_META_STRING("testBit"), jboolean>(n); }
inline ref<java::math::BigInteger> BigInteger::setBit(jint n) { return call_method<SCAPIX_META_STRING("setBit"), ref<java::math::BigInteger>>(n); }
inline ref<java::math::BigInteger> BigInteger::clearBit(jint n) { return call_method<SCAPIX_META_STRING("clearBit"), ref<java::math::BigInteger>>(n); }
inline ref<java::math::BigInteger> BigInteger::flipBit(jint n) { return call_method<SCAPIX_META_STRING("flipBit"), ref<java::math::BigInteger>>(n); }
inline jint BigInteger::getLowestSetBit() { return call_method<SCAPIX_META_STRING("getLowestSetBit"), jint>(); }
inline jint BigInteger::bitCount() { return call_method<SCAPIX_META_STRING("bitCount"), jint>(); }
inline ref<java::math::BigInteger> BigInteger::not_() { return call_method<SCAPIX_META_STRING("not"), ref<java::math::BigInteger>>(); }
inline ref<java::math::BigInteger> BigInteger::and_(ref<java::math::BigInteger> value) { return call_method<SCAPIX_META_STRING("and"), ref<java::math::BigInteger>>(value); }
inline ref<java::math::BigInteger> BigInteger::or_(ref<java::math::BigInteger> value) { return call_method<SCAPIX_META_STRING("or"), ref<java::math::BigInteger>>(value); }
inline ref<java::math::BigInteger> BigInteger::xor_(ref<java::math::BigInteger> value) { return call_method<SCAPIX_META_STRING("xor"), ref<java::math::BigInteger>>(value); }
inline ref<java::math::BigInteger> BigInteger::andNot(ref<java::math::BigInteger> value) { return call_method<SCAPIX_META_STRING("andNot"), ref<java::math::BigInteger>>(value); }
inline jint BigInteger::intValue() { return call_method<SCAPIX_META_STRING("intValue"), jint>(); }
inline jlong BigInteger::longValue() { return call_method<SCAPIX_META_STRING("longValue"), jlong>(); }
inline jfloat BigInteger::floatValue() { return call_method<SCAPIX_META_STRING("floatValue"), jfloat>(); }
inline jdouble BigInteger::doubleValue() { return call_method<SCAPIX_META_STRING("doubleValue"), jdouble>(); }
inline jint BigInteger::compareTo(ref<java::math::BigInteger> value) { return call_method<SCAPIX_META_STRING("compareTo"), jint>(value); }
inline ref<java::math::BigInteger> BigInteger::min(ref<java::math::BigInteger> value) { return call_method<SCAPIX_META_STRING("min"), ref<java::math::BigInteger>>(value); }
inline ref<java::math::BigInteger> BigInteger::max(ref<java::math::BigInteger> value) { return call_method<SCAPIX_META_STRING("max"), ref<java::math::BigInteger>>(value); }
inline jint BigInteger::hashCode() { return call_method<SCAPIX_META_STRING("hashCode"), jint>(); }
inline jboolean BigInteger::equals(ref<java::lang::Object> x) { return call_method<SCAPIX_META_STRING("equals"), jboolean>(x); }
inline ref<java::lang::String> BigInteger::toString() { return call_method<SCAPIX_META_STRING("toString"), ref<java::lang::String>>(); }
inline ref<java::lang::String> BigInteger::toString(jint radix) { return call_method<SCAPIX_META_STRING("toString"), ref<java::lang::String>>(radix); }
inline ref<java::math::BigInteger> BigInteger::gcd(ref<java::math::BigInteger> value) { return call_method<SCAPIX_META_STRING("gcd"), ref<java::math::BigInteger>>(value); }
inline ref<java::math::BigInteger> BigInteger::multiply(ref<java::math::BigInteger> value) { return call_method<SCAPIX_META_STRING("multiply"), ref<java::math::BigInteger>>(value); }
inline ref<java::math::BigInteger> BigInteger::pow(jint exp) { return call_method<SCAPIX_META_STRING("pow"), ref<java::math::BigInteger>>(exp); }
inline ref<link::java::array<java::math::BigInteger>> BigInteger::divideAndRemainder(ref<java::math::BigInteger> divisor) { return call_method<SCAPIX_META_STRING("divideAndRemainder"), ref<link::java::array<java::math::BigInteger>>>(divisor); }
inline ref<java::math::BigInteger> BigInteger::divide(ref<java::math::BigInteger> divisor) { return call_method<SCAPIX_META_STRING("divide"), ref<java::math::BigInteger>>(divisor); }
inline ref<java::math::BigInteger> BigInteger::remainder(ref<java::math::BigInteger> divisor) { return call_method<SCAPIX_META_STRING("remainder"), ref<java::math::BigInteger>>(divisor); }
inline ref<java::math::BigInteger> BigInteger::modInverse(ref<java::math::BigInteger> m) { return call_method<SCAPIX_META_STRING("modInverse"), ref<java::math::BigInteger>>(m); }
inline ref<java::math::BigInteger> BigInteger::modPow(ref<java::math::BigInteger> exponent, ref<java::math::BigInteger> modulus) { return call_method<SCAPIX_META_STRING("modPow"), ref<java::math::BigInteger>>(exponent, modulus); }
inline ref<java::math::BigInteger> BigInteger::mod(ref<java::math::BigInteger> m) { return call_method<SCAPIX_META_STRING("mod"), ref<java::math::BigInteger>>(m); }
inline jboolean BigInteger::isProbablePrime(jint certainty) { return call_method<SCAPIX_META_STRING("isProbablePrime"), jboolean>(certainty); }
inline ref<java::math::BigInteger> BigInteger::nextProbablePrime() { return call_method<SCAPIX_META_STRING("nextProbablePrime"), ref<java::math::BigInteger>>(); }
inline ref<java::math::BigInteger> BigInteger::probablePrime(jint bitLength, ref<java::util::Random> random) { return call_static_method<SCAPIX_META_STRING("probablePrime"), ref<java::math::BigInteger>>(bitLength, random); }

} // namespace java::math
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_MATH_BIGINTEGER_H