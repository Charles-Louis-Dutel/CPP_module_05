/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:12:07 by cdutel            #+#    #+#             */
/*   Updated: 2025/01/20 14:45:54 by cdutel           ###   ########.fr       */
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
		Bureaucrat	cant_sign("Bob", 146);
		Bureaucrat	cant_exec("Carl", 145);
		Bureaucrat	can_all("John", 137);

		ShrubberyCreationForm	shrub("Patrick");

		std::cout << shrub << std::endl;
		std::cout << cant_sign << std::endl;
		cant_sign.signForm(shrub);
		std::cout << std::endl;

		std::cout << shrub << std::endl;
		std::cout << cant_exec << std::endl;
		cant_exec.executeForm(shrub);
		cant_exec.signForm(shrub);
		cant_exec.executeForm(shrub);
		std::cout << std::endl;

		std::cout << shrub << std::endl;
		std::cout << can_all << std::endl;
		can_all.signForm(shrub);
		can_all.executeForm(shrub);
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


	std::cout << std::endl << std::endl << std::endl << std::endl;
	try
	{
		std::cout << "*****Testing RobotomyRequestForm*****" << std::endl;
		Bureaucrat	cant_sign("Bob", 73);
		Bureaucrat	cant_exec("Carl", 72);
		Bureaucrat	can_all("John", 45);

		RobotomyRequestForm	robot("Bender");

		std::cout << robot << std::endl;
		std::cout << cant_sign << std::endl;
		cant_sign.signForm(robot);
		std::cout << std::endl;

		std::cout << robot << std::endl;
		std::cout << cant_exec << std::endl;
		cant_exec.executeForm(robot);
		cant_exec.signForm(robot);
		cant_exec.executeForm(robot);
		std::cout << std::endl;

		std::cout << robot << std::endl;
		std::cout << can_all << std::endl;
		can_all.signForm(robot);
		can_all.executeForm(robot);
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


	std::cout << std::endl << std::endl << std::endl << std::endl;
	try
	{
		std::cout << "*****Testing PresidentialPardonForm*****" << std::endl;
		Bureaucrat	cant_sign("Bob", 26);
		Bureaucrat	cant_exec("Carl", 25);
		Bureaucrat	can_all("John", 5);

		PresidentialPardonForm	pres("Patrick");

		std::cout << pres << std::endl;
		std::cout << cant_sign << std::endl;
		cant_sign.signForm(pres);
		std::cout << std::endl;

		std::cout << pres << std::endl;
		std::cout << cant_exec << std::endl;
		cant_exec.executeForm(pres);
		cant_exec.signForm(pres);
		cant_exec.executeForm(pres);
		std::cout << std::endl;

		std::cout << pres << std::endl;
		std::cout << can_all << std::endl;
		can_all.signForm(pres);
		can_all.executeForm(pres);
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

	return (0);
}
