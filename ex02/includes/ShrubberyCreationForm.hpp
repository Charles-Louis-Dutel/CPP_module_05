/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:08:45 by cdutel            #+#    #+#             */
/*   Updated: 2025/01/20 13:23:51 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <iostream>
# include <string>
# include <stdexcept>
# include <fstream>

#define ASCII_TREE \
"       🌳\n" \
"       /\\\n" \
"      /  \\\n" \
"     /    \\\n" \
"    /      \\\n" \
"   /        \\\n" \
"  /          \\\n" \
" /            \\\n" \
"/______________\\\n" \
"      ||||\n" \
"      ||||\n" \
"      ||||\n" \
"      ||||\n" \
"      ||||"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string const target);
		ShrubberyCreationForm(ShrubberyCreationForm const &copy);
		~ShrubberyCreationForm(void);

		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &inst);

		virtual void			beSigned(Bureaucrat const &bureaucrat);
		virtual void			execute(Bureaucrat const &executor) const;

	private:
		std::string	_target;
};

#endif
