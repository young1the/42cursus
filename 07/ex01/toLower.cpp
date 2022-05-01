#include "toLower.hpp"

void toLower(char &c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c += 'a' - 'A';
	}
}
