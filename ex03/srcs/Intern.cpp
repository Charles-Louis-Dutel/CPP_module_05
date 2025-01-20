/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:05:25 by cdutel            #+#    #+#             */
/*   Updated: 2025/01/20 16:13:05 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

Intern::Intern(void)
{
}

Intern::Intern(Intern const &copy)
{
	*this = copy;
}

Intern::~Intern(void)
{
}


/*Operator overload*/
Intern	&Intern::operator=(Intern const &inst)
{
	if (this != &inst)
	{
	}
	return (*this);
}


/*Public member function*/
AForm	*Intern::makeForm(std::string form_name, std::string target)
{
	AForm		*new_form = NULL;
	std::string	form[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	int			i = 0;

	while (i < 3)
	{
		if (form[i] == form_name)
			break;
		i++;
	}

	switch (i)
	{
		case 0:
			new_form = new RobotomyRequestForm(target);
			if (!new_form)
			{
				std::cerr << "Cannot allocate RobotomyRequestForm" << std::endl;
				return (NULL);
			}
			std::cout << "Intern creates " << new_form->getName() << std::endl;
			break;

		case 1:
			new_form = new PresidentialPardonForm(target);
			if (!new_form)
			{
				std::cerr << "Cannot allocate PresidentialPardonForm" << std::endl;
				return (NULL);
			}
			std::cout << "Intern creates " << new_form->getName() << std::endl;
			break;

		case 2:
			new_form = new ShrubberyCreationForm(target);
			if (!new_form)
			{
				std::cerr << "Cannot allocate ShrubberyCreationForm" << std::endl;
				return (NULL);
			}
			std::cout << "Intern creates " << new_form->getName() << std::endl;
			break;

		default:
			std::cout << "Intern cannot creates " << form_name;
			std::cout << " because it doesn't exist" << std::endl;
	}
	return (new_form);
}
