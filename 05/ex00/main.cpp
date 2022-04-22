#include "Bureaucrat.hpp"

int main()
{
	std::cout << "<.....Consturcting Bureaucrat.....>" << std::endl;
	try
	{
		Bureaucrat cho("Cho", 150);
		Bureaucrat young("Young", 42);
		Bureaucrat il("Il", 1);
		Bureaucrat young_ch("young-ch", 0);
		Bureaucrat ch_young("ch-young", 151);
	}
	catch (std::exception & e)
	{
		std::cout << "! Wrong Bureaucrat, because " << e.what() << std::endl;
	}
	std::cout << "\n<.....Increment Bureaucrat.....>" << std::endl;
	try
	{
		Bureaucrat young("Young", 10);
		std::cout << young << std::endl;
		for (int i(0); i < 100; ++i)
		{
			young.incrementGrade();
			std::cout << young << std::endl;
		}
	}
	catch (std::exception & e)
	{
		std::cout << "! Increment failed, " << e.what() << std::endl;
	}
	std::cout << "\n<.....Decrement Bureaucrat.....>" << std::endl;
	try
	{
		Bureaucrat young("Young", 141);
		std::cout << young << std::endl;
		for (int i(0); i < 100; ++i)
		{
			young.decrementGrade();
			std::cout << young << std::endl;
		}
	}
	catch (std::exception & e)
	{
		std::cout << "! Increment failed, " << e.what() << std::endl;
	}
}