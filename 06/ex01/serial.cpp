#include "serial.hpp"

uintptr_t serialize(Data *ptr)
{
	std::cout << "serialize Data" << std::endl;
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *deserialize(uintptr_t raw)
{
	std::cout << "deserialize Data" << std::endl;
	return (reinterpret_cast<Data *>(raw));
}