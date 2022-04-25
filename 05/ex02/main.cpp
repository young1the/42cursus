#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	{
		std::cout << "---<PresidentialPardonForm Test>---" << std::endl;
		Bureaucrat a("A", 1);	// excute, sign
		Bureaucrat b("B", 25);	// sign
		Bureaucrat c("C", 26);	// 
		PresidentialPardonForm pf("young");
		std::cout << a << "\n" << b << "\n" << c << "\n" << pf << std::endl;
		pf.execute(a);
		pf.beSigned(c);
		b.signForm(pf);
		std::cout << pf << std::endl;
		pf.execute(b);
		a.executeForm(pf);
	}
	{
		std::cout << "\n---<RobotomyRequestForm Test>---" << std::endl;
		Bureaucrat a("A", 42);	// excute, sign
		Bureaucrat b("B", 72);	// sign
		Bureaucrat c("C", 100);	// 
		RobotomyRequestForm pf("young");
		std::cout << a << "\n" << b << "\n" << c << "\n" << pf << std::endl;
		pf.execute(a);
		pf.beSigned(c);
		b.signForm(pf);
		std::cout << pf << std::endl;
		pf.execute(b);
		a.executeForm(pf);
	}
	{
		std::cout << "\n---<ShrubberyCreationForm Test>---" << std::endl;
		Bureaucrat a("A", 126);	// excute, sign		
		Bureaucrat b("B", 145);	// sign
		Bureaucrat c("C", 150);	// 
		ShrubberyCreationForm pf("young");
		std::cout << a << "\n" << b << "\n" << c << "\n" << pf << std::endl;
		pf.execute(a);
		pf.beSigned(c);
		b.signForm(pf);
		std::cout << pf << std::endl;
		pf.execute(b);
		a.executeForm(pf);
	}
}