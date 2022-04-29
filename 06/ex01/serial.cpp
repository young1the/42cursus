#include "serial.hpp"

typedef struct s_data
{
	std::string	name;
	int			id;
}Data;

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