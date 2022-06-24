#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iterator>
#include "utility.hpp"

namespace ft
{

/* #iterator_traits */
template <class Iter>
struct iterator_traits
{
	typedef typename Iter::value_type			value_type;
	typedef typename Iter::difference_type		difference_type;
	typedef typename Iter::pointer				pointer;
	typedef typename Iter::const_pointer		const_pointer;
	typedef typename Iter::reference			reference;
	typedef typename Iter::const_reference		const_reference;
	typedef typename Iter::iterator_category	iterator_category;
};

template <typename T>
struct iterator_traits<T*>
{
	typedef T									value_type;
	typedef T*									pointer;
	typedef const T*							const_pointer;
	typedef T&									reference;
	typedef const T&							const_reference;
	typedef ptrdiff_t							difference_type;
	typedef std::random_access_iterator_tag		iterator_category;
};
/* #iterator_traits */

/* #reverse_iterator */
template <class T>
class reverse_iterator : public iterator_traits<T>
{
	protected:
	T	_current;
	public:
	typedef T												iterator_type;
	typedef typename iterator_traits<T>::difference_type	difference_type;
	typedef typename iterator_traits<T>::value_type			value_type;
	typedef typename iterator_traits<T>::reference			reference;
	typedef typename iterator_traits<T>::const_reference	const_reference;
	typedef typename iterator_traits<T>::pointer			pointer;
	typedef typename iterator_traits<T>::const_pointer		const_pointer;
	typedef typename iterator_traits<T>::iterator_category	iterator_category;
	reverse_iterator(iterator_type it = _nullptr) : _current(it) { };
	~reverse_iterator() { };
	template <typename Iter>
	reverse_iterator(const reverse_iterator<Iter> & x) : _current(x.base()) { }
	reverse_iterator& operator=(const reverse_iterator &x) { _current = x._current; return *this; }
	iterator_type base() const { return _current; }
	reference operator*() { return *_current; }
	pointer operator->() { return &(operator*()); }
	reverse_iterator& operator++() { --_current; return *this; }
	reverse_iterator operator++(int) { reverse_iterator tmp(*this); _current--; return tmp; }
	reverse_iterator& operator--() { ++_current; return *this; }
	reverse_iterator operator--(int) { reverse_iterator tmp(*this); _current++; return tmp; }
	reverse_iterator operator+(difference_type n) const { return reverse_iterator(_current - n); }
	reverse_iterator& operator+=(difference_type n) { _current -= n; return *this; }
	reverse_iterator operator-(difference_type n) const { return reverse_iterator(_current + n); }
	reverse_iterator& operator-=(difference_type n) { _current += n; return *this; }
	reference operator[](difference_type n) const { return *(*this + n); }
	bool operator==(reverse_iterator const &x) const { return _current == x._current; };
	bool operator!=(reverse_iterator const &x) const { return _current != x._current; };
	bool operator<(reverse_iterator const &x) const { return _current < x._current; };
	bool operator>(reverse_iterator const &x) const { return _current > x._current; };
	bool operator<=(reverse_iterator const &x) const { return _current <= x._current; };
	bool operator>=(reverse_iterator const &x) const { return _current >= x._current; };
};
template<typename Iterator>
reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n,
										const reverse_iterator<Iterator>& rev_it)
{
	return reverse_iterator<Iterator>(rev_it.base() - n);
}
template<typename Iterator>
typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& lhs,
																const reverse_iterator<Iterator>& rhs)
{
	return ( rhs.base() - lhs.base() );
}
template<typename Iterator1, typename Iterator2>
bool operator==(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
{
	return ( lhs.base() == rhs.base() );
}
template<typename Iterator1, typename Iterator2>
bool operator!=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
{
	return ( lhs.base() != rhs.base() );
}
template<typename Iterator1, typename Iterator2>
bool operator<(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
{
	return ( lhs.base() > rhs.base() );
}
template<typename Iterator1, typename Iterator2>
bool operator<=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
{
	return ( lhs.base() >= rhs.base() );
}
template<typename Iterator1, typename Iterator2>
bool operator>(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
{
	return ( lhs.base() < rhs.base() );
}
template<typename Iterator1, typename Iterator2>
bool operator>=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
{
	return ( lhs.base() <= rhs.base() );
}
/* reverse_iterator */

/* #random_access_iterator */
template <typename Iterator>
class random_access_iterator : public iterator_traits<Iterator>
{
	protected:
	Iterator _current;
	public:
	typedef typename iterator_traits<Iterator>::difference_type		diffrence_type;
	typedef typename iterator_traits<Iterator>::reference			reference;
	typedef typename iterator_traits<Iterator>::pointer				pointer;
	typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
	typedef typename iterator_traits<Iterator>::value_type			value_type;
	random_access_iterator() : _current() { }
	random_access_iterator(Iterator it) : _current(it) { }
	template <typename Iter>
	random_access_iterator(const random_access_iterator<Iter> & it )
	: _current(it.base()) { }
	Iterator base() const { return _current; }
	reference operator*() { return *_current; }
	pointer operator->() { return &(operator*()); }
	random_access_iterator& operator ++() { ++_current; return *this; }
	random_access_iterator operator ++(int) { return random_access_iterator(_current++); }
	random_access_iterator& operator--() { --_current; return *this; }
	random_access_iterator operator--(int) { return random_access_iterator(_current--); }
	reference operator[](const diffrence_type & n) const { return *(_current + n); }
	random_access_iterator& operator+=(const diffrence_type & n) { _current += n; return *this; }
	random_access_iterator operator+(const diffrence_type & n) const { return random_access_iterator(_current + n); }
	random_access_iterator& operator-=(const diffrence_type & n){ _current -= n; return *this; }
	random_access_iterator operator-(const diffrence_type & n) const { return random_access_iterator(_current - n); }
	diffrence_type operator-(const random_access_iterator & x) const { return _current - x._current; }
};
template<typename IteratorL, typename IteratorR>
bool operator == (const random_access_iterator<IteratorL> & lhs,
					const random_access_iterator<IteratorR> & rhs)
{
	return lhs.base() == rhs.base();
}
template<typename IteratorL, typename IteratorR>
bool operator != (const random_access_iterator<IteratorL> & lhs,
					const random_access_iterator<IteratorR> & rhs)
{
	return !(lhs == rhs);
}
template<typename IteratorL, typename IteratorR>
bool operator < (const random_access_iterator<IteratorL>& lhs,
					const random_access_iterator<IteratorR>& rhs)
{
	return lhs.base() < rhs.base();
}
template<typename IteratorL, typename IteratorR>
bool operator > (const random_access_iterator<IteratorL> & lhs,
				const random_access_iterator<IteratorR> & rhs)
{
	return rhs < lhs;
}
template<typename IteratorL, typename IteratorR>
bool operator <= (const random_access_iterator<IteratorL> & lhs,
					const random_access_iterator<IteratorR> & rhs)
{
	return !(rhs < lhs);
}
template<typename IteratorL, typename IteratorR>
bool operator >= (const random_access_iterator<IteratorL> & lhs,
					const random_access_iterator<IteratorR> & rhs)
{
	return !(lhs < rhs);
}
template<typename Iterator>
random_access_iterator<Iterator> operator+
(typename random_access_iterator<Iterator>::difference_type n,
const random_access_iterator<Iterator>& it)
{
	return random_access_iterator<Iterator>(it.base() - n);
}
template<typename IteratorL, typename IteratorR>
typename ft::random_access_iterator<IteratorL>::difference_type
operator-(const ft::random_access_iterator<IteratorL> lhs,
			const ft::random_access_iterator<IteratorR> rhs)
{
	return (lhs.base() - rhs.base());
}
/* random_access_iterator */

/* #node_iterator */
template <typename T, typename Pair>
class node_iterator
{
	protected:
	T	_current;

	private:
	void _next()
	{
		if (_current->_nil && _current->_begin != _current)
		{
			_current = _current->_begin;
		}
		else if (!_current->_right->_nil)
		{
			_current = _current->_right;
			while (!_current->_left->_nil)
			{
				_current = _current->_left;
			}
		}
		else
		{
			T old = _current;
			T tmp = _current;
			_current = _current->_parent;
			if (!_current)
			{
				_current = old->_right;
				return ;
			}
			while (_current->_left != tmp)
			{
				if (!_current->_parent)
				{
					_current = old->_right;
					break;
				}
				tmp = _current;
				_current = _current->_parent;
			}
		}
	}
	void _prev()
	{
		if (_current->_nil)
		{
			_current = _current->_parent;
		}
		else if (!_current->_left->_nil)
		{
			_current = _current->_left;
			while (!_current->_right->_nil)
			{
				_current = _current->_right;
			}
		}
		else
		{
			T old = _current;
			T tmp = _current;
			_current = _current->_parent;
			while (_current->_right != tmp)
			{
				tmp = _current;
				if (!_current->_parent)
				{
					_current = old->_left;
					break;
				}
				_current = _current->_parent;
			}
		}
	}

	public:
	typedef T				iterator_type;
	typedef Pair			value_type;
	typedef ptrdiff_t		difference_type;
	typedef Pair&			reference;
	typedef const Pair&		const_reference;
	typedef Pair*			pointer;
	typedef const Pair*		const_pointer;
	typedef typename iterator_traits<iterator_type>::iterator_category	iterator_category;
	node_iterator(T it = _nullptr) : _current(it) { };
	~node_iterator() { };
	template <class I, class P> node_iterator(const node_iterator<I, P>& x)
	: _current(x.base()) { };
	iterator_type base() const { return _current; }
	node_iterator& operator=(const node_iterator &x) { _current = x._current; return *this; }
	node_iterator operator++(int) { node_iterator tmp(*this); _next(); return tmp; }
	node_iterator& operator++() { _next(); return *this; }
	node_iterator operator--(int) { node_iterator tmp(*this); _prev(); return tmp; }
	node_iterator& operator--() { _prev(); return *this; }
	reference operator*() { return *(_current->_data); }
	const_reference operator*() const { return *(_current->_data); }
	pointer operator->() { return _current->_data; }
	const_pointer operator->() const { return _current->_data; }
	bool operator==(node_iterator const &x) const { return _current == x._current; };
	bool operator!=(node_iterator const &x) const { return _current != x._current; };
	bool operator>(node_iterator const &x) const { return _current->_data > x._current->_data; };
	bool operator<(node_iterator const &x) const { return x._current->_data > _current->_data; };
	bool operator<=(node_iterator const &x) const { return _current->_data <= x._current->_data; };
	bool operator>=(node_iterator const &x) const { return _current->_data >= x._current->_data; };
};
/* node iterator */

} /* namespace ft end */

#endif
