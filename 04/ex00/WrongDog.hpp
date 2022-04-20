#ifndef WRONGDOG_HPP
#define WRONGDOG_HPP

#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal {

private:

public:

	WrongDog();
	~WrongDog();
	WrongDog(const WrongDog & other);
	WrongDog& operator = (const WrongDog & other);
	/* occf */

};

#endif