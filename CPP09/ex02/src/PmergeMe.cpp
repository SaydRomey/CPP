/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:56:04 by cdumais           #+#    #+#             */
/*   Updated: 2024/09/13 21:35:09 by cdumais          ###   ########.fr       */
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
