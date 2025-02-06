/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:12:07 by cdutel            #+#    #+#             */
/*   Updated: 2025/02/06 15:48:26 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"

int	main(void)
{
	Intern		someRandomIntern;
	Bureaucrat	can_do_all("Bob", 5);
	AForm		*rrf;

	std::cout << "\033[33m*****Testing RobotomyRequestForm*****\033[0m" << std::endl;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (rrf)
	{
		can_do_all.signForm(*rrf);
		can_do_all.executeForm(*rrf);
		delete rrf;
	}
	std::cout << std::endl;

	std::cout << "\033[34m*****Testing PresidentialPardonForm*****\033[0m" << std::endl;
	rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
	if (rrf)
	{
		can_do_all.signForm(*rrf);
		can_do_all.executeForm(*rrf);
		delete rrf;
	}
	std::cout << std::endl;

	std::cout << "\033[32m*****Testing ShrubberyCreationForm*****\033[0m" << std::endl;
	rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
	if (rrf)
	{
		can_do_all.signForm(*rrf);
		can_do_all.executeForm(*rrf);
		delete rrf;
	}
	std::cout << std::endl;

	std::cout << "\033[31m*****Testing Invalid Form*****\033[0m" << std::endl;
	rrf = someRandomIntern.makeForm("inexistant form", "Bender");
	if (rrf)
	{
		can_do_all.signForm(*rrf);
		can_do_all.executeForm(*rrf);
		delete rrf;
	}

	return (0);
}

