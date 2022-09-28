#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {

private:

	Brain *brain;

public:

	Cat();
	~Cat();
	Cat(const Cat & other);
	Cat& operator = (const Cat & other);
	/* occf */

	void makeSound() const;
	void speak() const;
	void eatChur();

};

#endif