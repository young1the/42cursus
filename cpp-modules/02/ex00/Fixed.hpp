#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:

	int					value;
	static const int	bit = 8;

public:

	Fixed();
	~Fixed();
	Fixed(const Fixed &new_f);
	Fixed& operator = (const Fixed &new_f);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif