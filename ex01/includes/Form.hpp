/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:37:10 by cdutel            #+#    #+#             */
/*   Updated: 2025/01/13 21:30:43 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "Bureaucrat.hpp"

class	Form
{
	public:
		Form(void);
		Form(std::string const name, int const grade_to_sign, int const grade_to_exec);
		Form(Form const &copy);
		~Form(void);

		Form	&operator=(Form const &inst);

		std::string	getName(void) const;
		bool		getIsSigned(void) const;
		int			getRequiredToSign(void) const;
		int			getRequiredToExec(void) const;

		void		beSigned(Bureaucrat const &bureaucrat);

		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "Grade is too high";
				}
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "Grade is too low";
				}
		};

	private:
		std::string const	_name;
		bool				_is_signed;
		int const			_required_to_sign;
		int const			_required_to_exec;
};

std::ostream	&operator<<(std::ostream &o, Form const &inst);

#endif
