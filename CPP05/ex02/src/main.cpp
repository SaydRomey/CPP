/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 07:25:04 by cdumais           #+#    #+#             */
/*   Updated: 2024/07/06 10:40:45 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
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
		ShrubberyCreationForm	shrub("blueberry");
		std::cout << shrub << std::endl;

		print("-> bureaucrat");
		Bureaucrat	bubu("Bubu", 42);
		std::cout << bubu << std::endl;

		print("-> signing the form");
		bubu.signForm(shrub);
		std::cout << shrub << std::endl;

		bubu.executeForm(shrub);
		
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	
}


int	main(void)
{
	shrubTest();
	
	return (0);
}
