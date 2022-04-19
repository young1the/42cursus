#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {

private:

public:

	Cat();
	~Cat();
	Cat(const Cat & other);
	Cat& operator = (const Cat & other);
	/* occf */

	void makeSound() const;

};

#endif