#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "# Brain's default constructor called" << std::endl;
	for (int i = 0; i < MAX_IDEAS; ++i)
	{
		ideas[i] = "Empty";
	}
}

Brain::~Brain()
{
	std::cout << "# Brain's destructor called" << std::endl;
}

Brain::Brain(const Brain & other)
{
	std::cout << "# Brain's copy constructor called" << std::endl;
	*this = other;
}

Brain& Brain::operator = (const Brain & other)
{
	std::cout << "# Brain's copy assignment operator called" << std::endl;
	for (int i = 0; i < MAX_IDEAS; ++i)
	{
		ideas[i] = other.ideas[i];
	}
	return *this;
}

/* occf end */

void Brain::setIdeas(std::string idea_in)
{
	for (int i = 0; i < MAX_IDEAS; ++i)
	{
		ideas[i] = idea_in;
	}
}

const std::string &	Brain::getIdea() const
{
	return (ideas[0]);
}