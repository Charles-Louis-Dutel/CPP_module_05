/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:12:07 by cdutel            #+#    #+#             */
/*   Updated: 2025/01/13 17:16:36 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	bur("Bob", 54);
		std::cout << bur << std::endl;

		// Bureaucrat	bur2("Alex", 151);
		// std::cout << bur2 << std::endl;

		// Bureaucrat	bur3("Greg", 0);
		// std::cout << bur3 << std::endl;

		// Bureaucrat	bur4("David", 2);
		// std::cout << bur4 << std::endl;
		// bur4.incrementGrade();
		// std::cout << bur4 << std::endl;
		// bur4.incrementGrade();
		// std::cout << bur4 << std::endl;

		// Bureaucrat	bur5("Maxime", 149);
		// std::cout << bur5 << std::endl;
		// bur5.decrementGrade();
		// std::cout << bur5 << std::endl;
		// bur5.decrementGrade();
		// std::cout << bur5 << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
