/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:57:22 by cdutel            #+#    #+#             */
/*   Updated: 2025/01/20 13:50:49 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/AForm.hpp"

AForm::AForm(void) : _is_signed(0), _required_to_sign(150), _required_to_exec(150)
{
}

AForm::AForm(std::string const name, int const grade_to_sign, int const grade_to_exec) : _name(name), _is_signed(0), _required_to_sign(grade_to_sign), _required_to_exec(grade_to_exec)
{
	if (this->_required_to_sign < 1 || this->_required_to_exec < 1)
	{
		throw AForm::GradeTooHighException();
	}
	else if (this->_required_to_sign > 150 || this->_required_to_exec > 150)
	{
		throw AForm::GradeTooLowException();
	}
}

AForm::AForm(AForm const &copy) : _name(copy._name), _required_to_sign(copy._required_to_sign), _required_to_exec(copy._required_to_exec)
{
	this->_is_signed = copy._is_signed;
}

AForm::~AForm(void)
{
}


/*Operator overload*/
AForm	&AForm::operator=(AForm const &inst)
{
	if (this != &inst)
	{
		this->_is_signed = inst._is_signed;
	}
	return (*this);
}


/*Public member functions*/
std::string	AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::getIsSigned(void) const
{
	return (this->_is_signed);
}

int	AForm::getRequiredToExec(void) const
{
	return (this->_required_to_exec);
}

int	AForm::getRequiredToSign(void) const
{
	return (this->_required_to_sign);
}


/*Protected member functions*/
void	AForm::setIsSigned(bool set)
{
	this->_is_signed = set;
}


/*Ostream overload*/
std::ostream	&operator<<(std::ostream &o, AForm const &inst)
{
	o << inst.getName() << "'s infos : " << std::endl;
	o << "Is " << inst.getName() << " signed : " << (inst.getIsSigned() ? "yes" : "no") << std::endl;
	o << "Grade required to sign : " << inst.getRequiredToSign() << std::endl;
	o << "Grade required to execute : " << inst.getRequiredToExec();

	return (o);
}
