/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:57:22 by cdutel            #+#    #+#             */
/*   Updated: 2025/01/13 22:21:52 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Form.hpp"

Form::Form(void) : _is_signed(0), _required_to_sign(150), _required_to_exec(150)
{
}

Form::Form(std::string const name, int const grade_to_sign, int const grade_to_exec) : _name(name), _is_signed(0), _required_to_sign(grade_to_sign), _required_to_exec(grade_to_exec)
{
	if (this->_required_to_sign < 1 || this->_required_to_exec < 1)
	{
		throw Form::GradeTooHighException();
	}
	else if (this->_required_to_sign > 150 || this->_required_to_exec > 150)
	{
		throw Form::GradeTooLowException();
	}
}

Form::Form(Form const &copy) : _name(copy._name), _required_to_sign(copy._required_to_sign), _required_to_exec(copy._required_to_exec)
{
	this->_is_signed = copy._is_signed;
}

Form::~Form(void)
{
}


/*Operator overload*/
Form	&Form::operator=(Form const &inst)
{
	if (this != &inst)
	{
		this->_is_signed = inst._is_signed;
	}
	return (*this);
}


/*Public member functions*/
std::string	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getIsSigned(void) const
{
	return (this->_is_signed);
}

int	Form::getRequiredToExec(void) const
{
	return (this->_required_to_exec);
}

int	Form::getRequiredToSign(void) const
{
	return (this->_required_to_sign);
}

void	Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_required_to_sign)
	{
		throw Form::GradeTooLowException();
	}
	this->_is_signed = 1;
}


/*Ostream overload*/
std::ostream	&operator<<(std::ostream &o, Form const &inst)
{
	o << inst.getName() << "'s infos : " << std::endl;
	o << "Is " << inst.getName() << " signed : " << (inst.getIsSigned() ? "yes" : "no") << std::endl;
	o << "Grade required to sign : " << inst.getRequiredToSign() << std::endl;
	o << "Grade required to execute : " << inst.getRequiredToExec();

	return (o);
}
