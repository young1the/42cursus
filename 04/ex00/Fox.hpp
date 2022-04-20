#ifndef FOX_HPP
#define FOX_HPP

#include "Animal.hpp"

class Fox : public Animal {

private:

public:

	Fox();
	~Fox();
	Fox(const Fox & other);
	Fox& operator = (const Fox & other);
	/* occf */

};

#endif