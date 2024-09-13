/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:56:04 by cdumais           #+#    #+#             */
/*   Updated: 2024/09/13 14:58:33 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	print(const std::string &str, const std::string &color)
{
	if (!DEBUG)
		return ;
	
	std::cout << color << str << RESET << std::endl;
}

void	print(const std::string &str, int value, const std::string &color)
{
	if (!DEBUG)
		return ;
	
	std::cout << color << str << RESET << value << std::endl;
}

// void	printTime(const size_t &containerSize, const std::string &containerType, double time)
// {
// 	std::cout << std::fixed
// 		<< "Time to process a range of "
// 		<< std::setw(4) << std::right << containerSize
// 		<< " elements with " << containerType << " : "
// 		<< time << " seconds" << std::endl;
// }

/*
tmp
*/
// static void	delaySimulation(void)
// {
// 	volatile int	i = 0;
// 	while (i < 1000000)
// 	{
// 		i++; // example delay
// 	}
// }
