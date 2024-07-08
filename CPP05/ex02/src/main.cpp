/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 07:25:04 by cdumais           #+#    #+#             */
/*   Updated: 2024/07/07 22:11:07 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void	print(std::string str, std::string color = YELLOW)
{
	std::cout << color << "\n" << str << RESET << std::endl;
}

void	shrubTest(int grade)
{
	print("[ ** Testing shrubbery **]", ORANGE);
	
	try
	{
		print("-> form");
		ShrubberyCreationForm	form("Bushberry");
		std::cout << form << std::endl;

		print("-> bureaucrat");
		Bureaucrat	b("Arthur Beca", grade);
		std::cout << b << std::endl;

		// print("-> signing the form");
		// b.signForm(form);
		// std::cout << form << std::endl;

		print("-> executing the form");
		b.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}	
}

void	pardonTest(int grade)
{
	print("[ ** Testing Presidential Pardon **]", ORANGE);
	
	try
	{
		print("-> form");
		PresidentialPardonForm	form("Ian Carmil");
		std::cout << form << std::endl;

		print("-> bureaucrat");
		Bureaucrat	b("Bossman", grade);
		std::cout << b << std::endl;
		
		print("-> signing the form");
		b.signForm(form);
		std::cout << form << std::endl;

		print("-> executing the form");
		b.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	robotomyTest(int grade)
{
	print("[ ** Testing Robotomy **]", ORANGE);
	
	try
	{
		print("-> form");
		RobotomyRequestForm	form("Bo Ort");
		std::cout << form << std::endl;

		print("-> bureaucrat");
		Bureaucrat	b("Dr.Wily", grade);
		std::cout << b << std::endl;
		
		print("-> signing the form");
		b.signForm(form);
		std::cout << form << std::endl;

		print("-> executing the form");
		b.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int	main(void)
{
	// shrubTest(42);		// (145, 137)
	// pardonTest(10);		// (25, 5)
	robotomyTest(42);	// (72, 45)
	
	return (0);
}
