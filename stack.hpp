#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft
{

template <typename T, typename Container = ft::vector<T> >
class stack
{
	public:
	typedef Container									container_type;
	typedef typename container_type::size_type			size_type;
	typedef typename container_type::value_type			value_type;
	typedef typename container_type::reference			reference;
	typedef typename container_type::const_reference	const_reference;

	protected:
	container_type c;

	public :
	stack() : c() { }
	stack(container_type con) : c(con){}
	stack(const_reference x) : c(x.c){}
	reference operator = (const_reference x)
	{
		c = x.c;
		return *this;
	}

	bool empty() const { return c.empty(); }

	size_type size() const { return c.size(); }

	reference top() { return c.back(); }

	const_reference top() const { return c.back(); }

	void push(const_reference val) { c.push_back(val); }

	void pop() { c.pop_back(); }

	template<typename T1, typename Container1>
	friend bool operator == (const stack<T1, Container1> & x,
							const stack<T1, Container1> & y);

	template<typename T1, typename Container1>
	friend bool operator <(const stack<T1, Container1> & x,
							const stack<T1, Container1> & y);
};

template<class T, class Container>
bool operator == (const stack<T, Container> & x,
				const stack<T, Container> & y)
{
	return x.c == y.c;
}

template<class T, class Container>
bool operator!= (const stack<T, Container> & x,
				const stack<T, Container> & y)
{
	return !( x == y );
}

template<class T, class Container>
bool operator<(const stack<T, Container> & x,
				const stack<T, Container> & y)
{
	return x.c < y.c;
}

template<class T, class Container>
bool operator <= (const stack<T, Container> & x,
				const stack<T, Container> & y)
{
	return !(x > y);
}

template<class T, class Container>
bool operator > (const stack<T, Container> & x,
				const stack<T, Container> & y)
{
	return y < x;
}

template<class T, class Container>
bool operator >= (const stack<T, Container> & x,
				const stack<T, Container> & y)
{
	return !(x < y);
}

} /* namespace ft end */

#endif
