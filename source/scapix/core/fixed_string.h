/*
	scapix/core/fixed_string.h

	Copyright (c) 2019-2022 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_CORE_FIXED_STRING_H
#define SCAPIX_CORE_FIXED_STRING_H

#include <cstddef>

namespace scapix {

template <typename Char, std::size_t N>
class fixed_string
{
public:

	using char_type = Char;

	constexpr fixed_string(const Char(&input)[N]) noexcept
	{
		for (std::size_t i = 0; i < N; ++i)
			content[i] = input[i];
	}

	constexpr std::size_t size() const noexcept { return N - 1; }

	constexpr Char operator[](std::size_t i) const noexcept { return content[i]; }
	constexpr const Char* begin() const noexcept { return content; }
	constexpr const Char* end() const noexcept { return content + size(); }

	Char content[N];
};

template <typename Char>
class fixed_string<Char, 0>
{
public:

	using char_type = Char;

	constexpr fixed_string(const Char*) noexcept { }
	constexpr std::size_t size() const noexcept { return 0; }
	constexpr const Char* begin() const noexcept { return nullptr; }
	constexpr const Char* end() const noexcept { return nullptr; }
};

template <typename Char, std::size_t N> fixed_string(const Char(&)[N]) -> fixed_string<Char, N>;
template <typename Char, std::size_t N> fixed_string(fixed_string<Char, N>) -> fixed_string<Char, N>;

} // namespace scapix

#endif // SCAPIX_CORE_FIXED_STRING_H
