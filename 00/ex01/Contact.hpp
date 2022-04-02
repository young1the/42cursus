#pragma once

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>

# define COL_WIDTH 10

class Contact
{
private:
	void PrintField(const std::string &field) const;

public:
	enum eField
	{
		FirstName = 0,
		LastName,
		Nickname,
		PhoneNumber,
		DarkestSecret,
		END
	};
	std::string	field[END];

	Contact();
	~Contact();
	void PrintBrief(int index);
	void PrintAll();
};

#endif
