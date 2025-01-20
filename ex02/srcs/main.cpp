/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:12:07 by cdutel            #+#    #+#             */
/*   Updated: 2025/01/17 05:59:55 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int	main(void)
{
	try
	{
		std::cout << "*****Testing ShrubberyCreationForm*****" << std::endl;
		Bureaucrat	bur("Bob", 146);
		Bureaucrat	bur2("Carl", 145);
		Bureaucrat	bur3("John", 137);

		ShrubberyCreationForm	shrub("Patrick");
		std::cout << shrub << std::endl;
		std::cout << bur2 << std::endl;
		shrub.beSigned(bur2);
		std::cout << std::endl;

		std::cout << shrub << std::endl;
		std::cout << bur << std::endl;
		shrub.beSigned(bur);
		std::cout << std::endl;

		std::cout << shrub << std::endl << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (AForm::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (AForm::FormIsNotSignedException &e)
	{
		std::cerr << e.what() << std::endl;
	}



	std::cout << std::endl << std::endl;
	try
	{
		std::cout << "*****Testing RobotomyRequestForm*****" << std::endl;
		Bureaucrat	bur("Bob", 73);
		Bureaucrat	bur2("Carl", 72);
		Bureaucrat	bur3("John", 45);

		RobotomyRequestForm	robot("Patrick");
		std::cout << robot << std::endl;
		std::cout << bur2 << std::endl;
		robot.beSigned(bur2);
		std::cout << std::endl;

		std::cout << robot << std::endl;
		std::cout << bur << std::endl;
		robot.beSigned(bur);
		std::cout << std::endl;

		std::cout << robot << std::endl << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (AForm::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (AForm::FormIsNotSignedException &e)
	{
		std::cerr << e.what() << std::endl;
	}



	std::cout << std::endl << std::endl;
	try
	{
		std::cout << "*****Testing PresidentialPardonForm*****" << std::endl;
		Bureaucrat	bur("Bob", 26);
		Bureaucrat	bur2("Carl", 25);
		Bureaucrat	bur3("John", 5);

		PresidentialPardonForm	pres("Patrick");
		std::cout << pres << std::endl;
		std::cout << bur2 << std::endl;
		pres.beSigned(bur2);
		std::cout << std::endl;

		std::cout << pres << std::endl;
		std::cout << bur << std::endl;
		pres.beSigned(bur);
		std::cout << std::endl;

		std::cout << pres << std::endl << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (AForm::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (AForm::FormIsNotSignedException &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
