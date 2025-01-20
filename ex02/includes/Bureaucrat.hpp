/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:10:13 by cdutel            #+#    #+#             */
/*   Updated: 2025/01/14 01:22:00 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <stdexcept>

class	AForm;

class	Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(std::string const name, int const grade);
		Bureaucrat(Bureaucrat const &copy);
		~Bureaucrat(void);

		Bureaucrat	&operator=(Bureaucrat const &inst);

		std::string	getName(void) const;
		int			getGrade(void) const;

		void		incrementGrade(void);
		void		decrementGrade(void);
		void		signForm(AForm &inst);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Grade is too high";
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Grade is too low";
				}
		};

	private:
		std::string const	_Name;
		int					_Grade;
};

std::ostream	&operator<<( std::ostream &o, Bureaucrat const &inst);

#endif
