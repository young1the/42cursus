#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template<typename T> class Array
{
private :
	int	_len;
	T	*data;
public:

/* occf */
	Array(int len) : _len(len)
	{
		data = new T [_len];
		std::cout << "# constructed new Array" << std::endl;
	}
	Array(const Array & other) : _len(other._len)
	{
		data = new T[_len];
		for (int i = 0; i < _len; ++i)
			data[i] = other.data[i];
		std::cout << "# copy constructed new Array" << std::endl;		
	}
	~Array()
	{
		std::cout << "# destructor called" << std::endl;
		reset();
	}
	Array& operator = (const Array & other)
	{
		if (this == &other)
			return *this;
		reset();
		_len = other._len;
		data = new T[_len];
		for (int i = 0; i < _len; ++i)
			data[i] = other.data[i];
		std::cout << "# copied Array" << std::endl;
		return *this;
	}
/* occf end */

	T & operator[] (int i)
	{
		if (i >= _len || i < 0)
			throw OutOfArrayException();
		return data[i];
	}

	void reset()
	{
		delete [] data;
		data = NULL;
		std::cout << "# delete Array's data" << std::endl;
	}

	class OutOfArrayException : public std::exception
	{
		public:
			const char * what() const throw()
			{
				return "Out Of Array";
			}
	};

};

#endif