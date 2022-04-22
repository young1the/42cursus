#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "# Brain's default constructor called" << std::endl;
	setIdeas("Empty");
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

Brain::Brain(const std::string & idea_in)
{
	for (int i = 0; i < MAX_IDEAS; ++i)
	{
		ideas[i] = idea_in;
	}
}

/* occf end */

void Brain::setIdeas(const std::string & idea_set)
{
	for (int i = 0; i < MAX_IDEAS; ++i)
	{
		ideas[i] = idea_set;
	}
}

std::string *Brain::getIdeas()
{
	return ideas;
}