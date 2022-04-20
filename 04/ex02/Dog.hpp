#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {

private:

	using Animal::brain;

public:

	Dog();
	~Dog();
	Dog(const Dog & other);
	Dog& operator = (const Dog & other);
	/* occf */

	void makeSound() const;

};

#endif