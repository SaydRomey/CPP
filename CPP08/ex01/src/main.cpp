/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:05:06 by cdumais           #+#    #+#             */
/*   Updated: 2024/08/11 19:50:43 by cdumais          ###   ########.fr       */
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

/*
creates a 'Span' object with 'numElements' numbers randomized
*/
void	testSpan(unsigned int numElements)
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
		std::cout << e.what() << std::endl;
	}
}

/*
"[...]it would be wonderful to fill your Span using a range of iterators.
Making thousands calls to addNumber() is so annoying.
Implement a member function to add many numbers to your Span in one call."
*/
void	testAddManyNumbersToSpan(unsigned int numElements)
{
	try
	{
		std::vector<int>	numbers;
		unsigned int	i = 1;
		while (i <= numElements)
		{
			numbers.push_back(i);
			i++;
		}
				
		Span	sp = Span(numElements);
		
		sp.addNumbers(numbers.begin(), numbers.end());
		
		printSpan(sp, numElements);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

/*
"Running this code [...] should output:"
2
14
*/
void	pdfTest(void)
{
	try
	{
		Span	sp = Span(5);
		
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int	main(void)
{
	pdfTest();
	testSpan(10000);
	testAddManyNumbersToSpan(10);
	return (0);
}
