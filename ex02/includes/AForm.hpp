/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:37:10 by cdutel            #+#    #+#             */
/*   Updated: 2025/01/17 05:10:56 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "Bureaucrat.hpp"

class	AForm
{
	public:
		AForm(void);
		AForm(std::string const name, int const grade_to_sign, int const grade_to_exec);
		AForm(AForm const &copy);
		virtual ~AForm(void);

		AForm	&operator=(AForm const &inst);

		std::string		getName(void) const;
		bool			getIsSigned(void) const;
		int				getRequiredToSign(void) const;
		int				getRequiredToExec(void) const;
		void			setIsSigned(bool set);
		virtual void	beSigned(Bureaucrat const &bureaucrat) = 0;
		virtual void	execute(Bureaucrat const &executor) = 0;

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

		class	FormIsNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "This form isn't signed";
				}
		};

	private:
		std::string const	_name;
		bool				_is_signed;
		int const			_required_to_sign;
		int const			_required_to_exec;

	protected:
		void			setIsSigned(bool set);
};

std::ostream	&operator<<(std::ostream &o, AForm const &inst);

#endif
