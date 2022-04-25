#include <iostream>

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

int main(void)
{
	Data before = {"young-ch", 42};
	Data *after;
	uintptr_t uptr;

	std::cout << before.name << ", " << before.id << std::endl;
	uptr = serialize(&before);
	after = deserialize(uptr);
	std::cout << after->name << ", " << after->id << std::endl;
}
