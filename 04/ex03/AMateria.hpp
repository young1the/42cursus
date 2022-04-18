#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class AMateria
{
protected:
	std::string type;
public:

	AMateria(std::string const & type_in);
	std::string const & getType() const;
	virtual AMateria* clone() const = 0;

};

std::string const & AMateria::getType() const
{
	return type;
}

#endif