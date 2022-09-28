#ifndef SERIAL_HPP
#define SERIAL_HPP

#include <iostream>

typedef struct	s_data
{
	std::string	name;
	int			id;
}				Data;

uintptr_t serialize(Data *ptr);

Data *deserialize(uintptr_t raw);

#endif