#include "Form.hpp"

int main()
{
	std::cout << "<.....Consturcting Form.....>" << std::endl;
	try
	{
		Form study1("Study1", 1, 1);
		Form study2("Study2", 42, 42);
		Form study3("Study3", 150, 150);
		Form vacation("Vacation", 0, 151);
	}
	catch (std::exception & e)
	{
		std::cout << "! Wrong Form, because " << e.what() << std::endl;
	}
	Bureaucrat young("young-ch", 42);
	Form study3("Study3", 150, 150);
	study3.beSigned(young);
}