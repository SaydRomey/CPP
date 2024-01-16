/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 23:01:21 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/16 00:05:53 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl(void)
{
	// std::cout << "Harl constructor" << std::endl;

	HarlFuncPtr[DEBUG] = &Harl::debug;
	HarlFuncPtr[INFO] = &Harl::info;
	HarlFuncPtr[WARNING] = &Harl::warning;
	HarlFuncPtr[ERROR] = &Harl::error;

	_levels[DEBUG] = "DEBUG";
	_levels[INFO] = "INFO";
	_levels[WARNING] = "WARNING";
	_levels[ERROR] = "ERROR";

}

Harl::~Harl(void)
{
	// std::cout << "Harl destructor" << std::endl;
}

void	Harl::complain(std::string level)
{
	int	i = 0;
	while (i < LVL_COUNT)
	{
		if (_levels[i] == level)
			break;
		i++;
	}
	switch(i)
	{
		case DEBUG:
			(this->*HarlFuncPtr[DEBUG])();
			// fallthrough
		case INFO:
			(this->*HarlFuncPtr[INFO])();
			// fallthrough
		case WARNING:
			(this->*HarlFuncPtr[WARNING])();
			// fallthrough
		case ERROR:
			(this->*HarlFuncPtr[ERROR])();
			break;
		default:
			std::cout << DEFAULT_MSG << std::endl;
	}
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
