/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:56:04 by cdumais           #+#    #+#             */
/*   Updated: 2024/08/24 00:08:23 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
	// 
}

PmergeMe::PmergeMe(int argc, char *argv[])
{
	parseInput(argc, argv);
}

PmergeMe::PmergeMe(const PmergeMe &other) 
	: _inputSequence(other._inputSequence), _vectorSequence(other._vectorSequence), _dequeSequence(other._dequeSequence)
{
	// 
}

PmergeMe::~PmergeMe(void) {}

PmergeMe&	PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_inputSequence = other._inputSequence;
		_vectorSequence = other._vectorSequence;
		_dequeSequence = other._dequeSequence;
	}
	return (*this);
}

/* ************************************************************************** */
/* ************************************************************************** */

/*
tmp function to test order of execution for methods
*/
void	PmergeMe::process(void)
{
	setSequence(this->_vectorSequence);
	printSequence(this->_vectorSequence, "Vector: ");

	// group the elements of X into [n/2] pairs of elements, arbitrarily, leaving one element unpaired if odd num of elem
	std::vector<std::pair<int, int> >	pairs = groupPairs(getVectorSequence());
	std::cout << "Grouped Pairs:" << std::endl;
	printPairs(pairs);
}

/* ************************************************************************** */
/* ************************************************************************** */

/*
validates the number sequence (unique and positive integers)
stores the values in a linked list in PmergeMe's private attribute '_inputSequence'
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
			std::string errorMsg = "Integer overflow detected: " + std::string(argv[i]);
			throw (std::overflow_error(errorMsg));
			// throw (std::overflow_error("Integer overflow detected"));
		}
		if (*endPtr != '\0')
		{
			std::string errorMsg = "Invalid integer input: " + std::string(argv[i]);
			throw (std::invalid_argument(errorMsg));
			// throw (std::invalid_argument("Invalid integer input"));
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
	// this->_inputSequence = setSequence(inputSequence); // to test
	// setSequence(inputSequence); //to test
}

/* ************************************************************************** */

const std::list<int> &PmergeMe::getInputSequence(void) const
{
	return (this->_inputSequence);
}

const std::vector<int> &PmergeMe::getVectorSequence(void) const
{
	return (this->_vectorSequence);
}

const std::deque<int> &PmergeMe::getDequeSequence(void) const
{
	return (this->_dequeSequence);
}

/* ************************************************************************** */

