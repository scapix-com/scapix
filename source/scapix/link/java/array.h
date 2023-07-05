/*
	scapix/link/java/array.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_ARRAY_H
#define SCAPIX_LINK_JAVA_ARRAY_H

#include <utility>
#include <stdexcept>
#include <scapix/link/java/object.h>
#include <scapix/link/java/ref.h>
#include <scapix/link/java/lock.h>
#include <scapix/link/java/signature.h>
#include <scapix/link/java/detail/api/type.h>
#include <scapix/link/java/detail/api/array.h>

namespace scapix::link::java {

template <typename T>
class array_base : public object<signature_t<T[]>>
{
	using base = object<signature_t<T[]>>;

public:

	jsize size() const { return detail::api::get_array_length(this->handle()); }

protected:

	array_base(typename base::handle_type h) : base(h) {}

};

// object array

template <typename T>
class array<T, std::enable_if_t<!is_primitive_v<T>>> : public array_base<T>
{
	using base = array_base<T>;

public:

	class reference;
	class const_reference;
	class iterator;
	class const_iterator;

	using value_type = ref<T>;
	using element_type = typename ref<T>::element_type;
	using size_type = jsize;
	using difference_type = jsize;
	using pointer = void;
	using const_pointer = void;
	using reverse_iterator = std::reverse_iterator<iterator>;
	using const_reverse_iterator = std::reverse_iterator<const_iterator>;

	class reference
	{
	public:

		// We rely on C++17 guaranteed copy elision.
		// The same could be done in C++11 with Copy-List-Initialization (return {handle, size}).

		reference() = delete;
		reference(const reference&) = delete;
		reference(reference&&) = delete;

		void operator &() = delete;

		reference& operator =(const reference& other) { *this = other.get(); return *this; }
		reference& operator =(reference&& other) { *this = other.get(); return *this; }

		template <typename Y>
		reference& operator =(ref<Y> value) { arr.set_element(pos, value); return *this; }

		operator ref<T>() const { return get(); }
		ref<T> get() const { return arr.get_element(pos); }
		ref<T> operator ->() const { return get(); }

	private:

		friend array;
		friend class iterator;

		reference(typename array::handle_type arr, jsize pos) : arr(arr), pos(pos) {}

		array arr;
		jsize pos;

	};

	class iterator
	{
	public:

		using difference_type = jsize;
		using value_type = ref<T>;
		using pointer = void;
		using reference = array::reference;
		using iterator_category = std::random_access_iterator_tag;

		iterator() : pos(0) {}
		iterator(const iterator&) = default;
		iterator& operator =(const iterator&) = default;

		iterator& operator ++() { ++pos; return *this; }
		iterator& operator --() { --pos; return *this; }

		iterator operator ++(int) { iterator temp(*this); ++pos; return temp; }
		iterator operator --(int) { iterator temp(*this); --pos; return temp; }

		iterator& operator +=(difference_type d) { pos += d; return *this; }
		iterator& operator -=(difference_type d) { pos -= d; return *this; }

		friend iterator operator + (const iterator& i, difference_type n) { iterator temp(i); i += n; return temp; }
		friend iterator operator + (difference_type n, const iterator& i) { iterator temp(i); i += n; return temp; }
		friend iterator operator - (const iterator& i, difference_type n) { iterator temp(i); i -= n; return temp; }
		friend iterator operator - (difference_type n, const iterator& i) { iterator temp(i); i -= n; return temp; }

		reference operator [](difference_type n) const { return *(*this + n); }

		reference operator *() const { return reference(arr.handle(), pos); }
		reference operator ->() const { return reference(arr.handle(), pos); }

		friend bool operator == (const iterator& a, const iterator& b) { return a.pos == b.pos; }
		friend bool operator != (const iterator& a, const iterator& b) { return a.pos != b.pos; }
		friend bool operator >  (const iterator& a, const iterator& b) { return a.pos >  b.pos; }
		friend bool operator >= (const iterator& a, const iterator& b) { return a.pos >= b.pos; }
		friend bool operator <  (const iterator& a, const iterator& b) { return a.pos < b.pos; }
		friend bool operator <= (const iterator& a, const iterator& b) { return a.pos <= b.pos; }

		friend void swap(iterator& a, iterator& b)
		{
			using std::swap;
			swap(a.arr, b.arr);
			swap(a.pos, b.pos);
		}

	private:

		friend array;

		iterator(typename array::handle_type arr, jsize pos) : arr(arr), pos(pos) {}

		array arr;
		jsize pos;

	};

	class const_reference
	{
	public:

		// We rely on C++17 guaranteed copy elision.
		// The same could be done in C++11 with Copy-List-Initialization (return {handle, size}).

		const_reference() = delete;
		const_reference(const const_reference&) = delete;
		const_reference(const_reference&&) = delete;

		void operator &() = delete;

		operator ref<T>() const { return get(); }
		ref<T> get() const { return arr.get_element(pos); }
		ref<T> operator ->() const { return get(); }

	private:

		friend array;
		friend class const_iterator;

		const_reference(typename array::handle_type arr, jsize pos) : arr(arr), pos(pos) {}

		array arr;
		jsize pos;

	};

	class const_iterator
	{
	public:

		using difference_type = jsize;
		using value_type = ref<T>;
		using pointer = void;
		using reference = array::const_reference;
		using iterator_category = std::random_access_iterator_tag;

		const_iterator() : pos(0) {}
		const_iterator(const const_iterator&) = default;
		const_iterator& operator =(const const_iterator&) = default;

		const_iterator& operator ++() { ++pos; return *this; }
		const_iterator& operator --() { --pos; return *this; }

		const_iterator operator ++(int) { const_iterator temp(*this); ++pos; return temp; }
		const_iterator operator --(int) { const_iterator temp(*this); --pos; return temp; }

		const_iterator& operator +=(difference_type d) { pos += d; return *this; }
		const_iterator& operator -=(difference_type d) { pos -= d; return *this; }

		friend const_iterator operator + (const const_iterator& i, difference_type n) { const_iterator temp(i); i += n; return temp; }
		friend const_iterator operator + (difference_type n, const const_iterator& i) { const_iterator temp(i); i += n; return temp; }
		friend const_iterator operator - (const const_iterator& i, difference_type n) { const_iterator temp(i); i -= n; return temp; }
		friend const_iterator operator - (difference_type n, const const_iterator& i) { const_iterator temp(i); i -= n; return temp; }

		reference operator [](difference_type n) const { return *(*this + n); }

		reference operator *() const { return reference(arr.handle(), pos); }
		reference operator ->() const { return reference(arr.handle(), pos); }

		friend bool operator == (const const_iterator& a, const const_iterator& b) { return a.pos == b.pos; }
		friend bool operator != (const const_iterator& a, const const_iterator& b) { return a.pos != b.pos; }
		friend bool operator >  (const const_iterator& a, const const_iterator& b) { return a.pos > b.pos; }
		friend bool operator >= (const const_iterator& a, const const_iterator& b) { return a.pos >= b.pos; }
		friend bool operator <  (const const_iterator& a, const const_iterator& b) { return a.pos < b.pos; }
		friend bool operator <= (const const_iterator& a, const const_iterator& b) { return a.pos <= b.pos; }

		friend void swap(const_iterator& a, const_iterator& b)
		{
			using std::swap;
			swap(a.arr, b.arr);
			swap(a.pos, b.pos);
		}

	private:

		friend array;

		const_iterator(typename array::handle_type arr, jsize pos) : arr(arr), pos(pos) {}

		array arr;
		jsize pos;

	};

	bool empty() const { return this->size() == 0; }

	iterator begin() { return iterator(this->handle(), 0); }
	const_iterator begin() const { return const_iterator(this->handle(), 0); }
	const_iterator cbegin() const { return begin(); }

	iterator end() { return iterator(this->handle(), this->size()); }
	const_iterator end() const { return const_iterator(this->handle(), this->size()); }
	const_iterator cend() const { return end(); }

	reverse_iterator rbegin() { return reverse_iterator(end()); }
	const_reverse_iterator rbegin() const { return const_reverse_iterator(end());	}
	const_reverse_iterator crbegin() const { return rbegin(); }

	reverse_iterator rend() { return reverse_iterator(begin()); }
	const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }
	const_reverse_iterator crend() const { return rend(); }

	reference operator[](size_type pos) { return reference(this->handle(), pos); }
	const_reference operator[](size_type pos) const { return const_reference(this->handle(), pos); }

	reference at(size_type pos)
	{
		if (pos >= this->size())
			throw std::out_of_range("array_elements");

		return (*this)[pos];
	}

	const_reference at(size_type pos) const
	{
		if (pos >= this->size())
			throw std::out_of_range("array_elements");

		return (*this)[pos];
	}

	static ref<array> new_(jsize len, ref<element_type> init = {}) { return detail::api::new_array<element_type>(len, init); }

	// for consistency with primitive array

	array& elements() { return *this; }
	const array& elements() const { return *this; }

protected:

	array(typename base::handle_type h) : base(h) {}

private:

	ref<T> get_element(jsize index) const { return detail::api::get_array_element<element_type>(ref<T[]>(this->handle()), index); }
	void set_element(jsize index, ref<T> value) { detail::api::set_array_element<element_type>(ref<T[]>(this->handle()), index, value); }

};

// primitive array

template <typename T, lock Lock, release_mode Mode>
class array_elements
{
public:

	typedef T value_type;
	typedef jsize size_type;
	typedef jsize difference_type;
	typedef T* pointer;
	typedef const T* const_pointer;
	typedef T& reference;
	typedef const T& const_reference;
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef std::reverse_iterator<iterator> reverse_iterator;
	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

	~array_elements()
	{
		if (data_)
			detail::api::release_array_elements<T, Lock>(ref<T[]>(array_), data_, static_cast<jint>(Mode));
	}

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
			throw std::out_of_range("array_elements");

		return (*this)[pos];
	}

	const_reference at(size_type pos) const
	{
		if (pos >= size())
			throw std::out_of_range("array_elements");

		return (*this)[pos];
	}

	jboolean is_copy() const
	{
		return is_copy_;
	}

	void commit()
	{
		detail::api::release_array_elements<T, Lock>(ref<T[]>(array_), data_, JNI_COMMIT);
	}

	// After a call to release() or abort() object is in a valid but unspecified state:
	// only functions without preconditions are safe to call (like an assignment operator or destructor).

	void release()
	{
		if (data_)
		{
			detail::api::release_array_elements<T, Lock>(ref<T[]>(array_), data_, 0);
			data_ = 0;
		}
	}

	void abort() const
	{
		if (data_)
		{
			detail::api::release_array_elements<T, Lock>(ref<T[]>(array_), data_, JNI_ABORT);
			data_ = 0;
		}
	}

private:

	friend class array<T>;

	using handle_type = typename array_base<T>::handle_type;

	array_elements(handle_type array, jsize size) : array_(array), data_(detail::api::get_array_elements<T, Lock>(ref<T[]>(array_), &is_copy_)), size_(size) {}

	// We rely on C++17 guaranteed copy elision.
	// The same could be done in C++11 with Copy-List-Initialization (return {handle, size}).

	array_elements(const array_elements&) = delete;
	array_elements& operator=(const array_elements&) = delete;

	array_elements(array_elements&&) = delete;
	array_elements& operator=(array_elements&&) = delete;

private:

	handle_type array_;
	jboolean is_copy_;
	pointer data_;
	size_type size_;

};

template <typename T>
class array<T, std::enable_if_t<is_primitive_v<T>>> : public array_base<T>
{
	using base = array_base<T>;

public:

	static ref<array> new_(jsize len) { return detail::api::new_array<T>(len); }

	template <lock Lock = lock::noncritical, release_mode Mode = release_mode::copy>
	array_elements<T, Lock, Mode> elements() { return array_elements<T, Lock, Mode>(this->handle(), this->size()); }

	template <lock Lock = lock::noncritical, release_mode Mode = release_mode::copy>
	array_elements<T, Lock, Mode> elements(jsize size) { return array_elements<T, Lock, Mode>(this->handle(), size); }

	template <lock Lock = lock::noncritical>
	const array_elements<T, Lock, release_mode::abort> elements() const { return array_elements<T, Lock, release_mode::abort>(this->handle(), this->size()); }

	template <lock Lock = lock::noncritical>
	const array_elements<T, Lock, release_mode::abort> elements(jsize size) const { return array_elements<T, Lock, release_mode::abort>(this->handle(), size); }

	template <lock Lock = lock::noncritical>
	const array_elements<T, Lock, release_mode::abort> const_elements() const { return array_elements<T, Lock, release_mode::abort>(this->handle(), this->size()); }

	template <lock Lock = lock::noncritical>
	const array_elements<T, Lock, release_mode::abort> const_elements(jsize size) const { return array_elements<T, Lock, release_mode::abort>(this->handle(), size); }

	void get_region(jsize start, jsize len, T* buf) const { detail::api::get_array_region(ref<T[]>(this->handle()), start, len, buf); }
	void set_region(jsize start, jsize len, const T* buf) { detail::api::set_array_region(ref<T[]>(this->handle()), start, len, buf); }

protected:

	array(typename base::handle_type h) : base(h) {}

};

} // namespace scapix::link::java

#endif // SCAPIX_LINK_JAVA_ARRAY_H
