/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:50:34 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/15 17:42:36 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl(void)
{
	// std::cout << "Harl constructor" << std::endl;
}

Harl::~Harl(void)
{
	// std::cout << "Harl destructor" << std::endl;
}

void	Harl::complain(std::string level)
{
	// typedef void	(Harl::*HarlFuncPtr)();

	HarlFuncPtr	functions[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	int	i = 0;
	while (i < 4)
	{
		if (levels[i] == level)
		{
			(this->*functions[i])();
			return;
		}
		++i;
	}
	if (!level.empty())
		std::cout << "Invalid complaint level: " << level << std::endl;
	else
		std::cout << "Invalid complaint format" << std::endl;
}

void	Harl::debug(void)
{
	std::cout << ORANGE << "[DEBUG]" << RESET << "\n";
	std::cout << DEBUG_MSG << std::endl; 
}

void	Harl::info(void)
{
	std::cout << ORANGE << "[INFO]" << RESET << "\n";
	std::cout << INFO_MSG << std::endl; 
}
void	Harl::warning(void)
{
	std::cout << ORANGE << "[WARNING]" << RESET << "\n";
	std::cout << WARNING_MSG << std::endl; 
}

void	Harl::error(void)
{
	std::cout << ORANGE << "[ERROR]" << RESET << "\n";
	std::cout << ERROR_MSG << std::endl; 
}
