#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <exception>
#include <algorithm>
#include <iterator>
#include "utility.hpp"
#include "iterator.hpp"

namespace ft
{

template < typename T, typename Allocator = std::allocator<T> >
class vector
{
	public:
	typedef Allocator									allocator_type;
	typedef T											value_type;
	typedef typename allocator_type::size_type			size_type;
	typedef typename allocator_type::difference_type	difference_type;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer		const_pointer;
	typedef value_type&									reference;
	typedef const value_type&							const_reference;
	typedef ft::random_access_iterator<pointer>			iterator;
	typedef ft::random_access_iterator<const_pointer>	const_iterator;
	typedef ft::reverse_iterator<iterator>				reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

	private:
	allocator_type		_allocator;
	pointer				_data;
	size_type			_size;
	size_type			_capacity;

	pointer _allocate(size_type n)
	{
		return _allocator.allocate(n);
	}

	void _deallocate(pointer p, size_type n)
	{
		if (p)
			_allocator.deallocate(p, n);
	}

	void _construct(pointer ptr, const_reference val)
	{
		_allocator.construct(ptr, val);
	}

	void _destroy(pointer p)
	{
		if (p)
			_allocator.destroy(p);
	}

	void _checkRange(size_type __n) const
	{
		if (__n >= this->size())
			throw std::out_of_range("vector");
	}

	void _setVector(pointer data_new, size_type size_new, size_type capacity_new)
	{
		_data = data_new;
		_size = size_new;
		_capacity = capacity_new;
	}

	void _fillData(pointer ptr, value_type value, size_type n)
	{
		for (size_type i = 0; i != n; ++i)
		{
			_construct(ptr + i, value);
		}
	}

	template <class InputIterator>
	void _fillData(pointer ptr, InputIterator start,
	typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type finish)
	{
		for (difference_type i = 0; start != finish; ++start,++i)
		{
			_construct(ptr + i, *(start));
		}
	}

	void _removeData(iterator begin, iterator end)
	{
		for (iterator it = begin; it != end; ++it)
		{
			_destroy(it.base());
		}
	}

	void _clearVector()
	{
		_removeData(begin(), end());
		_deallocate(_data, _capacity);
		_setVector(NULL, 0, 0);
	}

	template<class Iterator>
	bool _validate_insert_size(Iterator first, Iterator last, size_t range)
	{
		pointer tmp_buf = _allocate(range);
		bool res = true;
		size_t i = 0;
		for (;first != last; ++first, ++i)
		{
			try
			{
				tmp_buf[i] = *first;
			}
			catch (...)
			{
				res = false;
				break;
			}
		}
		_deallocate(tmp_buf, range);
		return res;
	}

	public:
	vector(const allocator_type & allocator_in = allocator_type())
	: _allocator(allocator_in), _data(NULL) ,_size(0), _capacity(0) { }

	vector(size_t n, const value_type & value_in = value_type(),
					const allocator_type& allocator_in = allocator_type())
	: _allocator(allocator_in), _data(_allocate(n)), _size(n), _capacity(n)
	{
		_fillData(_data, value_in, n);
	}

	template <class InputIterator>
	vector(InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last,
	const allocator_type & allocator_in = allocator_type()) : _allocator(allocator_in)
	{
		difference_type distance = std::distance(first, last);
		size_type size_new = distance;
		_setVector(_allocate(size_new), size_new, size_new);
		_fillData(_data, first, last);
	}

	vector(const vector & x) : _allocator(x._allocator)
	{
		_data = _allocate(x._capacity);
		_fillData(_data, x.begin(), x.end());
		_setVector(_data, x._size, x._capacity);
	}

	vector& operator=(const vector & x)
	{
		if (this != &x)
		{
			if (this->_data != NULL)
			{
				_clearVector();
			}
			_setVector(_allocate(x._capacity), x._size, x._capacity);
			_fillData(this->_data, x.begin(), x.end());
		}
		return *this;
	}

	~vector()
	{
		_clearVector();
	}

	template <class InputIterator>
	void assign(InputIterator first, InputIterator last,
	typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
	{
		difference_type distance = std::distance(first, last);
		size_type size_new = size_type(distance);
		if (size_new > capacity())
		{
			_clearVector();
			_setVector(_allocate(size_new), size_new, size_new);
		}
		else
		{
			_removeData(begin(), end());
			_size = size_new;
		}
		_fillData(_data, first, last);
	}

	void assign(size_type n, const value_type& val)
	{
		if (n > capacity())
		{
			_clearVector();
			_setVector(_allocate(n), n, n);
		}
		else
		{
			_removeData(begin(), end());
			_size = n;
		}
		_fillData(_data, val, n);
	}

	allocator_type get_allocator() const { return _allocator; }
	reference operator [] ( size_type n ) { return *(_data + n); }
	const_reference operator [] ( size_type n ) const { return *(_data + n); }

	reference at(size_type n)
	{
		_checkRange(n);
		return (*this)[n];
	}

	const_reference at(size_type n) const
	{
		_checkRange(n);
		return (*this)[n];
	}

	reference front() { return *(begin()); }
	const_reference front() const { return *(begin()); }
	reference back() { return *(end() - 1); }
	const_reference back() const { return *(end() - 1); }
	pointer data() { return _data; }
	const_pointer data() const { return _data; }
	iterator begin() { return iterator(_data); }
	const_iterator begin() const { return iterator(_data); }
	iterator end() { return begin() + _size; }
	const_iterator end() const { return begin() + _size; }
	reverse_iterator rbegin() { return reverse_iterator(--end()); }
	const_reverse_iterator rbegin() const { return const_reverse_iterator(--end()); }
	reverse_iterator rend() { return reverse_iterator(begin()); }
	const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }
	bool empty() const { return (begin() == end()); }
	size_type size() const { return size_type(end() - begin()); }
	size_type max_size() const { return _allocator.max_size(); }

	void reserve(size_type n)
	{
		if (n > max_size())
			throw std::length_error("vector");
		if (n > _capacity)
		{
			pointer tmp = _allocate(n);
			size_type old_size = _size;
			_fillData(tmp, begin(), end());
			_clearVector();
			_setVector(tmp, old_size, n);
		}
	}

	size_type capacity() const { return _capacity; }

	void clear() { erase(begin(), end()); }


	iterator insert( iterator position, const value_type & val )
	{
		size_type index = position - this->begin();
		if (this->_size == this->_capacity)
		{
			reserve(this->_capacity ? this->_capacity * 2 : 1);
		}
		for (size_type i = this->_size; i > index; --i)
		{
			_construct(&(*this->begin()) + i, *(begin() + i - 1));
		}
		this->_construct(&(*this->begin()) + index, val);
		this->_size++;
		return this->begin() + index;
	}

	void insert( iterator position, size_type n, const value_type & val )
	{
		if (n)
		{
			size_type index = position - this->begin();
			if (this->_size + n > this->_capacity)
				reserve(_size + n);
			_fillData(this->begin().base(),val,n);
			_size += n;
		}
	}

	template<class InputIterator>
	void insert( iterator position, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first,
				InputIterator last )
	{
		size_type index = position - this->begin();
		size_type n = std::distance(first, last);
		if (!this->_validate_insert_size(first, last, n))
		{
			throw std::out_of_range("vector");
		}
		if (this->_size + n > this->_capacity)
		{
			size_type capacity_new;
			if (_capacity * 2 > _size + n)
			{
				capacity_new = _capacity * 2;
			}
			else
			{
				capacity_new = _size + n;
			}
			reserve(capacity_new);
		}
		for (size_type i = this->_size; i > index; i--)
		{
			this->_construct(&(*this->begin()) + i + n - 1, *(begin() + i - 1));
		}
		_fillData(_data + index, first, last);
		this->_size += n;
	}

	iterator erase(iterator position)
	{
		if (position + 1 != end())
		{
			std::copy(position + 1, end(), position);
		}
		--_size;
		_destroy(end().base());
		return position;
	}

	iterator erase(iterator first, iterator last)
	{
		iterator it = std::copy(last, end(), first);
		_removeData(it, end());
		_size -= std::distance(first, last);
		return first;
	}

	void push_back( const value_type & val )
	{
		if (_capacity == _size)
			reserve(_capacity ? _capacity * 2 : 1);
		_construct(end().base(),val);
		_size++;
	}

	void pop_back()
	{
		if (empty())
			return ;
		--_size;
		_destroy(end().base());
	}

	void resize (size_type n, value_type val = value_type())
	{
		if (n == this->_size)
			return;
		if (n > this->_capacity)
		{
			this->_capacity == 0 ? reserve(n) : reserve(this->_capacity * 2);
		}
		if (n < this->_size)
		{
			this->_removeData(this->begin() + n, this->end());
		}
		else
		{
			this->_fillData(this->begin().base()+ this->_size, val,(n - this->_size));
		}
		this->_size = n;
	}

	void swap(vector& other)
	{
		pointer data_tmp = _data;
		size_type size_tmp = _size;
		size_type capacity_tmp = _capacity;

		_setVector(other._data, other._size, other._capacity);
		other._setVector(data_tmp, size_tmp, capacity_tmp);
	}

}; // class vector end

template <class T, class Alloc>
bool operator == (const vector<T, Alloc>& x, const vector<T, Alloc>& y)
{
	return (x.size() == y.size() &&
			ft::equal(x.begin(), x.end(), y.begin()));
}

template <class T, class Alloc>
bool operator<(const vector<T, Alloc>& x, const vector<T, Alloc>& y)
{
	return ft::lexicographical_compare(x.begin(), x.end(),
										y.begin(), y.end());
}

template <class T, class Alloc>
void swap(vector<T, Alloc>& x, vector<T, Alloc>& y)
{
	x.swap(y);
}

template <class T, class Alloc>
bool operator!=(const vector<T, Alloc>& x, const vector<T, Alloc>& y)
{
	return !(x == y);
}

template <class T, class Alloc>
bool operator > (const vector<T, Alloc>& x, const vector<T, Alloc>& y)
{
	return y < x;
}

template <class T, class Alloc>
bool operator <= (const vector<T, Alloc>& x, const vector<T, Alloc>& y)
{
	return !(y < x);
}

template <class T, class Alloc>
bool operator >= (const vector<T, Alloc>& x, const vector<T, Alloc>& y)
{
	return !(x < y);
}

} /* namespace ft end */

#endif
