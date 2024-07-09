/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:13:30 by cdumais           #+#    #+#             */
/*   Updated: 2024/07/09 11:16:29 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	print(std::string str, std::string color=ORANGE)
{
	std::cout << color << "\n" << str << RESET << std::endl;
}

void	test_constructors(void)
{
	print("[ ** Testing Constructors ** ]");
	
	print("-> dflt", YELLOW);
	Bureaucrat	dflt;
	std::cout << dflt << std::endl;
	
	print("-> param bureaucrat", YELLOW);
	Bureaucrat	param("Cara B. Maturap", 128);
	std::cout << param << std::endl;
	
	print("-> copy bureaucrat", YELLOW);
	Bureaucrat	TobyCapurcar(param);
	std::cout << TobyCapurcar << std::endl;

	print("-> assigning dflt's grade to param", YELLOW);
	param = dflt;
	std::cout << param << std::endl;
}

void	test_exceptions(void)
{
	print("[ ** Testing exceptions ** ]");

	try
	{
		print("-> bureaucrat high", YELLOW);
		Bureaucrat high("Hugh B. Catarri", 0); // Should throw GradeTooHighException
		std::cout << high << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		print("-> bureaucrat low", YELLOW);
		Bureaucrat low("Walt Corbura", 151); // Should throw GradeTooLowException
		std::cout << low << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		print("-> bureaucrat normal", YELLOW);
		Bureaucrat normal("Marcelo Barnatur", 100); // Should not throw an exception
		std::cout << normal << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	test_member_functions(void)
{
	print("[ ** Testing class functions ** ]");

	try
	{
		print("-> constructor with grade at 100", YELLOW);
		Bureaucrat normal("Marcelo Barnatur", 100);
		std::cout << normal << std::endl;

		print("-> 'incrementGrade()' called once", YELLOW);
		normal.incrementGrade(); // Increase grade
		std::cout << normal << std::endl;

		print("-> loop to get to lowest grade...", YELLOW);
		unsigned int	i = normal.getGrade();
		while (i < GRADE_MIN)
		{
			normal.decrementGrade(); // Decrease grade to the lowest
			i++;
		}
		std::cout << normal << std::endl;

		print("-> 'decrementGrade()' called once", YELLOW);
		normal.decrementGrade(); // Should throw GradeTooLowException
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
	test_exceptions();
	// test_member_functions();

	return (0);
}
