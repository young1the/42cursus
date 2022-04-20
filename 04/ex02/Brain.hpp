#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

#define MAX_IDEAS 100

class Brain {

private:

protected:

	std::string	ideas[MAX_IDEAS];

public:

	Brain();
	~Brain();
	Brain(const Brain & other);
	Brain& operator = (const Brain & other);
	/* occf */
	void setIdeas(std::string idea_in);
	const std::string &	getIdea() const;

};

#endif