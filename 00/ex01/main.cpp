#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	phonebook;

	std::cout << "# 42 PHONEBOOK" << std::endl;
	std::cout << "# Enter the Command (ADD, SEARCH, EXIT)" << std::endl;

	while (42)
	{
		static int index;
		std::string	command;

		std::cout << "PHONEBOOK > ";
		std::getline(std::cin, command);
		if (command == std::string("ADD"))
		{
			phonebook.Add(index);
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
		index++;
		if (index == 8)
			index = 0;
	}
	return (0);
}

// Please note that dynamic allocation is forbidden

// On program start-up, the phonebook is empty,
// the user is prompted to enter one of three commands.
// The program only accepts ADD, SEARCH and EXIT.

// ADD: save a new contact
//prompted to input the information of the new contact one field at a time.
// first name, last name, nickname, phone number, and darkest secret.
//  A saved contact can’t have empty fields.

// SEARCH: display a specific contact
// Display the saved contacts as a list of 4 columns:
// index, first name, last name and nickname.
// Each column must be 10 characters wide. (’|’) separate them.
// The text must be right-aligned.
// If the text is longer than the column,
// it must be truncated and the last displayable character must be replaced by a
// dot (’.’).
