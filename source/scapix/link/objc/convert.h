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

// C++20
template <typename T>
using remove_cvref_t = std::remove_cv_t<std::remove_reference_t<T>>;

template <typename ObjC, typename Cpp, typename = void>
struct convert;

template <typename ObjC, typename Cpp>
decltype(auto) convert_objc(Cpp&& cpp)
{
    return convert<remove_cvref_t<ObjC>, remove_cvref_t<Cpp>>::objc(std::forward<Cpp>(cpp));
}

template <typename Cpp, typename ObjC>
decltype(auto) convert_cpp(ObjC&& objc)
{
    return convert<remove_cvref_t<ObjC>, remove_cvref_t<Cpp>>::cpp(std::forward<ObjC>(objc));
}

template<typename ObjC, typename Cpp>
using has_convert_objc_t = decltype(std::declval<ObjC>() = convert<remove_cvref_t<ObjC>, remove_cvref_t<Cpp>>::objc(std::declval<Cpp>()));

template<typename ObjC, typename Cpp>
using has_convert_cpp_t = decltype(std::declval<Cpp>() = convert<remove_cvref_t<ObjC>, remove_cvref_t<Cpp>>::cpp(std::declval<ObjC>()));

template <typename T>
struct convert<T, T>
{
    static T cpp(T value)
    {
        return value;
    }

    static T objc(T value)
    {
        return value;
    }
};

template <>
struct convert<BOOL, bool>
{
    static bool cpp(BOOL value)
    {
        return value;
    }

    static BOOL objc(bool value)
    {
        return value;
    }
};

template <typename ObjC, typename Cpp, typename = void>
struct convert_shared;

template<typename ObjC, typename Cpp>
using has_convert_shared_t = decltype(convert_shared<ObjC, Cpp>::objc(std::declval<std::shared_ptr<Cpp>>()));

template <typename ObjC, typename T>
struct convert<ObjC, std::shared_ptr<T>>
{
	static std::shared_ptr<T> cpp(ObjC value)
	{
		if constexpr (std::experimental::is_detected_v<has_convert_shared_t, ObjC, T>)
			return convert_shared<ObjC, T>::cpp(value);
		else
			return std::make_shared<T>(convert_cpp<T>(value));
	}

	static ObjC objc(std::shared_ptr<T> value)
	{
		if constexpr (std::experimental::is_detected_v<has_convert_shared_t, ObjC, T>)
			return convert_shared<ObjC, T>::objc(value);
		else
			return convert_objc<ObjC>(*value);
	}
};

template <>
struct convert<NSNumber*, bool>
{
    static bool cpp(NSNumber* value)
    {
        return [value boolValue];
    }
    
    static NSNumber* objc(bool value)
    {
        return [NSNumber numberWithBool:value];
    }
};

template <>
struct convert<NSNumber*, std::int8_t>
{
    static std::int8_t cpp(NSNumber* value)
    {
        return [value charValue];
    }
    
    static NSNumber* objc(std::int8_t value)
    {
        return [NSNumber numberWithChar:value];
    }
};

template <>
struct convert<NSNumber*, std::int16_t>
{
    static std::int16_t cpp(NSNumber* value)
    {
        return [value shortValue];
    }
    
    static NSNumber* objc(std::int16_t value)
    {
        return [NSNumber numberWithShort:value];
    }
};

template <>
struct convert<NSNumber*, std::int32_t>
{
    static std::int32_t cpp(NSNumber* value)
    {
        return [value intValue];
    }

    static NSNumber* objc(std::int32_t value)
    {
        return [NSNumber numberWithInt:value];
    }
};

template <>
struct convert<NSNumber*, std::int64_t>
{
    static std::int64_t cpp(NSNumber* value)
    {
        return [value longValue];
    }

    static NSNumber* objc(std::int64_t value)
    {
        return [NSNumber numberWithLong:value];
    }
};

template <>
struct convert<NSNumber*, float>
{
    static float cpp(NSNumber* value)
    {
        return [value floatValue];
    }

    static NSNumber* objc(float value)
    {
        return [NSNumber numberWithFloat:value];
    }
};

template <>
struct convert<NSNumber*, double>
{
    static double cpp(NSNumber* value)
    {
        return [value doubleValue];
    }

    static NSNumber* objc(double value)
    {
        return [NSNumber numberWithDouble:value];
    }
};

template <>
struct convert<NSString*, std::string>
{
    static std::string cpp(NSString* value)
    {
        if (!value)
            return std::string();
        
        return std::string([value UTF8String]);
    }

    static NSString* objc(std::string_view value)
    {
        return [NSString stringWithUTF8String:value.data()];
    }
};

// to do: replace nullptr values with [NSNull null]
// to do: direct bridge to Swift would be more efficient (https://developer.apple.com/documentation/swift/array)

template <typename Array, typename T, typename A>
struct convert<Array, std::vector<T, A>, std::enable_if_t<std::is_convertible_v<Array, NSArray*>>>
{
    using objc_value = decltype(std::declval<Array>()[0]);

    static std::vector<T, A> cpp(Array value)
    {
        std::vector<T, A> vec;
        vec.reserve(value.count);

        for (objc_value element in value)
        {
            vec.push_back(convert_cpp<T>(element));
        }

        return vec;
    }

    static Array objc(const std::vector<T, A>& value)
    {
        NSMutableArray<objc_value>* arr = [NSMutableArray<objc_value> arrayWithCapacity: value.size()];

        for (const T& element : value)
        {
            [arr addObject: convert_objc<objc_value>(element)];
        }

        return arr;
    }
};

// no ordered map in objc/swift

template <typename Dictionary, typename K, typename T, typename C, typename A>
struct convert<Dictionary, std::map<K, T, C, A>, std::enable_if_t<std::is_convertible_v<Dictionary, NSDictionary*>>>
{
    using objc_key = decltype([[std::declval<Dictionary>() keyEnumerator] nextObject]);
    using objc_value = decltype([std::declval<Dictionary>() objectForKey:nil]);

    static std::map<K, T, C, A> cpp(NSDictionary<objc_key, objc_value>* value)
    {
        std::map<K, T, C, A> map;

        for (objc_key key in value)
        {
            map.emplace(convert_cpp<K>(key), convert_cpp<T>([value objectForKey:key]));
        }

        return map;
    }

    static NSDictionary<objc_key, objc_value>* objc(const std::map<K, T, C, A>& value)
    {
        NSMutableDictionary<objc_key, objc_value>* dict = [NSMutableDictionary<objc_key, objc_value> dictionaryWithCapacity: value.size()];

        for (const auto& element : value)
        {
            [dict setObject: convert_objc<objc_value>(element.second) forKey: convert_objc<objc_key>(element.first)];
        }

        return dict;
    }
};

template <typename Dictionary, typename K, typename V, typename H, typename P, typename A>
struct convert<Dictionary, std::unordered_map<K, V, H, P, A>, std::enable_if_t<std::is_convertible_v<Dictionary, NSDictionary*>>>
{
    using objc_key = decltype([[std::declval<Dictionary>() keyEnumerator] nextObject]);
    using objc_value = decltype([std::declval<Dictionary>() objectForKey:nil]);

    static std::unordered_map<K, V, H, P, A> cpp(NSDictionary<objc_key, objc_value>* value)
    {
        std::unordered_map<K, V, H, P, A> map;

        for (objc_key key in value)
        {
            map.emplace(convert_cpp<K>(key), convert_cpp<V>([value objectForKey:key]));
        }

        return map;
    }

    static NSDictionary<objc_key, objc_value>* objc(const std::unordered_map<K, V, H, P, A>& value)
    {
        NSMutableDictionary<objc_key, objc_value>* dict = [NSMutableDictionary<objc_key, objc_value> dictionaryWithCapacity: value.size()];

        for (const auto& element : value)
        {
            [dict setObject: convert_objc<objc_value>(element.second) forKey: convert_objc<objc_key>(element.first)];
        }

        return dict;
    }
};

template <typename Set, typename V, typename H, typename P, typename A>
struct convert<Set, std::unordered_set<V, H, P, A>, std::enable_if_t<std::is_convertible_v<Set, NSSet*>>>
{
    using objc_value = decltype([std::declval<Set>() member:nil]);

    static std::unordered_set<V, H, P, A> cpp(NSSet<objc_value>* value)
    {
        std::unordered_set<V, H, P, A> set;
        
        for (objc_value element in value)
        {
            set.insert(convert_cpp<V>(element));
        }
        
        return set;
    }

    static NSSet<objc_value>* objc(const std::unordered_set<V, H, P, A>& value)
    {
        NSMutableSet<objc_value>* set = [NSMutableSet<objc_value> setWithCapacity: value.size()];
        
        for (const V& element : value)
        {
            [set addObject: convert_objc<objc_value>(element)];
        }
        
        return set;
    }
};

template <typename Set, typename K, typename C, typename A>
struct convert<Set, std::set<K, C, A>, std::enable_if_t<std::is_convertible_v<Set, NSOrderedSet*>>>
{
    using objc_value = decltype([std::declval<Set>() firstObject]);

    static std::set<K, C, A> cpp(NSOrderedSet<objc_value>* value)
    {
        std::set<K, C, A> set;
        
        for (objc_value element in value)
        {
            set.insert(set.end(), convert_cpp<K>(element));
        }
        
        return set;
    }

    static NSOrderedSet<objc_value>* objc(const std::set<K, C, A>& value)
    {
        NSMutableOrderedSet<objc_value>* set = [NSMutableOrderedSet<objc_value> orderedSetWithCapacity: value.size()];
        
        for (const K& element : value)
        {
            [set addObject: convert_objc<objc_value>(element)];
        }
        
        return set;
    }
};

template <typename ObjcR, typename ...ObjcArgs, typename R, typename ...Args>
struct convert<ObjcR(^)(ObjcArgs...), std::function<R(Args...)>>
{
    using block = ObjcR(^)(ObjcArgs...);

    static std::function<R(Args...)> cpp(const block& value)
    {
        return [value = std::move(value)](Args... args)
        {
            if constexpr (std::is_void_v<R>)
                return value(convert_objc<ObjcArgs>(args)...);
            else
                return convert_cpp<R>(value(convert_objc<ObjcArgs>(args)...));
        };
    }

    static block objc(const std::function<R(Args...)>& value)
    {
        return [value = std::move(value)](ObjcArgs... args)
        {
            if constexpr (std::is_void_v<ObjcR>)
                return value(convert_cpp<Args>(args)...);
            else
                return convert_objc<ObjcR>(value(convert_cpp<Args>(args)...));
        };
    }
};

} // namespace objc
} // namespace link
} // namespace scapix

#endif // SCAPIX_LINK_OBJC_CONVERT_H
