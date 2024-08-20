/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:56:04 by cdumais           #+#    #+#             */
/*   Updated: 2024/08/20 01:23:14 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) : _vectorTime(0.0), _dequeTime(0.0) {}

PmergeMe::PmergeMe(const PmergeMe &other)
:	_sequence(other._sequence),
	_sortedVector(other._sortedVector),
	_sortedDeque(other._sortedDeque),
	_vectorTime(other._vectorTime),
	_dequeTime(other._dequeTime) {}

PmergeMe::~PmergeMe(void) {}

PmergeMe&	PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_sequence = other._sequence;
		_sortedVector = other._sortedVector;
		_sortedDeque = other._sortedDeque;
		_vectorTime = other._vectorTime;
		_dequeTime = other._dequeTime;
	}
	return (*this);
}

/* ************************************************************************** */

void	PmergeMe::setSequence(const std::vector<int> &seq)
{
	_sequence = seq;
	std::cout << "** Input size: " << _sequence.size() << std::endl;  // Debugging line
}

void	PmergeMe::mergeInsertSort(std::vector<int> &vec)
{
	_sortedVector = vec;
	sortAndMeasureVector();
}

void	PmergeMe::mergeInsertSort(std::deque<int> &deq)
{
	_sortedDeque = deq;
	sortAndMeasureDeque();
}

void	PmergeMe::displayResults(void) const
{
	std::cout << "Before: ";
	std::vector<int>::const_iterator	seqIt = _sequence.begin();
	while (seqIt != _sequence.end())
	{
		std::cout << *seqIt;
		seqIt++;
	}
	std::cout << std::endl;

	std::cout << "After (vector): ";
	std::vector<int>::const_iterator	vecIt = _sortedVector.begin();
	while (vecIt != _sortedVector.end())
	{
		std::cout << *vecIt;
		vecIt++;
	}
	std::cout << std::endl;

	std::cout << "After (deque): ";
	std::deque<int>::const_iterator	deqIt = _sortedDeque.begin();
	while (deqIt != _sortedDeque.end())
	{
		std::cout << *deqIt;
		deqIt++;
	}
	std::cout << std::endl;

	std::cout << "Time to process a range of " << _sortedVector.size() \
	<< " elements with std::vector: " << _vectorTime * 1000000 << " us" << std::endl;
	std::cout << "Time to process a range of " << _sortedDeque.size() \
	<< " elements with std::deque: " << _dequeTime * 1000000 << " us" << std::endl;
}

/* ************************************************************************** */

void	PmergeMe::sortAndMeasureVector(void)
{
	clock_t	start = clock();
	mergeInsertSortImpl(_sortedVector);
	_vectorTime = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;
}

void	PmergeMe::sortAndMeasureDeque(void)
{
	clock_t	start = clock();
	mergeInsertSortImpl(_sortedDeque);
	_dequeTime = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;
}

void	PmergeMe::mergeInsertSortImpl(std::vector<int> &seq)
{
	std::cout << "** Processing sequence of size: " << seq.size() << std::endl;  // Debugging line
	
	// if sequence has 1 or 0 elements, it is already sorted
	if (seq.size() <= 1)
		return ;

	std::vector<int>	mainChain;
	std::vector<int>	auxiliary;
	// pre-allocate to reduce reallocations
	mainChain.reserve(seq.size() / 2);
	auxiliary.reserve(seq.size() / 2);
	
	// step 1: pair the elements and sort each pair
	size_t	i = 0;
	while (i < seq.size())
	{
		if (i + 1 < seq.size())
		{
			// sort the pair and push the smaller element into the mainChain,
			// and the larger element into the auxiliary
			if (seq[i] > seq[i + 1])
			{
				mainChain.push_back(seq[i + 1]);
				auxiliary.push_back(seq[i]);
			}
			else
			{
				mainChain.push_back(seq[i]);
				auxiliary.push_back(seq[i + 1]);
			}
		}
		else
		{
			// if there is an odd number of elements, the las one remains unpaired
			// it is simply added to the mainChain
			mainChain.push_back(seq[i]);
		}
		i += 2;
	}

	std::cout << "** Main chain size: " << mainChain.size() << ", Auxiliary size: " << auxiliary.size() << std::endl;  // Debugging line
	
	// step 2: recursively sort the mainChain
	mergeInsertSortImpl(mainChain);

	// step 3: generate the Jacobsthal sequence dynamically based on the size of the auxiliary array
	std::vector<std::vector<int>::size_type> jacobsthalOrder = generateJacobsthalOrder<std::vector<int>::size_type, std::vector<std::vector<int>::size_type> >(auxiliary.size());

	// step 4: insert elements from auxiliary into the mainChain in the Jacobsthan order
	i = 0;
	while (i < auxiliary.size())
	{
		if (i < jacobsthalOrder.size() && jacobsthalOrder[i] < auxiliary.size())
		{
			// optimize binary insertion to minimize shifting
			size_t	pos = binarySearchPosition(mainChain, auxiliary[jacobsthalOrder[i]]);
			if (pos <= mainChain.size())
			{
				mainChain.insert(mainChain.begin() + pos, auxiliary[jacobsthalOrder[i]]);
			}
		}
		i++;
	}

	i = 0;
	while (i < auxiliary.size())
	{
		if (std::find(mainChain.begin(), mainChain.end(), auxiliary[i]) == mainChain.end())
		{
			size_t	pos = binarySearchPosition(mainChain, auxiliary[i]);
			mainChain.insert(mainChain.begin() + pos, auxiliary[i]);
		}
		i++;
	}
	
	// update the original sequence with the sorted mainChain
	seq = mainChain;
	std::cout << "** Final sequence size: " << seq.size() << std::endl;  // Debugging line
}

void	PmergeMe::mergeInsertSortImpl(std::deque<int> &seq)
{
	if (seq.size() <= 1)
		return ;

	std::deque<int>	mainChain;
	std::deque<int>	auxiliary;
	
	size_t	i = 0;
	while (i < seq.size())
	{
		if (i + 1 < seq.size())
		{
			if (seq[i] > seq[i + 1])
			{
				mainChain.push_back(seq[i + 1]);
				auxiliary.push_back(seq[i]);
			}
			else
			{
				mainChain.push_back(seq[i]);
				auxiliary.push_back(seq[i + 1]);
			}
		}
		else
		{
			mainChain.push_back(seq[i]);
		}
		i += 2;
	}
	
	mergeInsertSortImpl(mainChain);
	
	std::deque<std::deque<int>::size_type> jacobsthalOrder = generateJacobsthalOrder<std::deque<int>::size_type, std::deque<std::deque<int>::size_type> >(auxiliary.size());
	
	i = 0;
	while (i < auxiliary.size())
	{
		if (i < jacobsthalOrder.size() && jacobsthalOrder[i] < auxiliary.size())
		{
			// adjust insertion to make use of deque's efficient push_back/insert
			size_t	pos = binarySearchPosition(mainChain, auxiliary[jacobsthalOrder[i]]);
			if (pos <= mainChain.size())
			{
				if (pos == 0 || pos == mainChain.size())
				{
					mainChain.push_back(auxiliary[jacobsthalOrder[i]]);
				}
				else
				{
					mainChain.insert(mainChain.begin() + pos, auxiliary[jacobsthalOrder[i]]);
				}
			}
		}
		i++;
	}

	i = 0;
	while (i < auxiliary.size())
	{
		if (std::find(mainChain.begin(), mainChain.end(), auxiliary[i]) == mainChain.end())
		{
			size_t	pos = binarySearchPosition(mainChain, auxiliary[i]);
			mainChain.insert(mainChain.begin() + pos, auxiliary[i]);
		}
		i++;
	}	
	
	seq = mainChain;
}

/*
Performs binary search and returns the position to insert the element
*/
template <typename T>
size_t	PmergeMe::binarySearchPosition(T &mainChain, typename T::value_type element)
{
	size_t	low = 0;
	size_t	high = mainChain.size();
	
	while (low < high)
	{
		size_t	mid = (low + high) / 2;

		if (mainChain[mid] < element)
		{
			low = mid + 1;
		}
		else
		{
			high = mid;
		}
	}
	return (low); // position where 'element' should be inserted
}

std::vector<int>	parseInput(int argc, char *argv[])
{
	std::vector<int>	inputSequence;
	std::set<int>		uniqueNumbers; // set to detect duplicates

	int	i = 1;
	while (i < argc)
	{
		int	num = std::atoi(argv[i]);
		if (num <= 0)
		{
			throw (std::invalid_argument("Non-positive integers are not allowed"));
		}
		
		// check for unique numbers
		if (uniqueNumbers.find(num) != uniqueNumbers.end())
		{
			throw (std::invalid_argument("Duplicate values are not allowed"));
		}

		uniqueNumbers.insert(num);
		inputSequence.push_back(num);
		i++;
	}
	return (inputSequence);
}
