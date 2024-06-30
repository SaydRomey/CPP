/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:13:30 by cdumais           #+#    #+#             */
/*   Updated: 2024/06/30 15:57:41 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	print(std::string str, std::string color = YELLOW)
{
	std::cout << color << "\n" << str << RESET << std::endl;
}

void	test_constructors(void)
{
	print("[ ** Testing Constructors ** ]", ORANGE);
	
	print("-> dflt Form");
	Form	dflt;
	std::cout << dflt << std::endl;

	print("-> param Form");
	Form	param("param form", 42, 42);
	std::cout << param << std::endl;

	print("-> copied Form");
	Form	copied(param);
	std::cout << copied << std::endl;

	print("-> assigning dflt's attributes to param");
	param = dflt;
	std::cout << param << std::endl;
}

void	test_exceptions(void)
{
	print("[ ** Testing exceptions ** ]", ORANGE);

	try
	{
		print("-> Form high");
		Form	high("high form", 0, 42); // Should throw GradeTooHighException
		std::cout << high << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		print("-> Form low");
		Form	low("low form", 151, 42); // Should throw GradeTooLowException
		std::cout << low << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		print("-> Form normal");
		Form	normal("normal form", 41, 41); // Should not throw an exception
		std::cout << normal << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	test_member_functions(void)
{
	print("[ ** Testing member functions ** ]", ORANGE);

	try
	{
		print("-> Form normal");
		Form	normal("normal form", 41, 41); // Should not throw an exception
		std::cout << normal << std::endl;

		print("-> bureaucrat with grade too low to sign form");
		Bureaucrat	b;
		std::cout << b << std::endl;

		print("-> bureaucrat.signForm(normal)");
		b.signForm(normal);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	print("Message after catching exception", PURPLE);
}

int	main(void)
{
	// test_constructors();
	// test_exceptions();
	// test_member_functions();

	Form	normal("normal form", 41, 41);
	std::cout << normal << "\n" << std::endl;
	
	Form	dflt;
	std::cout << dflt << "\n" << std::endl;

	Bureaucrat	b;
	std::cout << b << "\n" << std::endl;

	b.signForm(dflt);
	std::cout << "\n" << dflt << std::endl;

	print("-> assigning dflt's attributes to normal");
	normal = dflt;
	std::cout << normal << "\n" << std::endl;

	return (0);
}
