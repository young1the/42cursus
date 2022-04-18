#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {

private:

public:

	Dog();
	~Dog();
	Dog(const Dog & other);
	Dog& operator = (const Dog & other);
	/* occf */

	virtual void makeSound() const;

};

#endif