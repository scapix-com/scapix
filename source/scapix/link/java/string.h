/*
	scapix/link/java/string.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

// outside of include guard
#include <scapix/link/java/object_impl.h>

#ifndef SCAPIX_LINK_JAVA_STRING_H
#define SCAPIX_LINK_JAVA_STRING_H

#include <stdexcept>
#include <type_traits>
#include <iterator>
#include <scapix/link/java/object.h>
#include <scapix/link/java/lock.h>
#include <scapix/link/java/detail/api/string.h>

namespace scapix::link::java {

template <typename Char, lock Lock>
class string_chars
{
public:

	typedef Char value_type;
	typedef std::make_unsigned<jsize>::type size_type;
	typedef jsize difference_type;
//	typedef value_type* pointer;
	typedef const value_type* pointer;
	typedef const value_type* const_pointer;
	typedef value_type& reference;
	typedef const value_type& const_reference;
	typedef value_type* iterator;
	typedef const value_type* const_iterator;
	typedef std::reverse_iterator<iterator> reverse_iterator;
	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

	string_chars(const string_chars&) = delete;
	string_chars& operator=(const string_chars&) = delete;

	string_chars(string_chars&& c) : string_(c.string_), is_copy_(c.is_copy_), data_(c.data_), size_(c.size_) { c.data_ = nullptr; }
	string_chars& operator=(string_chars&& c) = delete; // { c.swap(*this); return *this; }

	~string_chars() { release(); }

	pointer data() { return data_; }
	const_pointer data() const { return data_; }

	size_type size() const { return size_; }
	bool empty() const { return size() == 0; }

	iterator begin() { return data(); }
	const_iterator begin() const { return data(); }
	const_iterator cbegin() const { return data(); }

	iterator end() { return data() + size(); }
	const_iterator end() const { return data() + size(); }
	const_iterator cend() const { return data() + size(); }

	reverse_iterator rbegin() { return data() + size();	}
	const_reverse_iterator rbegin() const { return data() + size();	}
	const_reverse_iterator crbegin() const { return data() + size(); }

	reverse_iterator rend() { return data(); }
	const_reverse_iterator rend() const { return data(); }
	const_reverse_iterator crend() const { return data(); }

	reference operator[](size_type pos) { return data()[pos]; }
	const_reference operator[](size_type pos) const { return data()[pos]; }

	reference at(size_type pos)
	{
		if (pos >= size())
			throw std::out_of_range("string_chars");

		return (*this)[pos];
	}

	const_reference at(size_type pos) const
	{
		if (pos >= size())
			throw std::out_of_range("string_chars");

		return (*this)[pos];
	}

	jboolean is_copy() const
	{
		return is_copy_;
	}

	void release()
	{
		if (data_)
		{
			detail::api::release_string_chars<Char, Lock>(string_, data_);
			data_ = nullptr;
		}
	}

private:

	friend class string;

	string_chars(jstring string, jsize size) : string_(string), data_(detail::api::get_string_chars<Char, Lock>(string_, &is_copy_)), size_(size) {}

private:

	jstring string_;
	jboolean is_copy_;
	pointer data_;
	size_type size_;

};

class string : public object<SCAPIX_META_STRING("java/lang/String")>
{
public:

	static local_ref<string> new_(const jchar* buf, jsize len)
	{
		return local_ref<string>(detail::api::new_string(buf, len));
	}

	static local_ref<string> new_(const char* buf)
	{
		return local_ref<string>(detail::api::new_string(buf));
	}

	template <typename Char = jchar>
	jsize length() const
	{
		return detail::api::get_string_length<Char>(handle());
	}

	template <typename Char = jchar, lock Lock = lock::noncritical>
	string_chars<Char, Lock> chars() const
	{
		static_assert(!std::is_same_v<Char, char> || Lock != lock::critical, "Unsupported parameter combination: <char, critical>");
		return string_chars<Char, Lock>(handle(), length());
	}

	template <typename Char = jchar, lock Lock = lock::noncritical>
	string_chars<Char, Lock> chars(jsize size) const
	{
		static_assert(!std::is_same_v<Char, char> || Lock != lock::critical, "Unsupported parameter combination: <char, critical>");
		assert(size <= length());
		return string_chars<Char, Lock>(handle(), size);
	}

	template <typename Char>
	void get_region(jsize start, jsize len, Char* buf) const
	{
		detail::api::get_string_region(handle(), start, len, buf);
	}

protected:

	string(handle_type h) : object(h) {}

};

} // namespace scapix::link::java

#endif // SCAPIX_LINK_JAVA_STRING_H
