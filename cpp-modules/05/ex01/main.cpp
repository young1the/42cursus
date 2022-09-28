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
		std::cout << "! Constructing failed" << e.what() << std::endl;
	}
	std::cout << "\n<.....Signing Form.....>" << std::endl;
	Bureaucrat young("young-ch", 43);
	Form study("Study", 42, 42);
	std::cout << "<.....>" << std::endl;
	std::cout << study << std::endl;
	std::cout << young << std::endl;
	young.signForm(study);
	std::cout << "<.....>" << std::endl;
	std::cout << study << std::endl;
	young.incrementGrade();
	std::cout << young << std::endl;
	study.beSigned(young);
	std::cout << study << std::endl;
}