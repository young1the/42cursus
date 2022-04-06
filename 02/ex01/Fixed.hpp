#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:

	int					value;
	static const int	bit = 8;

public:

	Fixed();
	Fixed(const int new_value);
	Fixed(const float new_value);
	Fixed(const Fixed &new_f);
	~Fixed();
	Fixed& operator = (const Fixed &new_f);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int new_value)
{
	std::cout << "Int constructor called" << std::endl;
	value = new_value;
}

Fixed::Fixed(const float new_value)
{
	std::cout << "Float constructor called" << std::endl;
	value = int(round(new_value));
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

std::ostream& operator << (std::ostream& outstream, const Fixed &f)
{
	std::cout << f.getRawBits();
	return outstream;
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

#endif