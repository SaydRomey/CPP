/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:56:04 by cdumais           #+#    #+#             */
/*   Updated: 2024/09/07 23:47:27 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(int argc, char *argv[])
{
	parseInput(argc, argv);
}

PmergeMe::PmergeMe(const PmergeMe &other) :	_inputSequence(other._inputSequence) {}

PmergeMe::~PmergeMe(void) {}

PmergeMe&	PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_inputSequence = other._inputSequence;
	}
	return (*this);
}

/* ************************************************************************** */

/*
Validates the number sequence (unique and positive integers)
Stores the values in a list in PmergeMe's private attribute '_inputSequence'
*/
void	PmergeMe::parseInput(int argc, char *argv[])
{
	std::list<int>	inputSequence;
	std::set<int>	uniqueNumbers;

	if (argc < 2)
	{
		throw (std::invalid_argument("No input sequence provided"));
	}
	int	i = 1;
	while (i < argc)
	{
		errno = 0;
		char	*endPtr;
		long	num = std::strtol(argv[i], &endPtr, 10);
		if (errno == ERANGE || num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
		{
			throw (std::overflow_error(("Integer overflow detected: ") + std::string(argv[i])));
		}
		if (*endPtr != '\0')
		{
			throw (std::invalid_argument(("Invalid integer input: ") + std::string(argv[i])));
		}
		if (num < 0)
		{
			throw (std::invalid_argument("Non-positive integers are not allowed"));
		}
		if (uniqueNumbers.find(num) != uniqueNumbers.end())
		{
			throw (std::invalid_argument("Duplicate values are not allowed"));
		}
		uniqueNumbers.insert(num);
		inputSequence.push_back(num);
		i++;
	}
	this->_inputSequence = inputSequence;
}

/* ************************************************************************** */

const std::list<int> &PmergeMe::getInputSequence(void) const
{
	return (this->_inputSequence);
}

/* ************************************************************************** */

void	print(const std::string &str, const std::string &color)
{
	if (!DEBUG)
		return ;
	
	std::cout << color << str << RESET << std::endl;
}

// void	print(const std::string &str, const std::string &color)
// {
// 	print(str, color, true);
// }

// void	print(const std::string &str, bool shouldPrint)
// {
// 	print(str, GRAYTALIC, shouldPrint);
// }

// void	print(const std::string &str)
// {
// 	print(str, GRAYTALIC, true);
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
