#include "Fixed.hpp"

Fixed::Fixed()
{
	fixed_point = 0;
}

Fixed::Fixed(const int new_value)
{
	fixed_point = new_value << bit;
}

Fixed::Fixed(const float new_value)
{
	fixed_point = static_cast<int>(roundf((new_value) * (1 << bit)));
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed &new_f)
{
	*this = new_f;
}

Fixed&	Fixed::operator = (const Fixed &new_f)
{
	this->fixed_point = new_f.fixed_point;
	return *this;
}

std::ostream&	operator << (std::ostream& outstream, const Fixed &f)
{
	std::cout << f.toFloat();
	return outstream;
}

int	Fixed::getRawBits( void ) const
{
	return (fixed_point);
}
void	Fixed::setRawBits( int const raw )
{
	fixed_point = raw;
}

float	Fixed::toFloat( void ) const
{
	return (static_cast<float>(fixed_point) / (1 << bit));
}
int	Fixed::toInt( void ) const
{
	return (fixed_point >> bit);
}

bool	Fixed::operator > (const Fixed &b) const
{
	return (this->getRawBits() > b.getRawBits() ? true : false);
}

bool	Fixed::operator < (const Fixed &b) const
{
	return (this->getRawBits() < b.getRawBits() ? true : false);
}

bool	Fixed::operator >= (const Fixed &b)
{
	return (this->getRawBits() >= b.getRawBits() ? true : false);
}

bool	Fixed::operator <= (const Fixed &b)
{
	return (this->getRawBits() <= b.getRawBits() ? true : false);
}

bool	Fixed::operator == (const Fixed &b)
{
	return (this->getRawBits() == b.getRawBits() ? true : false);
}

bool	Fixed::operator != (const Fixed &b)
{
	return (this->getRawBits() != b.getRawBits() ? true : false);
}

Fixed&	Fixed::operator +(const Fixed &other)
{
	this->fixed_point += other.fixed_point;
	return (*this);
}

Fixed&	Fixed::operator -(const Fixed &other)
{
	this->fixed_point -= other.fixed_point;
	return (*this);
}

Fixed&	Fixed::operator *(const Fixed &other)
{
	long	temp_l;

	temp_l = static_cast<long>(this->fixed_point) * static_cast<long>(other.fixed_point);
	this->setRawBits(temp_l / (1 << bit));
	return (*this);
}

Fixed&	Fixed::operator /(const Fixed &other)
{
	long	temp_l;

	temp_l = static_cast<long>(this->fixed_point) / static_cast<long>(other.fixed_point);
	this->setRawBits(temp_l * (1 << bit));
	return (*this);
}

Fixed&	Fixed::operator ++()
{
	this->fixed_point++;
	return (*this);
}

Fixed	Fixed::operator ++(int)
{
	Fixed	temp(*this);
	
	++(*this);
	return (temp);
}

Fixed&	Fixed::operator --()
{
	this->fixed_point--;
	return (*this);
}

Fixed	Fixed::operator --(int)
{
	Fixed	temp;
	
	temp.fixed_point = this->fixed_point;
	--(*this);
	return (temp);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b ? a : b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b ? a : b);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b ? a : b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b ? a : b);
}

const Fixed&	min(const Fixed& a, const Fixed& b)
{
	return (Fixed::min(a, b));
}

Fixed&	min(Fixed& a, Fixed& b)
{
	return (Fixed::min(a,b));
}

const Fixed&	max(const Fixed& a, const Fixed& b)
{
	return (Fixed::max(a, b));
}

Fixed	&max(Fixed& a, Fixed& b)
{
	return (Fixed::max(a, b));
}