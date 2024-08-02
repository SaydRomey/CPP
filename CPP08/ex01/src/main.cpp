/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:05:06 by cdumais           #+#    #+#             */
/*   Updated: 2024/08/02 13:08:35 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>

void	printSpan(Span &sp, unsigned int numElements)
{
	std::cout << "\n(" << numElements << " numbers)" << std::endl;
	std::cout << "Shortest span:\t" << sp.shortestSpan() << std::endl;
	std::cout << "Longest span:\t" << sp.longestSpan() << std::endl;
}

void	testLargeSpan(unsigned int numElements)
{
	try
	{
		Span	sp(numElements);
		
		std::srand(static_cast<unsigned int>(time(0)));
		unsigned int	i = 0;
		while (i < numElements)
		{
			sp.addNumber(std::rand());
			i++;
		}
		printSpan(sp, numElements);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int	main(void)
{
	testLargeSpan(10000);

	try
	{
		Span	sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		// std::cout << sp.shortestSpan() << std::endl;
		// std::cout << sp.longestSpan() << std::endl;
		printSpan(sp, 5);

		std::vector<int>	numbers;
		numbers.push_back(1);
		numbers.push_back(2);
		numbers.push_back(3);
		numbers.push_back(4);
		numbers.push_back(5);
		numbers.push_back(6);
		numbers.push_back(7);
		numbers.push_back(8);
		numbers.push_back(9);
		numbers.push_back(10);
				
		Span	sp2 = Span(10);
		sp2.addNumbers(numbers.begin(), numbers.end());
		printSpan(sp2, 10);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
