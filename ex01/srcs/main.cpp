/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:12:07 by cdutel            #+#    #+#             */
/*   Updated: 2025/02/06 14:59:52 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int	main(void)
{
	try
	{
		std::cout << "Testing valid form : " << std::endl;
		Form	form1("Form 1", 50, 1);
		std::cout << form1 << std::endl << std::endl;
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;


	try
	{
		std::cout << "Testing too low required_to_sign form : " << std::endl;
		Form	form2("Form 2", 151, 1);
		std::cout << form2 << std::endl;
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;


	try
	{
		std::cout << "Testing too high required_to_sign form : " << std::endl;
		Form	form3("Form 3", 0, 1);
		std::cout << form3 << std::endl;
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;


	try
	{
		std::cout << "Testing too low required_to_exec form : " << std::endl;
		Form	form4("Form 4", 50, 151);
		std::cout << form4 << std::endl;
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;


	try
	{
		std::cout << "Testing too high required_to_exec form : " << std::endl;
		Form	form5("Form 5", 50, 0);
		std::cout << form5 << std::endl;
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl << std::endl;


	try
	{
		std::cout << "Testing bureaucrat signing form : " << std::endl;
		Bureaucrat	bur("Bob", 54);
		Bureaucrat	bur2("Carl", 50);
		Bureaucrat	bur3("John", 49);

		Form	form("Form test", 50, 1);
		std::cout << form << std::endl << std::endl;

		std::cout << bur << std::endl;
		bur.signForm(form);
		std::cout << form << std::endl << std::endl;

		std::cout << bur2 << std::endl;
		bur2.signForm(form);
		std::cout << form << std::endl << std::endl;

		std::cout << bur3 << std::endl;
		bur3.signForm(form);
		std::cout << form << std::endl << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
