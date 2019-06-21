/*
	scapix/link/java/array.h

	Copyright (c) 2019 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_ARRAY_H
#define SCAPIX_LINK_JAVA_ARRAY_H

#include <stdexcept>
#include <scapix/link/java/object.h>
#include <scapix/link/java/ref.h>
#include <scapix/link/java/lock.h>
#include <scapix/link/java/signature.h>
#include <scapix/link/java/detail/env.h>
#include <scapix/link/java/detail/api/type.h>
#include <scapix/link/java/detail/api/array.h>

namespace scapix {
namespace link {
namespace java {

//template <typename T>
//using array = object_type<signature_t<T[]>>;

// fix: already declared in ref.h

//template <typename T, typename = void>
//class array;

template <typename T>
class array_base : public object<signature_t<T[]>, handle_type_t<T[]>>
{
	using base = object<signature_t<T[]>, handle_type_t<T[]>>;

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

	typedef ref<T> value_type;
	typedef typename ref<T>::element_type element_type; // fix names (T could be ClassName)
	typedef jsize size_type;
	typedef jsize difference_type;
	//	typedef value_type* pointer;
	//	typedef const value_type* const_pointer;
	//	typedef value_type& reference;
	//	typedef const value_type& const_reference;
	//	typedef value_type* iterator;
	//	typedef const value_type* const_iterator;
	//	typedef std::reverse_iterator<iterator> reverse_iterator;
	//	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

	class reference
	{
	public:

		// We rely on C++17 guaranteed copy elision.
		// The same could be done in C++11 with Copy-List-Initialization (return {handle, size}).

		reference(const reference&) = delete;
		reference(reference&&) = delete;

		reference& operator = (const reference& other) = delete;
		reference& operator = (reference&& other) { arr.set_element(pos, std::move(other).get()); return *this; }

		void operator&() = delete;

		template <typename Y>
		reference& operator=(ref<Y> value) { arr.set_element(pos, value); return *this; }

		operator ref<T>() const { return arr.get_element(pos); }
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

		iterator(const iterator&) = default;

		iterator& operator ++() { pos++; return *this; }
		reference operator *() { return reference(arr.handle(), pos); }
		ref<T> operator ->() { return reference(arr.handle(), pos); }

		bool operator == (const iterator& other) const { return pos == other.pos; }
		bool operator != (const iterator& other) const { return pos != other.pos; }

	private:

		friend array;

		iterator(typename array::handle_type arr, jsize pos) : arr(arr), pos(pos) {}

		array arr;
		jsize pos;

	};

	class const_reference
	{
	public:

		const_reference(const const_reference&) = default;

		void operator&() = delete;

		operator ref<T>() const { return arr.get_element(pos); }

	private:

		const_reference(typename array::handle_type arr, jsize pos) : arr(arr), pos(pos) {}

		array arr;
		jsize pos;

	};

	bool empty() const { return this->size() == 0; }

	iterator begin() { return iterator(this->handle(),  0); }
	//const_iterator begin() const { return data(); }
	//const_iterator cbegin() const { return data(); }

	iterator end() { return iterator(this->handle(),  this->size()); }
	//const_iterator end() const { return data() + size(); }
	//const_iterator cend() const { return data() + size(); }

	//reverse_iterator rbegin() { return data() + size();	}
	//const_reverse_iterator rbegin() const { return data() + size();	}
	//const_reverse_iterator crbegin() const { return data() + size(); }

	//reverse_iterator rend() { return data(); }
	//const_reverse_iterator rend() const { return data(); }
	//const_reverse_iterator crend() const { return data(); }

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

template <typename T, lock Lock>
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
		release();
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

	void commit() const
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

	void abort()
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

	template <lock Lock = lock::noncritical>
	array_elements<T, Lock> elements() { return array_elements<T, Lock>(this->handle(), this->size()); }

	template <lock Lock = lock::noncritical>
	array_elements<T, Lock> elements(jsize size) { return array_elements<T, Lock>(this->handle(), size); }

	// to do: const versions (const array_elements isn't movable, add const_array_elements?)
	// const array<jint> vs array<const jint> vs const_array<jint>?
	// to do: const_elements should always call abort().

	template <lock Lock = lock::noncritical>
	const array_elements<T, Lock> elements() const { return array_elements<T, Lock>(this->handle(), this->size()); }

	template <lock Lock = lock::noncritical>
	const array_elements<T, Lock> elements(jsize size) const { return array_elements<T, Lock>(this->handle(), size); }

	template <lock Lock = lock::noncritical>
	const array_elements<T, Lock> const_elements() const { return array_elements<T, Lock>(this->handle(), this->size()); }

	template <lock Lock = lock::noncritical>
	const array_elements<T, Lock> const_elements(jsize size) const { return array_elements<T, Lock>(this->handle(), size); }

	void get_region(jsize start, jsize len, T* buf) { detail::api::get_array_region(ref<T[]>(this->handle()), start, len, buf); }
	void set_region(jsize start, jsize len, const T* buf) { detail::api::set_array_region(ref<T[]>(this->handle()), start, len, buf); }

protected:

	array(typename base::handle_type h) : base(h) {}

};

// to do: array<"Ljava/lang/Object;"> and array<'I'> is wrong

template <char... Chars>
class object<meta::string<'[', Chars...>> : public array<meta::string<Chars...>>
{
	using array<meta::string<Chars...>>::array;
};
    
} // namespace java
} // namespace link
} // namespace scapix

#endif // SCAPIX_LINK_JAVA_ARRAY_H
