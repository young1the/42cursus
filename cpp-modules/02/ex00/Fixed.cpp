#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &new_f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = new_f;
}

Fixed& Fixed::operator = (const Fixed &new_f)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = new_f.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (value);
}

void Fixed::setRawBits( int const raw )
{
	value = raw;
}
