#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>
#include "Brain.hpp"

class Animal {

private:

protected:

	std::string	type;
	Brain		*brain;

public:

	Animal();
	virtual ~Animal();
	Animal(const Animal & other);
	Animal& operator = (const Animal & other);
	/* occf */

	const std::string &	getType() const;

	virtual void	makeSound() const;

};

#endif