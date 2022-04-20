#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal {

private:

protected:

	std::string	type;

public:

	WrongAnimal();
	~WrongAnimal();
	WrongAnimal(const WrongAnimal & other);
	WrongAnimal& operator = (const WrongAnimal & other);
	/* occf */

	const std::string &	getType() const;

	void	makeSound() const;

};

#endif