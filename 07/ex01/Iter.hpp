#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void Iter(T* arr, unsigned int len, void (*f)(T&))
{
	for (unsigned int i = 0; i < len; i++)
		(*f)(arr[i]);
}

template <typename T>
void Iter(T* arr, unsigned int len, void (*f)(const T&))
{
	for (unsigned int i = 0; i < len; i++)
		(*f)(arr[i]);
}

#endif