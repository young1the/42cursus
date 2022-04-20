#include "Fox.hpp"

Fox::Fox()
: Animal("Fox")
{
	std::cout << "# Fox's default constructor called" << std::endl;
}

Fox::~Fox()
{
	std::cout << "# Fox's destructor called" << std::endl;
}

Fox::Fox(const Fox & other)
: Animal(other)
{
	std::cout << "# Fox's copy constructor called" << std::endl;
}

Fox& Fox::operator = (const Fox & other)
{
	std::cout << "# Fox's copy assignment operator called" << std::endl;
	(void)other;
	return *this;
}

/* occf end*/