#include "serial.hpp"

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
