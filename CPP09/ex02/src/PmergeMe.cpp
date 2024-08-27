/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:56:04 by cdumais           #+#    #+#             */
/*   Updated: 2024/08/26 20:31:41 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(int argc, char *argv[])
{
	parseInput(argc, argv);
}

PmergeMe::PmergeMe(const PmergeMe &other) 
	:	_inputSequence(other._inputSequence),
		_vectorSequence(other._vectorSequence),
		_dequeSequence(other._dequeSequence) {}

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

/*
Validates the number sequence (unique and positive integers)
Stores the values in a linked list in PmergeMe's private attribute '_inputSequence'
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

/*
Calculates the nth jacobsthal number

// return (static_cast<int>((pow(2, n) + pow(-1, n - 1)) / 3));
*/
int	PmergeMe::jacobsthal(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);

	int	prev2 = 0;  // J_0
	int	prev1 = 1;  // J_1
	int	current = 0;

	int	i = 2;
	while (i <= n)
	{
		current = prev1 + 2 * prev2; // J_n = J_{n-1} + 2 * J_{n-2}
		prev2 = prev1;
		prev1 = current;
		i++;
	}
	return (current);
}
/*
Gets the order of pending elements using Jacobsthal numbers
*/
std::vector<int>	PmergeMe::getJacobsthalOrder(int n)
{
	std::vector<int>	order;

	// Generate Jacobsthal numbers until the number exceeds n
	int	j = 0;
	while (jacobsthal(j) < n)
	{
		order.push_back(jacobsthal(j));
		j++;
	}

	// Add the last number
	order.push_back(n);

	// Generate the sequence based on Jacobsthal order
	std::vector<int>	result;
	size_t	i = 0;
	while (i < order.size() - 1)
	{
		int	k = order[i + 1] - 1;
		while (k >= order[i])
		{
			result.push_back(k);
			k--;
		}
		i++;
	}
	return (result);
}


/* ************************************************************************** */

// void	delaySimulation(void)
// {
// 	volatile int	i = 0;
// 	while (i < 1000000)
// 	{
// 		i++; // example delay
// 	}
// }

std::vector<int>	PmergeMe::processVector(double &duration)
{
	std::clock_t	start = std::clock();
	
	setSequence(this->_vectorSequence);

	std::vector<int>	sortedSequence = mergeInsertionSort(_vectorSequence);

	std::clock_t	end = std::clock();
	duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	
	return (sortedSequence);
}

/*
tmp public function to test order of execution order for methods
*/
void	PmergeMe::process(void)
{
	printSequence(getInputSequence(), "Before: ");
	
	double	vectorTime;
	std::vector<int>	sortedSequence = processVector(vectorTime);

	printSequence(sortedSequence, "After: ");
	printTime(_vectorSequence, "std::vector" , vectorTime);
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

