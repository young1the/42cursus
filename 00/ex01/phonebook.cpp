#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	amount = 0;
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::AddUtil(const char *prompt, std::string &field)
{
	while (42)
	{
		std::cout << prompt;
		std::getline(std::cin, field);
		if (field != "")
			break ;
		std::cout << "# ERROR : CANNOT HAVE EMPTY FIELD" << std::endl;
	}
	return ;
}

void	PhoneBook::Add(int index)
{
	std::string input;

	AddUtil("Enter your \"First Name\" : ", contact[index].field[Contact::FirstName]);
	AddUtil("Enter your \"Last Name\" : ", contact[index].field[Contact::LastName]);
	AddUtil("Enter your \"Nickname\" : ", contact[index].field[Contact::Nickname]);
	AddUtil("Enter your \"Phone Number\" : ", contact[index].field[Contact::PhoneNumber]);
	AddUtil("Enter your \"Darkest Secret\" : ", contact[index].field[Contact::DarkestSecret]);
	std::cout << "# Added Contact" << std::endl;
	amount++;
}

void	PhoneBook::SearchShow()
{
	std::cout << std::left;
	std::cout << '|';
	std::cout << std::setw(10) << "Index";
	std::cout << '|';
	std::cout << std::setw(10) << "First Name";
	std::cout << '|';
	std::cout << std::setw(10) << "Last Name";
	std::cout << '|';
	std::cout << std::setw(10) << "Nickname";
	std::cout << '|';
	std::cout << std::endl;
	for (int i = 0; i < amount; i++)
	{
		contact[i].PrintBrief(i);
	}
}

void	PhoneBook::SerachFindIndex(int &index)
{
	while (42)
	{
		std::cout << "enter index number for more information. : ";
		std::cin >> index;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
		}
		else
		{
			std::cin.ignore(INT32_MAX, '\n');
			if (index >= 0 && index <= 7)
				break ;
		}
		std::cout << "# ERROR : INDEX RANGE [0,7]" << std::endl;
	}
	return ;
}

void	PhoneBook::Search()
{
	std::string	line;
	int		index;

	line.resize(45, '-');
	std::cout << line << std::endl;
	SearchShow();
	std::cout << line << std::endl;
	SerachFindIndex(index);
	std::cout << line << std::endl;
	contact[index].PrintAll();
	std::cout << line << std::endl;
}
