/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 07:25:04 by cdumais           #+#    #+#             */
/*   Updated: 2024/07/06 13:14:44 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

void	print(std::string str, std::string color = YELLOW)
{
	std::cout << color << "\n" << str << RESET << std::endl;
}

void	shrubTest(void)
{
	print("[ ** Testing shrubbery **]", ORANGE);
	
	try
	{
		print("-> form");
		ShrubberyCreationForm	form("Bushberry");
		std::cout << form << std::endl;

		print("-> bureaucrat");
		Bureaucrat	b;
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

void	pardonTest(int lvl)
{
	print("[ ** Testing Presidential Pardon **]", ORANGE);
	
	try
	{
		print("-> form");
		PresidentialPardonForm	form("Carmil Ian");
		std::cout << form << std::endl;

		print("-> bureaucrat");
		Bureaucrat	b("Bossman", lvl);
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

void	robotomyTest(void)
{
	print("[ ** Testing Robotomy **]", ORANGE);
	
	try
	{
		// 
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int	main(void)
{
	// shrubTest();
	// pardonTest(10); // (25, 5)
	robotomyTest();
	
	return (0);
}
