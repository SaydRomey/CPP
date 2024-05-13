/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:13:30 by cdumais           #+#    #+#             */
/*   Updated: 2024/05/13 17:09:14 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	print(std::string str, std::string color=ORANGE)
{
	std::cout << color << "\n[ " << str << " ]" << RESET << std::endl;
}

void	test_constructors(void)
{
	print("** Testing Constructors **");
	
	Bureaucrat	dflt;
	std::cout << dflt << std::endl;
	
	Bureaucrat	param("Cara B. Maturap", 128);
	std::cout << param << std::endl;
	
	Bureaucrat	TobyCapurcar(param);
	std::cout << TobyCapurcar << std::endl;

	param = dflt;
	std::cout << param << std::endl;
}

void	test_exceptions(void)
{
	print("** Testing exceptions **");
	try
	{
		Bureaucrat high("Hugh B. Catarri", 0); // Should throw GradeTooHighException
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat low("Walt Corbura", 151); // Should throw GradeTooLowException
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat normal("Marcelo Barnatur", 100); // Should not throw an exception
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int	main(void)
{
	test_constructors();
	test_exceptions();

	print("** Testing class functions **");
	
	try
	{
		Bureaucrat normal("Marcelo Barnatur", 100);
		std::cout << normal << std::endl;

		normal.incrementGrade(); // Increase grade
		std::cout << normal << std::endl;

		int	i = 0;
		while (i < 99)
		{
			normal.decrementGrade(); // Decrease grade to the lowest
			i++;
		}
		std::cout << normal << std::endl;

		normal.decrementGrade(); // Should throw GradeTooLowException
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	print("Message after catching exception", PURPLE);
	return (0);
}
