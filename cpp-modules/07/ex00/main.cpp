#include "whatever.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main( void )
{
	int a = 2;
	int b = 3;
	whatever::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << whatever::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << whatever::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	whatever::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << whatever::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << whatever::max( c, d ) << std::endl;


	Bureaucrat young("Young", 42);
	Bureaucrat il("Il", 1);
	Bureaucrat cho("Cho", 1);
	std::cout << whatever::min(young, il) << std::endl;
	std::cout << whatever::min(cho, il) << std::endl;
	std::cout << whatever::max(il, cho) << std::endl;

	return 0;
}

// a = 3, b = 2
// min(a, b) = 2
// max(a, b) = 3
// c = chaine2, d = chaine1
// min(c, d) = chaine1
// max(c, d) = chaine2