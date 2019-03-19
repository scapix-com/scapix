// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/util/stream/AbstractPipeline.h>
#include <scapix/java_api/java/util/stream/Stream.h>

#ifndef SCAPIX_JAVA_UTIL_STREAM_REFERENCEPIPELINE_H
#define SCAPIX_JAVA_UTIL_STREAM_REFERENCEPIPELINE_H

namespace scapix::java_api {

namespace java::lang { class Object; }
namespace java::util { class Comparator; }
namespace java::util { class Iterator; }
namespace java::util { class Optional; }
namespace java::util::function { class BiConsumer; }
namespace java::util::function { class BiFunction; }
namespace java::util::function { class BinaryOperator; }
namespace java::util::function { class Consumer; }
namespace java::util::function { class Function; }
namespace java::util::function { class IntFunction; }
namespace java::util::function { class Predicate; }
namespace java::util::function { class Supplier; }
namespace java::util::function { class ToDoubleFunction; }
namespace java::util::function { class ToIntFunction; }
namespace java::util::function { class ToLongFunction; }
namespace java::util::stream { class Collector; }
namespace java::util::stream { class DoubleStream; }
namespace java::util::stream { class IntStream; }
namespace java::util::stream { class LongStream; }

namespace java::util::stream {

// private
class ReferencePipeline : public object_base<SCAPIX_META_STRING("java/util/stream/ReferencePipeline"),
	java::util::stream::AbstractPipeline,
	java::util::stream::Stream>
{
public:

	ref<java::util::Iterator> iterator();
	ref<java::util::stream::Stream> unordered();
	ref<java::util::stream::Stream> filter(ref<java::util::function::Predicate> predicate);
	ref<java::util::stream::Stream> map(ref<java::util::function::Function> mapper);
	ref<java::util::stream::IntStream> mapToInt(ref<java::util::function::ToIntFunction> mapper);
	ref<java::util::stream::LongStream> mapToLong(ref<java::util::function::ToLongFunction> mapper);
	ref<java::util::stream::DoubleStream> mapToDouble(ref<java::util::function::ToDoubleFunction> mapper);
	ref<java::util::stream::Stream> flatMap(ref<java::util::function::Function> mapper);
	ref<java::util::stream::IntStream> flatMapToInt(ref<java::util::function::Function> mapper);
	ref<java::util::stream::DoubleStream> flatMapToDouble(ref<java::util::function::Function> mapper);
	ref<java::util::stream::LongStream> flatMapToLong(ref<java::util::function::Function> mapper);
	ref<java::util::stream::Stream> peek(ref<java::util::function::Consumer> action);
	ref<java::util::stream::Stream> distinct();
	ref<java::util::stream::Stream> sorted();
	ref<java::util::stream::Stream> sorted(ref<java::util::Comparator> comparator);
	ref<java::util::stream::Stream> limit(jlong maxSize);
	ref<java::util::stream::Stream> skip(jlong n);
	ref<java::util::stream::Stream> takeWhile(ref<java::util::function::Predicate> predicate);
	ref<java::util::stream::Stream> dropWhile(ref<java::util::function::Predicate> predicate);
	void forEach(ref<java::util::function::Consumer> action);
	void forEachOrdered(ref<java::util::function::Consumer> action);
	ref<link::java::array<java::lang::Object>> toArray(ref<java::util::function::IntFunction> generator);
	ref<link::java::array<java::lang::Object>> toArray();
	jboolean anyMatch(ref<java::util::function::Predicate> predicate);
	jboolean allMatch(ref<java::util::function::Predicate> predicate);
	jboolean noneMatch(ref<java::util::function::Predicate> predicate);
	ref<java::util::Optional> findFirst();
	ref<java::util::Optional> findAny();
	ref<java::lang::Object> reduce(ref<java::lang::Object> identity, ref<java::util::function::BinaryOperator> accumulator);
	ref<java::util::Optional> reduce(ref<java::util::function::BinaryOperator> accumulator);
	ref<java::lang::Object> reduce(ref<java::lang::Object> identity, ref<java::util::function::BiFunction> accumulator, ref<java::util::function::BinaryOperator> combiner);
	ref<java::lang::Object> collect(ref<java::util::stream::Collector> collector);
	ref<java::lang::Object> collect(ref<java::util::function::Supplier> supplier, ref<java::util::function::BiConsumer> accumulator, ref<java::util::function::BiConsumer> combiner);
	ref<java::util::Optional> max(ref<java::util::Comparator> comparator);
	ref<java::util::Optional> min(ref<java::util::Comparator> comparator);
	jlong count();

protected:

	ReferencePipeline(handle_type h) : base_(h) {}

};

} // namespace java::util::stream
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/java/util/Comparator.h>
#include <scapix/java_api/java/util/Iterator.h>
#include <scapix/java_api/java/util/Optional.h>
#include <scapix/java_api/java/util/function/BiConsumer.h>
#include <scapix/java_api/java/util/function/BiFunction.h>
#include <scapix/java_api/java/util/function/BinaryOperator.h>
#include <scapix/java_api/java/util/function/Consumer.h>
#include <scapix/java_api/java/util/function/Function.h>
#include <scapix/java_api/java/util/function/IntFunction.h>
#include <scapix/java_api/java/util/function/Predicate.h>
#include <scapix/java_api/java/util/function/Supplier.h>
#include <scapix/java_api/java/util/function/ToDoubleFunction.h>
#include <scapix/java_api/java/util/function/ToIntFunction.h>
#include <scapix/java_api/java/util/function/ToLongFunction.h>
#include <scapix/java_api/java/util/stream/Collector.h>
#include <scapix/java_api/java/util/stream/DoubleStream.h>
#include <scapix/java_api/java/util/stream/IntStream.h>
#include <scapix/java_api/java/util/stream/LongStream.h>

namespace scapix::java_api {
namespace java::util::stream {

inline ref<java::util::Iterator> ReferencePipeline::iterator() { return call_method<SCAPIX_META_STRING("iterator"), ref<java::util::Iterator>>(); }
inline ref<java::util::stream::Stream> ReferencePipeline::unordered() { return call_method<SCAPIX_META_STRING("unordered"), ref<java::util::stream::Stream>>(); }
inline ref<java::util::stream::Stream> ReferencePipeline::filter(ref<java::util::function::Predicate> predicate) { return call_method<SCAPIX_META_STRING("filter"), ref<java::util::stream::Stream>>(predicate); }
inline ref<java::util::stream::Stream> ReferencePipeline::map(ref<java::util::function::Function> mapper) { return call_method<SCAPIX_META_STRING("map"), ref<java::util::stream::Stream>>(mapper); }
inline ref<java::util::stream::IntStream> ReferencePipeline::mapToInt(ref<java::util::function::ToIntFunction> mapper) { return call_method<SCAPIX_META_STRING("mapToInt"), ref<java::util::stream::IntStream>>(mapper); }
inline ref<java::util::stream::LongStream> ReferencePipeline::mapToLong(ref<java::util::function::ToLongFunction> mapper) { return call_method<SCAPIX_META_STRING("mapToLong"), ref<java::util::stream::LongStream>>(mapper); }
inline ref<java::util::stream::DoubleStream> ReferencePipeline::mapToDouble(ref<java::util::function::ToDoubleFunction> mapper) { return call_method<SCAPIX_META_STRING("mapToDouble"), ref<java::util::stream::DoubleStream>>(mapper); }
inline ref<java::util::stream::Stream> ReferencePipeline::flatMap(ref<java::util::function::Function> mapper) { return call_method<SCAPIX_META_STRING("flatMap"), ref<java::util::stream::Stream>>(mapper); }
inline ref<java::util::stream::IntStream> ReferencePipeline::flatMapToInt(ref<java::util::function::Function> mapper) { return call_method<SCAPIX_META_STRING("flatMapToInt"), ref<java::util::stream::IntStream>>(mapper); }
inline ref<java::util::stream::DoubleStream> ReferencePipeline::flatMapToDouble(ref<java::util::function::Function> mapper) { return call_method<SCAPIX_META_STRING("flatMapToDouble"), ref<java::util::stream::DoubleStream>>(mapper); }
inline ref<java::util::stream::LongStream> ReferencePipeline::flatMapToLong(ref<java::util::function::Function> mapper) { return call_method<SCAPIX_META_STRING("flatMapToLong"), ref<java::util::stream::LongStream>>(mapper); }
inline ref<java::util::stream::Stream> ReferencePipeline::peek(ref<java::util::function::Consumer> action) { return call_method<SCAPIX_META_STRING("peek"), ref<java::util::stream::Stream>>(action); }
inline ref<java::util::stream::Stream> ReferencePipeline::distinct() { return call_method<SCAPIX_META_STRING("distinct"), ref<java::util::stream::Stream>>(); }
inline ref<java::util::stream::Stream> ReferencePipeline::sorted() { return call_method<SCAPIX_META_STRING("sorted"), ref<java::util::stream::Stream>>(); }
inline ref<java::util::stream::Stream> ReferencePipeline::sorted(ref<java::util::Comparator> comparator) { return call_method<SCAPIX_META_STRING("sorted"), ref<java::util::stream::Stream>>(comparator); }
inline ref<java::util::stream::Stream> ReferencePipeline::limit(jlong maxSize) { return call_method<SCAPIX_META_STRING("limit"), ref<java::util::stream::Stream>>(maxSize); }
inline ref<java::util::stream::Stream> ReferencePipeline::skip(jlong n) { return call_method<SCAPIX_META_STRING("skip"), ref<java::util::stream::Stream>>(n); }
inline ref<java::util::stream::Stream> ReferencePipeline::takeWhile(ref<java::util::function::Predicate> predicate) { return call_method<SCAPIX_META_STRING("takeWhile"), ref<java::util::stream::Stream>>(predicate); }
inline ref<java::util::stream::Stream> ReferencePipeline::dropWhile(ref<java::util::function::Predicate> predicate) { return call_method<SCAPIX_META_STRING("dropWhile"), ref<java::util::stream::Stream>>(predicate); }
inline void ReferencePipeline::forEach(ref<java::util::function::Consumer> action) { return call_method<SCAPIX_META_STRING("forEach"), void>(action); }
inline void ReferencePipeline::forEachOrdered(ref<java::util::function::Consumer> action) { return call_method<SCAPIX_META_STRING("forEachOrdered"), void>(action); }
inline ref<link::java::array<java::lang::Object>> ReferencePipeline::toArray(ref<java::util::function::IntFunction> generator) { return call_method<SCAPIX_META_STRING("toArray"), ref<link::java::array<java::lang::Object>>>(generator); }
inline ref<link::java::array<java::lang::Object>> ReferencePipeline::toArray() { return call_method<SCAPIX_META_STRING("toArray"), ref<link::java::array<java::lang::Object>>>(); }
inline jboolean ReferencePipeline::anyMatch(ref<java::util::function::Predicate> predicate) { return call_method<SCAPIX_META_STRING("anyMatch"), jboolean>(predicate); }
inline jboolean ReferencePipeline::allMatch(ref<java::util::function::Predicate> predicate) { return call_method<SCAPIX_META_STRING("allMatch"), jboolean>(predicate); }
inline jboolean ReferencePipeline::noneMatch(ref<java::util::function::Predicate> predicate) { return call_method<SCAPIX_META_STRING("noneMatch"), jboolean>(predicate); }
inline ref<java::util::Optional> ReferencePipeline::findFirst() { return call_method<SCAPIX_META_STRING("findFirst"), ref<java::util::Optional>>(); }
inline ref<java::util::Optional> ReferencePipeline::findAny() { return call_method<SCAPIX_META_STRING("findAny"), ref<java::util::Optional>>(); }
inline ref<java::lang::Object> ReferencePipeline::reduce(ref<java::lang::Object> identity, ref<java::util::function::BinaryOperator> accumulator) { return call_method<SCAPIX_META_STRING("reduce"), ref<java::lang::Object>>(identity, accumulator); }
inline ref<java::util::Optional> ReferencePipeline::reduce(ref<java::util::function::BinaryOperator> accumulator) { return call_method<SCAPIX_META_STRING("reduce"), ref<java::util::Optional>>(accumulator); }
inline ref<java::lang::Object> ReferencePipeline::reduce(ref<java::lang::Object> identity, ref<java::util::function::BiFunction> accumulator, ref<java::util::function::BinaryOperator> combiner) { return call_method<SCAPIX_META_STRING("reduce"), ref<java::lang::Object>>(identity, accumulator, combiner); }
inline ref<java::lang::Object> ReferencePipeline::collect(ref<java::util::stream::Collector> collector) { return call_method<SCAPIX_META_STRING("collect"), ref<java::lang::Object>>(collector); }
inline ref<java::lang::Object> ReferencePipeline::collect(ref<java::util::function::Supplier> supplier, ref<java::util::function::BiConsumer> accumulator, ref<java::util::function::BiConsumer> combiner) { return call_method<SCAPIX_META_STRING("collect"), ref<java::lang::Object>>(supplier, accumulator, combiner); }
inline ref<java::util::Optional> ReferencePipeline::max(ref<java::util::Comparator> comparator) { return call_method<SCAPIX_META_STRING("max"), ref<java::util::Optional>>(comparator); }
inline ref<java::util::Optional> ReferencePipeline::min(ref<java::util::Comparator> comparator) { return call_method<SCAPIX_META_STRING("min"), ref<java::util::Optional>>(comparator); }
inline jlong ReferencePipeline::count() { return call_method<SCAPIX_META_STRING("count"), jlong>(); }

} // namespace java::util::stream
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_UTIL_STREAM_REFERENCEPIPELINE_H