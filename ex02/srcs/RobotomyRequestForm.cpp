/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:08:03 by cdutel            #+#    #+#             */
/*   Updated: 2025/01/17 05:02:15 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy)
{
	this->_target = copy._target;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}


/*Operator overload*/
RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &inst)
{
	if (this != &inst)
	{
		this->_target = inst._target;
	}
	return (*this);
}


/*Public member functions*/
void	RobotomyRequestForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getRequiredToSign())
	{
		throw AForm::GradeTooLowException();
	}
	this->setIsSigned(1);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor)
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
