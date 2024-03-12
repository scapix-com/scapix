/*
	scapix/core/fixed_string.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_CORE_FIXED_STRING_H
#define SCAPIX_CORE_FIXED_STRING_H

#include <cstddef>
#include <utility>
#include <algorithm>

namespace scapix {

template <typename Char, std::size_t N>
struct fixed_string
{
	template <std::size_t... I>
	constexpr fixed_string(const Char(&input)[N], std::index_sequence<I...>) noexcept: content{input[I]...} {}
	constexpr fixed_string(const Char(&input)[N]) noexcept: fixed_string(input, std::make_index_sequence<N>()) {}

	template <std::size_t N1, std::size_t N2, std::size_t... I1, std::size_t... I2>
	constexpr fixed_string(fixed_string<Char, N1> s1, std::index_sequence<I1...>, fixed_string<Char, N2> s2, std::index_sequence<I2...>) noexcept : content{ s1[I1]..., s2[I2]... } {}

	template <std::size_t N1, std::size_t N2>
	constexpr fixed_string(fixed_string<Char, N1> s1, fixed_string<Char, N2> s2) noexcept : fixed_string(s1, std::make_index_sequence<N1-1>(), s2, std::make_index_sequence<N2>()) {}

	constexpr fixed_string replace(Char from, Char to) const noexcept
	{
		fixed_string r(content);

		for (std::size_t i = 0; i < N; ++i)
			if (content[i] == from)
				r.content[i] = to;

		return r;
	}

	constexpr std::size_t size() const noexcept { return N - 1; }

	constexpr Char operator[](std::size_t i) const noexcept { return content[i]; }
	constexpr const Char* begin() const noexcept { return content; }
	constexpr const Char* end() const noexcept { return content + size(); }
	constexpr operator const Char*() const noexcept { return content; }

	Char content[N];
};

template <typename Char>
struct fixed_string<Char, 0>
{
	constexpr fixed_string(const Char*) noexcept {}
	constexpr std::size_t size() const noexcept { return 0; }
	constexpr const Char* begin() const noexcept { return nullptr; }
	constexpr const Char* end() const noexcept { return nullptr; }
};

template <typename Char, std::size_t N> fixed_string(const Char(&)[N]) -> fixed_string<Char, N>;
template <typename Char, std::size_t N> fixed_string(fixed_string<Char, N>) -> fixed_string<Char, N>;

template <typename Char, std::size_t N1, std::size_t N2>
constexpr fixed_string<Char, N1 + N2 - 1> operator + (const fixed_string<Char, N1>& s1, const fixed_string<Char, N2>& s2)
{
	return fixed_string<Char, N1 + N2 - 1>(s1, s2);
}

template <typename Char, std::size_t N1, std::size_t N2>
constexpr fixed_string<Char, N1 + N2 - 1> operator + (const Char(&s1)[N1], const fixed_string<Char, N2>& s2)
{
	return fixed_string<Char, N1 + N2 - 1>(fixed_string(s1), s2);
}

template <typename Char, std::size_t N1, std::size_t N2>
constexpr fixed_string<Char, N1 + N2 - 1> operator + (const fixed_string<Char, N1>& s1, const Char(&s2)[N2])
{
	return fixed_string<Char, N1 + N2 - 1>(s1, fixed_string(s2));
}

template <typename Char, std::size_t N1, std::size_t N2>
constexpr bool operator == (const fixed_string<Char, N1>& s1, const fixed_string<Char, N2>& s2)
{
	return std::ranges::equal(s1.content, s2.content);
}

template <typename Char, std::size_t N1, std::size_t N2>
constexpr bool operator == (const Char(&s1)[N1], const fixed_string<Char, N2>& s2)
{
	return std::ranges::equal(s1, s2.content);
}

template <typename Char, std::size_t N1, std::size_t N2>
constexpr bool operator == (const fixed_string<Char, N1>& s1, const Char(&s2)[N2])
{
	return std::ranges::equal(s1.content, s2);
}

} // namespace scapix

#endif // SCAPIX_CORE_FIXED_STRING_H
