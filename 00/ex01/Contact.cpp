#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void	Contact::PrintField(const std::string &field) const
{
	std::string	temp(field);

	if (temp.size() > COL_WIDTH)
	{
		temp.resize(COL_WIDTH);
		temp[COL_WIDTH - 1] = '.';
	}
	std::cout << std::setw(COL_WIDTH) << temp;
	return ;
}

void	Contact::PrintBrief(int index)
{
	std::cout << std::right;
	std::cout << '|';
	std::cout << std::setw(COL_WIDTH) << index;
	std::cout << '|';
	for (int i = 0; i <= Nickname; i++)
	{
		PrintField(field[i]);
		std::cout << '|';
	}
	std::cout << std::endl;
}

void	Contact::PrintAll()
{
	std::cout << std::left;
	std::cout << "First Name : " << field[FirstName] << std::endl;
	std::cout << "Last Name : " << field[LastName] << std::endl;
	std::cout << "Nickname : " << field[Nickname] << std::endl;
	std::cout << "Phone Number : " << field[PhoneNumber] << std::endl;
	std::cout << "Darkest Secret : " << field[DarkestSecret] << std::endl;
}
