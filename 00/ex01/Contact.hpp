#pragma once
#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>

# define COL_WIDTH 10

enum eField
{
	FirstName = 0,
	LastName,
	Nickname,
	PhoneNumber,
	DarkestSecret,
	END
};

class Contact {

private:

	void		PrintField(const std::string &field) const;
	std::string	field[END];

public:

	bool	flag;


	Contact();
	~Contact();
	void			PrintBrief(int index);
	void			PrintAll();
	std::string&	getField(enum eField field_no);

};

#endif
