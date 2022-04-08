#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	fixed_point = 0;
}

Fixed::Fixed(const int new_value)
{
	std::cout << "Int constructor called" << std::endl;
	fixed_point = new_value << bit;
}

Fixed::Fixed(const float new_value)
{
	std::cout << "Float constructor called" << std::endl;
	fixed_point = static_cast<int>(roundf((new_value) * (1 << bit)));
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
	this->fixed_point = new_f.fixed_point;
	return *this;
}

std::ostream& operator << (std::ostream& outstream, const Fixed &f)
{
	std::cout << f.toFloat();
	return outstream;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (fixed_point);
}
void Fixed::setRawBits( int const raw )
{
	fixed_point = raw;
}

float Fixed::toFloat( void ) const
{
	return (static_cast<float>(fixed_point) / (1 << bit));
}

int Fixed::toInt( void ) const
{
	return (fixed_point >> bit);
}