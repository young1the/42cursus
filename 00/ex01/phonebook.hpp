#pragma once
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

class PhoneBook
{
private:
	Contact	contact[8];
	void	AddUtil(const char *prompt, std::string &field);
	void	SearchShow();
	void	SerachFindIndex(int &index);
public:
	PhoneBook();
	~PhoneBook();
	void	Add(int index);
	void	Search();
};

#endif
