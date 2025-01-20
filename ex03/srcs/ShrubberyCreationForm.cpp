/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:31:19 by cdutel            #+#    #+#             */
/*   Updated: 2025/01/20 13:59:02 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : AForm(copy)
{
	this->_target = copy._target;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}


/*Operator overload*/
ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &inst)
{
	if (this != &inst)
	{
		this->_target = inst._target;
	}
	return (*this);
}


/*Public member functions*/
void	ShrubberyCreationForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getRequiredToSign())
	{
		throw AForm::GradeTooLowException();
	}
	this->setIsSigned(1);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::ofstream	outfile;

	if (this->getIsSigned() != 1)
	{
		throw AForm::FormIsNotSignedException();
	}
	if (executor.getGrade() > this->getRequiredToExec())
	{
		throw AForm::GradeTooLowException();
	}
	std::string	name = this->_target + "_shrubbery";
	outfile.open(name.c_str());
	if (!outfile.is_open())
	{
		std::cerr << "Error opening shrubbery outfile" << std::endl;
		return;
	}
	outfile << ASCII_TREE;
}
