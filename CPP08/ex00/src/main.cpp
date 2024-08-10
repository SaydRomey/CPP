/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:25:08 by cdumais           #+#    #+#             */
/*   Updated: 2024/08/09 18:30:02 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int	main(void)
{
	try
	{
		std::vector<int>	vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(4);
		vec.push_back(5);
		std::vector<int>::iterator	vecIt = easyfind(vec, 3);
		std::cout << "Found value in vector: " << *vecIt << std::endl;

		std::list<int>		lst;
		lst.push_back(10);
		lst.push_back(20);
		lst.push_back(30);
		lst.push_back(40);
		lst.push_back(50);
		std::list<int>::iterator	lstIt = easyfind(lst, 20);
		std::cout << "Found value in list: " << *lstIt << std::endl;

		// this should throw an exception
		easyfind(vec, 42);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
