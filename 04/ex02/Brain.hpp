#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

#define MAX_IDEAS 100

class Brain {

private:

	std::string	ideas[MAX_IDEAS];

public:

	Brain();
	~Brain();
	Brain(const Brain & other);
	Brain& operator = (const Brain & other);
	Brain(const std::string & idea_in);
	/* occf */

	void setIdeas(const std::string & idea_set);
	std::string *getIdeas();
	
};

#endif