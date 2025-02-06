/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:57:33 by cdutel            #+#    #+#             */
/*   Updated: 2025/02/06 15:45:53 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include <iostream>
# include <string>
# include <stdexcept>
# include <new>

class	Intern
{
	public:
		Intern(void);
		Intern(Intern const &copy);
		~Intern(void);

		Intern	&operator=(Intern const &inst);

		AForm	*makeForm(std::string form_name, std::string target);
};

#endif
