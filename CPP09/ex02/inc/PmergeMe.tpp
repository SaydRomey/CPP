/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:55:51 by cdumais           #+#    #+#             */
/*   Updated: 2024/08/26 20:33:20 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_TPP
# define PMERGEME_TPP

# include "PmergeMe.hpp"

template <typename C>
void	PmergeMe::printSequence(const C &seq, const std::string &str, bool shouldPrint)
{
	if (!shouldPrint)
		return ;

	typename C::const_iterator	it = seq.begin();
	
	std::cout << str;
	while (it != seq.end())
	{
		std::cout << *it;
		if (++it != seq.end())
			std::cout << ", ";
	}
	std::cout << std::endl;
}

template <typename C>
void	PmergeMe::printSequence(const C &seq, const std::string &str, int value, bool shouldPrint)
{
	if (!shouldPrint)
		return ;

	typename C::const_iterator	it = seq.begin();
	
	std::cout << str << value << ": ";
	while (it != seq.end())
	{
		std::cout << *it;
		if (++it != seq.end())
			std::cout << ", ";
	}
	std::cout << std::endl;
}

/* ************************************************************************** */

template <typename Container>
int	PmergeMe::compareElements(const typename Container::value_type &a, const typename Container::value_type &b)
{
	if (a < b)
		return (-1);
	if (a > b)
		return (1);
	return (0);
}

/*
helper function to compare two elements
*/
template <typename T>
int	PmergeMe::compareElements(const T &a, const T &b)
{
	if (a < b)
		return (-1);
	if (a > b)
		return (1);
	return (0);
}

// binary search to find insertion point in a sorted container
template <typename T, typename Container>
int	PmergeMe::binarySearchInsertionPoint(const T &element, const Container &container, int lowerBound, int upperBound)
{
	while (lowerBound <= upperBound)
	{
		int	mid = (lowerBound + upperBound) / 2;
		if (compareElements<Container>(element, container[mid]) < 0)
		{
			upperBound = mid - 1;
		}
		else if (compareElements<Container>(element, container[mid]) > 0)
		{
			lowerBound = mid + 1;
		}
		else
		{
			return (mid);
		}
	}
	return (lowerBound);
}

// inserts an element into a container at a specified position
template <typename T, typename Container>
Container	PmergeMe::insertElement(const Container &container, const T &element, int position)
{
	Container	newContainer(container);

	newContainer.insert(newContainer.begin() + position, element);
	return (newContainer);
}

// binary insert into a sorted container
template <typename T, typename Container>
Container	PmergeMe::binaryInsert(const T &element, const Container &container)
{
	int	index = binarySearchInsertionPoint(element, container, 0, container.size() - 1);
	
	Container	newContainer(container);
	newContainer.insert(newContainer.begin() + index, element);
	
	return (newContainer);	
}

////

template <typename Container>
std::vector<typename Container::value_type> PmergeMe::createPairs(const Container &container)
{
	std::vector<typename Container::value_type>	sortedPairs;
	
	typename	Container::const_iterator it = container.begin();
	
	while (it != container.end())
	{
		typename Container::value_type first = *it;

		++it;
		if (it == container.end())
		{
			sortedPairs.push_back(first);
			break;
		}
		
		typename Container::value_type second = *it;
		++it;
		if (compareElements<Container>(first, second) > 0)
		{
			std::swap(first, second);
		}
		
		sortedPairs.push_back(first);
		sortedPairs.push_back(second);
	}
	return (sortedPairs);
}

template <typename Container>
void PmergeMe::splitMainAndPendingChains(const std::vector<typename Container::value_type> &sortedPairs, Container &mainChain, Container &pendingElements)
{
	typename std::vector<typename Container::value_type>::const_iterator it = sortedPairs.begin();
	
	while (it != sortedPairs.end())
	{
		if (mainChain.size() < sortedPairs.size() / 2)
		{
			mainChain = binaryInsert(*it, mainChain);
		}
		else
		{
			pendingElements.push_back(*it);
		}
		it++;
	}
}

template <typename Container>
void PmergeMe::applyJacobsthalOrder(Container &mainChain, const Container &pendingElements)
{
	std::vector<int> order = getJacobsthalOrder(pendingElements.size());
	printSequence(order, "Jacobsthal order: ", DEBUG);

	size_t i = 0;
	while (i < order.size())
	{
		if (order[i] < static_cast<int>(pendingElements.size()))
		{
			printSequence(mainChain, "Before inserting element at Jacobsthal index ", order[i], DEBUG);

			mainChain = binaryInsert(pendingElements[order[i]], mainChain);

			printSequence(mainChain, "After inserting element at Jacobsthal index ", order[i], DEBUG);
		}
		i++;
	}
}

template <typename Container>
Container PmergeMe::mergeInsertionSort(const Container &container)
{
	if (container.size() < 2)
	{
		return (container);
	}

	// split pair creation and recursive sorting later ...
	
	std::vector<typename Container::value_type> sortedPairs = createPairs(container);
	printSequence(sortedPairs, "Sorted pairs: ", DEBUG);
	
	Container mainChain;
	Container pendingElements;
	splitMainAndPendingChains(sortedPairs, mainChain, pendingElements);

	printSequence(mainChain, "Main Chain after splitting: ", DEBUG);
	printSequence(pendingElements, "Pending elements after splitting: ", DEBUG);

	applyJacobsthalOrder(mainChain, pendingElements);

	printSequence(mainChain, "Final Main Chain after all insertions: ", DEBUG);
	
	return (mainChain);
}

////


// merge-insertion sort function for any container type (maybe public instead of private?)
// template <typename Container>
// Container PmergeMe::mergeInsertionSort(const Container &container)
// {
// 	// Debug: Check the input container size
// 	std::cout << "Input container size: " << container.size() << std::endl;

// 	printSequence(container, "Input values: ", DEBUG);
	
// 	typedef typename Container::value_type T;

// 	if (container.size() < 2)
// 	{
// 		return (container);
// 	}
	
// 	Container	sortedPairs;
// 	typename Container::const_iterator	it = container.begin();
// 	while (it != container.end())
// 	{
// 		T	first = *it;
// 		++it;
// 		if (it == container.end())
// 		{
// 			sortedPairs.push_back(first);
// 			break ;
// 		}
// 		T	second = *it;
// 		++it;
// 		if (compareElements(first, second) > 0)
// 		{
// 			std::swap(first, second);
// 		}
// 		sortedPairs.push_back(first);
// 		sortedPairs.push_back(second);
// 	}

// 	printSequence(sortedPairs, "Sorted pairs: ", DEBUG);

// 	Container	mainChain;
// 	Container	pendingElements;
	
// 	for (typename Container::const_iterator it = sortedPairs.begin(); it != sortedPairs.end(); ++it)
// 	{
// 		if (mainChain.size() < sortedPairs.size() / 2)
// 		{
// 			mainChain = binaryInsert(*it, mainChain);
// 		}
// 		else
// 		{
// 			pendingElements.push_back(*it);
// 		}
// 	}

// 	printSequence(mainChain, "Initial Main Chain after inserting pairs: ", DEBUG);
// 	printSequence(pendingElements, "Pending elements: ", DEBUG);

// 	std::vector<int>	order = getJacobsthalOrder(pendingElements.size());
	
// 	// Debug: Output Jacobsthal order
// 	printSequence(order, "Jacobsthal order: ", DEBUG);

// 	size_t	i = 0;
// 	while (i < order.size())
// 	{
// 		if (order[i] < static_cast<int>(pendingElements.size()))
// 		{
// 			std::ostringstream ossBefore;
// 			ossBefore << "Before inserting element at Jacobsthal index " << order[i] << ": ";
// 			printSequence(mainChain, ossBefore.str(), DEBUG);

// 			mainChain = binaryInsert(pendingElements[order[i]], mainChain);

// 			std::ostringstream ossAfter;
// 			ossAfter << "After inserting element at Jacobsthal index " << order[i] << ": ";
// 			printSequence(mainChain, ossAfter.str(), DEBUG);
// 		}		
// 		i++;
// 	}

// 	printSequence(mainChain, "Final Main Chain after all insertions: ", DEBUG);
	
// 	return (mainChain);
// }

/*
Fills the container with values from the list '_inputSequence'
*/
template <typename Container>
void	PmergeMe::setSequence(Container &seq)
{
	seq.assign(this->_inputSequence.begin(), this->_inputSequence.end());
}

template <typename Container>
void	PmergeMe::printTime(const Container &container, const std::string &containerType, double time) const
{
	std::cout << std::fixed
		<< "Time to process a range of " << container.size() 
		<< " elements with " << containerType << " : " 
		<< time << " seconds" << std::endl;
}


/* ************************************************************************** */


#endif // PMERGEME_TPP
