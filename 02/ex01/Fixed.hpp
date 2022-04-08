#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:

	int					fixed_point;
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
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream& operator << (std::ostream& outstream, const Fixed &f);

#endif
