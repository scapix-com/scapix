/*
	scapix/link/objc/convert.h

	Copyright (c) 2019 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_OBJC_CONVERT_H
#define SCAPIX_LINK_OBJC_CONVERT_H

#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <experimental/type_traits>

#import <Foundation/Foundation.h>

namespace scapix {
namespace link {
namespace objc {

template <typename T>
using remove_cvref_t = std::remove_cv_t<std::remove_reference_t<T>>;

template <typename T1, typename T2, typename = void>
struct convert_impl;

template<typename To, typename From>
using has_convert_t = decltype(convert_impl<To, From>::convert(std::declval<From>()));

template <typename To, typename From>
decltype(auto) convert(From value)
{
    using to = remove_cvref_t<To>;
    using from = remove_cvref_t<From>;

    if constexpr (std::experimental::is_detected_v<has_convert_t, to, from>)
        return convert_impl<to, from>::convert(value);
    else
        return convert_impl<from, to>::convert(value);
}

template <typename T>
struct convert_impl<T, T>
{
    static T convert(T value)
    {
        return value;
    }
};

template <>
struct convert_impl<bool, BOOL>
{
    static bool convert(BOOL value)
    {
        return value;
    }

    template <typename T = BOOL, typename = std::enable_if_t<!std::is_same_v<bool, T>>>
    static BOOL convert(bool value)
    {
        return value;
    }
};

template <typename T, typename Y>
struct convert_impl<std::shared_ptr<T>, Y, std::enable_if_t<!bridge::is_object<T>>>
{
    static std::shared_ptr<T> convert(Y value)
    {
        return std::make_shared<T>(objc::convert<T>(value));
    }

    static Y convert(std::shared_ptr<T> value)
    {
        return objc::convert<Y>(*value);
    }
};

template <>
struct convert_impl<bool, NSNumber*>
{
    static bool convert(NSNumber* value)
    {
        return [value boolValue];
    }
    
    static NSNumber* convert(bool value)
    {
        return [NSNumber numberWithBool:value];
    }
};

template <>
struct convert_impl<std::int8_t, NSNumber*>
{
    static std::int8_t convert(NSNumber* value)
    {
        return [value charValue];
    }
    
    static NSNumber* convert(std::int8_t value)
    {
        return [NSNumber numberWithChar:value];
    }
};

template <>
struct convert_impl<std::int16_t, NSNumber*>
{
    static std::int16_t convert(NSNumber* value)
    {
        return [value shortValue];
    }
    
    static NSNumber* convert(std::int16_t value)
    {
        return [NSNumber numberWithShort:value];
    }
};

template <>
struct convert_impl<std::int32_t, NSNumber*>
{
    static std::int32_t convert(NSNumber* value)
    {
        return [value intValue];
    }

    static NSNumber* convert(std::int32_t value)
    {
        return [NSNumber numberWithInt:value];
    }
};

template <>
struct convert_impl<std::int64_t, NSNumber*>
{
    static std::int64_t convert(NSNumber* value)
    {
        return [value longValue];
    }
    
    static NSNumber* convert(std::int64_t value)
    {
        return [NSNumber numberWithLong:value];
    }
};

template <>
struct convert_impl<float, NSNumber*>
{
    static float convert(NSNumber* value)
    {
        return [value floatValue];
    }
    
    static NSNumber* convert(float value)
    {
        return [NSNumber numberWithFloat:value];
    }
};

template <>
struct convert_impl<double, NSNumber*>
{
    static double convert(NSNumber* value)
    {
        return [value doubleValue];
    }
    
    static NSNumber* convert(double value)
    {
        return [NSNumber numberWithDouble:value];
    }
};

template <>
struct convert_impl<std::string, NSString*>
{
    static std::string convert(NSString* value)
    {
        if (!value)
            return std::string();
        
        return std::string([value UTF8String]);
    }
    
    static NSString* convert(const std::string& value)
    {
        return [NSString stringWithUTF8String:value.data()];
    }
};

// to do: replace nullptr values with [NSNull null]
// to do: direct bridge to Swift would be more efficient (https://developer.apple.com/documentation/swift/array)

template <typename T, typename A, typename Array>
struct convert_impl<std::vector<T, A>, Array, std::enable_if_t<std::is_convertible_v<Array, NSArray*>>>
{
    using objc_value = decltype(std::declval<Array>()[0]);

    static std::vector<T, A> convert(Array value)
    {
        std::vector<T, A> vec;
        vec.reserve(value.count);

        for (objc_value element in value)
        {
            vec.push_back(objc::convert<T>(element));
        }

        return vec;
    }

    static Array convert(const std::vector<T, A>& value)
    {
        NSMutableArray<objc_value>* arr = [NSMutableArray<objc_value> arrayWithCapacity: value.size()];

        for (const T& element : value)
        {
            [arr addObject: objc::convert<objc_value>(element)];
        }

        return arr;
    }
};

// no ordered map in objc/swift

template <typename K, typename T, typename C, typename A, typename Dictionary>
struct convert_impl<std::map<K, T, C, A>, Dictionary, std::enable_if_t<std::is_convertible_v<Dictionary, NSDictionary*>>>
{
    using objc_key = decltype([[std::declval<Dictionary>() keyEnumerator] nextObject]);
    using objc_value = decltype([std::declval<Dictionary>() objectForKey:nil]);

    static std::map<K, T, C, A> convert(NSDictionary<objc_key, objc_value>* value)
    {
        std::map<K, T, C, A> map;

        for (objc_key key in value)
        {
            map.emplace(objc::convert<K>(key), objc::convert<T>([value objectForKey:key]));
        }

        return map;
    }

    static NSDictionary<objc_key, objc_value>* convert(const std::map<K, T, C, A>& value)
    {
        NSMutableDictionary<objc_key, objc_value>* dict = [NSMutableDictionary<objc_key, objc_value> dictionaryWithCapacity: value.size()];

        for (const auto& element : value)
        {
            [dict setObject: objc::convert<objc_value>(element.second) forKey: objc::convert<objc_key>(element.first)];
        }

        return dict;
    }
};

template <typename K, typename V, typename H, typename P, typename A, typename Dictionary>
struct convert_impl<std::unordered_map<K, V, H, P, A>, Dictionary, std::enable_if_t<std::is_convertible_v<Dictionary, NSDictionary*>>>
{
    using objc_key = decltype([[std::declval<Dictionary>() keyEnumerator] nextObject]);
    using objc_value = decltype([std::declval<Dictionary>() objectForKey:nil]);

    static std::unordered_map<K, V, H, P, A> convert(NSDictionary<objc_key, objc_value>* value)
    {
        std::unordered_map<K, V, H, P, A> map;
        
        for (objc_key key in value)
        {
            map.emplace(objc::convert<K>(key), objc::convert<V>([value objectForKey:key]));
        }
        
        return map;
    }

    static NSDictionary<objc_key, objc_value>* convert(const std::unordered_map<K, V, H, P, A>& value)
    {
        NSMutableDictionary<objc_key, objc_value>* dict = [NSMutableDictionary<objc_key, objc_value> dictionaryWithCapacity: value.size()];
        
        for (const auto& element : value)
        {
            [dict setObject: objc::convert<objc_value>(element.second) forKey: objc::convert<objc_key>(element.first)];
        }
        
        return dict;
    }
};

template <typename V, typename H, typename P, typename A, typename Set>
struct convert_impl<std::unordered_set<V, H, P, A>, Set, std::enable_if_t<std::is_convertible_v<Set, NSSet*>>>
{
    using objc_value = decltype([std::declval<Set>() member:nil]);

    static std::unordered_set<V, H, P, A> convert(NSSet<objc_value>* value)
    {
        std::unordered_set<V, H, P, A> set;
        
        for (objc_value element in value)
        {
            set.insert(objc::convert<V>(element));
        }
        
        return set;
    }

    static NSSet<objc_value>* convert(const std::unordered_set<V, H, P, A>& value)
    {
        NSMutableSet<objc_value>* set = [NSMutableSet<objc_value> setWithCapacity: value.size()];
        
        for (const V& element : value)
        {
            [set addObject: objc::convert<objc_value>(element)];
        }
        
        return set;
    }
};

template <typename K, typename C, typename A, typename Set>
struct convert_impl<std::set<K, C, A>, Set, std::enable_if_t<std::is_convertible_v<Set, NSOrderedSet*>>>
{
    using objc_value = decltype([std::declval<Set>() firstObject]);

    static std::set<K, C, A> convert(NSOrderedSet<objc_value>* value)
    {
        std::set<K, C, A> set;
        
        for (objc_value element in value)
        {
            set.insert(set.end(), objc::convert<K>(element));
        }
        
        return set;
    }

    static NSOrderedSet<objc_value>* convert(const std::set<K, C, A>& value)
    {
        NSMutableOrderedSet<objc_value>* set = [NSMutableOrderedSet<objc_value> orderedSetWithCapacity: value.size()];
        
        for (const K& element : value)
        {
            [set addObject: objc::convert<objc_value>(element)];
        }
        
        return set;
    }
};

template <typename R, typename ...Args, typename ObjcR, typename ...ObjcArgs>
struct convert_impl<std::function<R(Args...)>, ObjcR(^)(ObjcArgs...)>
{
    using block = ObjcR(^)(ObjcArgs...);

    static std::function<R(Args...)> convert(const block& value)
    {
        return [value = std::move(value)](Args... args)
        {
            if constexpr (std::is_void_v<R>)
                return value(objc::convert<ObjcArgs>(args)...);
            else
                return objc::convert<R>(value(objc::convert<ObjcArgs>(args)...));
        };
    }

    static block convert(const std::function<R(Args...)>& value)
    {
        return [value = std::move(value)](ObjcArgs... args)
        {
            if constexpr (std::is_void_v<ObjcR>)
                return value(objc::convert<Args>(args)...);
            else
                return objc::convert<ObjcR>(value(objc::convert<Args>(args)...));
        };
    }
};

} // namespace objc
} // namespace link
} // namespace scapix

#endif // SCAPIX_LINK_OBJC_CONVERT_H
