/*
	scapix/core/fixed_string.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_CORE_FIXED_STRING_H
#define SCAPIX_CORE_FIXED_STRING_H

#include <cstddef>
#include <utility>

namespace scapix {

template <typename Char, std::size_t N>
struct fixed_string
{
	template <std::size_t... I>
	constexpr fixed_string(const Char(&input)[N], std::index_sequence<I...>) noexcept: content{input[I]...} {}
	constexpr fixed_string(const Char(&input)[N]) noexcept: fixed_string(input, std::make_index_sequence<N>()) {}

	constexpr std::size_t size() const noexcept { return N - 1; }

	constexpr Char operator[](std::size_t i) const noexcept { return content[i]; }
	constexpr const Char* begin() const noexcept { return content; }
	constexpr const Char* end() const noexcept { return content + size(); }

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

} // namespace scapix

#endif // SCAPIX_CORE_FIXED_STRING_H
