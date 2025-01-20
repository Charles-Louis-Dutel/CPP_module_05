/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:11:32 by cdutel            #+#    #+#             */
/*   Updated: 2025/01/20 13:34:04 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"

Bureaucrat::Bureaucrat(void) : _Name(), _Grade(150)
{
}

Bureaucrat::Bureaucrat(std::string const name, int const grade) : _Name(name)
{
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	this->_Grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) : _Name(copy._Name)
{
	this->_Grade = copy._Grade;
}

Bureaucrat::~Bureaucrat(void)
{
}


/*Operator overload*/
Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &inst)
{
	if (this != &inst)
	{
		this->_Grade = inst._Grade;
	}
	return (*this);
}


/*Public member functions*/
std::string	Bureaucrat::getName(void) const
{
	return (this->_Name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_Grade);
}


void	Bureaucrat::incrementGrade(void)
{
	if (this->_Grade == 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	this->_Grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	if (this->_Grade == 150)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	this->_Grade++;
}

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_Name << " signed " << form.getName() << std::endl;
	}
	catch(AForm::GradeTooLowException &e)
	{
		std::cout << this->_Name << " couldn't sign " << form.getName();
		std::cout << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->_Name << " executed " << form.getName() << std::endl;
	}
	catch(AForm::FormIsNotSignedException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(AForm::GradeTooLowException &e)
	{
		std::cout << this->_Name << " couldn't execute " << form.getName();
		std::cout << " because " << e.what() << std::endl;
	}
}


/*Ostream overload*/
std::ostream	&operator<<(std::ostream &o, Bureaucrat const &inst)
{
	o << inst.getName() << ", bureaucrat grade " << inst.getGrade();
	return (o);
}
