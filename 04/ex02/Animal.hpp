#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {

private:

protected:

	std::string	type;

public:

	Animal();
	virtual ~Animal();
	Animal(const Animal & other);
	Animal& operator = (const Animal & other);

	Animal(const std::string & type_in);
	/* occf */

	const std::string &	getType() const;

	virtual void	makeSound() const = 0;

};

#endif