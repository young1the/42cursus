#include <iostream>
#include <string>

int	main()
{
	std::string	str("HI THIS IS BRAIN");
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "The memory address of the string variable\t: " << &str << std::endl;
	std::cout << "The memory address held by stringPTR\t\t: " << &stringPTR << std::endl;
	std::cout << "The memory address held by stringREF\t\t: " << &stringREF << std::endl;

	std::cout << "The value of the string variable\t\t: " << str << std::endl;
	std::cout << "The value pointed to by stringPTR\t\t: " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF\t\t: " << stringREF << std::endl;
}
