#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	phonebook;

	std::cout << "# 42 PHONEBOOK\n";
	std::cout << "# Enter the Command (ADD, SEARCH, EXIT)" << std::endl;

	int index = 0;
	while (42)
	{
		std::string	command;

		std::cout << "PHONEBOOK > ";
		std::getline(std::cin, command);
		if (command == std::string("ADD"))
		{
			phonebook.Add(index);
			++index;
		}
		else if (command == std::string("SEARCH"))
		{
			phonebook.Search();
		}
		else if (command == std::string("EXIT"))
		{
			std::cout << "# Bye" << std::endl;
			break ;
		}
		if (index == 8)
			index = 0;
	}

	return (0);
}
