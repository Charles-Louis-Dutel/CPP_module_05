/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:09:05 by cdutel            #+#    #+#             */
/*   Updated: 2025/01/17 05:02:20 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy)
{
	this->_target = copy._target;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}


/*Operator overload*/
PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &inst)
{
	if (this != &inst)
	{
		this->_target = inst._target;
	}
	return (*this);
}


/*Public member functions*/
void	PresidentialPardonForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getRequiredToSign())
	{
		throw AForm::GradeTooLowException();
	}
	this->setIsSigned(1);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor)
{
	if (this->getIsSigned() != 1)
	{
		throw AForm::FormIsNotSignedException();
	}
	if (executor.getGrade() > this->getRequiredToExec())
	{
		throw AForm::GradeTooLowException();
	}
}

