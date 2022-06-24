#ifndef UTILITY_HPP
#define UTILITY_HPP

namespace ft
{

/* #enable_if */
// template <class T, typename std::enable_if<std::is_integral<T>::value, T>::type* = nullptr>
// template의 첫번째 인자가 ture일 때만, enable_if::type을 가진다.
template <bool, typename T = void>
struct enable_if {};

template <typename T>
struct enable_if<true, T>
{
	typedef T type;
};
/* enable_if */

/* #is_integral! */
template <bool type, typename T>
struct integral_constant
{
	static const bool value = type;
	operator bool() const 
	{ 
		return value; 
	}
};

template <typename T>
struct integral_type : integral_constant<false, T> {};

template <typename T>
struct is_integral : integral_type <T> {};

template <>
struct integral_type<char> : public integral_constant<true, char> {};
template <>
struct integral_type<bool> : public integral_constant<true, bool> {};
template <>
struct integral_type<int> : public integral_constant<true, int> {};
template <>
struct integral_type<char16_t> : public integral_constant<true, char16_t> {};
template <>
struct integral_type<char32_t> : public integral_constant<true, char32_t> {};
template <>
struct integral_type<wchar_t> : public integral_constant<true, wchar_t> {};
template <>
struct integral_type<signed char> : public integral_constant<true, signed char> {};
template <>
struct integral_type<short int> : public integral_constant<true, short int> {};
template <>
struct integral_type<long int> : public integral_constant<true, long int> {};
template <>
struct integral_type<long long int> : public integral_constant<true, long long int> {};
template <>
struct integral_type<unsigned char> : public integral_constant<true, unsigned char> {};
template <>
struct integral_type<unsigned short int> : public integral_constant<true, unsigned short int> {};
template <>
struct integral_type<unsigned int> : public integral_constant<true, unsigned int> {};
template <>
struct integral_type<unsigned long int> : public integral_constant<true, unsigned long int> {};
template <>
struct integral_type<unsigned long long int> : public integral_constant<true, unsigned long long int> {};
/* is_integral */

/* #equal */
template <typename Iterator1, typename Iterator2>
bool equal(Iterator1 first1, Iterator1 last1,
			Iterator2 first2)
{
	while (first1 != last1)
	{
		if (!(*first1 == *first2))
			return false;
		++first1;
		++first2;
	}
	return true;
}

template <typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
bool equal (InputIterator1 first1, InputIterator1 last1,
			InputIterator2 first2, BinaryPredicate pred)
{
	while (first1 != last1)
	{
		if (!pred(*first1,*first2))
			return false;
		++first1;
		++first2;
	}
	return true;
}
/* equal */

/* #lexicographical_compare */
template <class InputIterator1, class InputIterator2>
bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
							InputIterator2 first2, InputIterator2 last2)
{
	while (first1 != last1)
	{
		if (first2 == last2 || *first2 < *first1)
			return false;
		else if (*first1 < *first2)
			return true;
		++first1;
		++first2;
	}
	return (first2 != last2);
}

template <class InputIterator1, class InputIterator2, class Compare>
bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
								InputIterator2 first2, InputIterator2 last2,
								Compare comp)
{
	while (first1 != last1)
	{
		if (first2 == last2 || comp(*first2, *first1))
			return false;
		else if (comp(*first2, *first1))
			return true;
		++first1;
		++first2;
	}
	return (first2 != last2);
}
/* lexicographical_compare */

/* #pair */
template<typename T1, typename T2>
struct pair
{
	typedef T1	first_type;
	typedef T2	second_type;

	T1			first;
	T2			second;

	pair() : first(), second() { }

	template<typename F, typename S>
	pair(const pair<F, S> & x) : first(x.first), second(x.second) {}

	pair(const first_type & a, const second_type & b) : first(a), second(b) { }

	pair & operator=(const pair & x)
	{
		this->first = x.first;
		this->second = x.second;
		return *this;
	}

}; // class pair end

template<typename T1, typename T2>
bool operator == (const pair<T1, T2> & lhs, const pair<T1, T2> & rhs)
{
	return lhs.first == rhs.first && lhs.second == rhs.second ;
}

template<typename T1, typename T2>
bool operator != (const pair<T1, T2> & lhs, const pair<T1, T2> & rhs)
{
	return !(lhs == rhs);
}

template<typename T1, typename T2>
bool operator < (const pair<T1, T2> & lhs, const pair<T1, T2> & rhs)
{
	return (lhs.first < rhs.first) || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
}

template<typename T1, typename T2>
bool operator <= (const pair<T1, T2> & lhs, const pair<T1, T2> & rhs)
{
	return !(rhs < lhs);
}

template<typename T1, typename T2>
bool operator > (const pair<T1, T2> & lhs, const pair<T1, T2> & rhs)
{
	return rhs < lhs;
}

template<typename T1, typename T2>
bool operator >= (const pair<T1, T2> & lhs, const pair<T1, T2> & rhs)
{
	return !( lhs < rhs );
}

template<typename T1, typename T2>
pair<T1, T2> make_pair( T1 x, T2 y )
{
	return pair<T1, T2>(x, y);
}
/* pair */

/* #nullptr */
class nullptr_t
{
	public:
	template <class T> operator T *() const { return 0; }
	template <class C, class T> operator T C::*() const { return 0; }
	private:
	void operator&() const;
};

const nullptr_t _nullptr = {};
/* nullptr */

} /* namespace ft end */

#endif
