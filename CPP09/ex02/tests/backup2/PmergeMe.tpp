/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:55:51 by cdumais           #+#    #+#             */
/*   Updated: 2024/09/07 20:50:07 by cdumais          ###   ########.fr       */
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

template <typename Container>
void PmergeMe::printPairs(const std::vector<typename Container::value_type> &pairs, const std::string &str, bool shouldPrint)
{
	if (!shouldPrint)
		return;

	std::cout << str;
	typename std::vector<typename Container::value_type>::const_iterator it = pairs.begin();

	while (it != pairs.end())
	{
		typename Container::value_type first = *it;
		++it;

		if (it != pairs.end())
		{
			typename Container::value_type second = *it;
			++it;
			std::cout << "(" << first << ", " << second << ")";
		}
		else
		{
			// If there's an odd number of elements, just print the last one
			std::cout << "(" << first << ")";
		}

		if (it != pairs.end())
		{
			std::cout << ", ";
		}
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

/*
more cpp-esque version

*/
template <typename T, typename Container>
int	PmergeMe::binarySearchInsertionPoint(const T &element, const Container &container, int lowerBound, int upperBound)
{
	typename	Container::const_iterator it;
	
	it = std::lower_bound(container.begin() + lowerBound, container.begin() + upperBound + 1, element);
	return (it - Container.begin()); // get the index of the insertion point
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
std::vector<std::pair<int, int> >	PmergeMe::createPairs(const Container &container)
{
	std::vector<std::pair<int, int> >	pairs;	
	typename	Container::const_iterator	it = container.begin();
	
	while (it != container.end())
	{
		int	first = *it;
		++it;
		if (it == container.end())
		{
			pairs.push_back(std::make_pair(first, ODDFLAG));
			// pairs.push_back(first);
			// pairs.push_back(ODDFLAG);  // Marker for odd value
			break ;
		}
		
		int	second = *it;
		++it;
		
		// Ensure pairs are (bigger, smaller)
		if (first < second)
		{
			std::swap(first, second);
		}
		pairs.push_back(std::make_pair(first, second));
		// pairs.push_back(first);
		// pairs.push_back(second);
	}
	// printPairs<std::vector<typename Container::value_type> >(pairs, "Pairs created: ", DEBUG);
	return (pairs);
}

/*	need to separate the pair creation process and the recursive sorting into two separate functions

*/
template <typename Container>
Container	PmergeMe::recursivelySortLargerElements(const std::vector<std::pair<int, int> > &pairs, Container &pendingElements)
{
	Container	mainChain;

	// Base case: if no pairs, return empty mainChain
	if (pairs.empty())
	{
		return (mainChain);
	}

	// Process pairs one at a time
	int	larger = pairs[0].first;
	int	smaller = pairs[0].second;
	// typename Container::value_type	larger = pairs[0].first;
	// typename Container::value_type	smaller = pairs[0].second;

	if (smaller != ODDFLAG)
	{
		// normal pair processing
		pendingElements.push_back(smaller); // add smaller value to pendingElements
	}
	else
	{
		// handle odd value
		pendingElements.push_back(larger); // the odd value
		return (mainChain); // no need to sort odd value
	}

	
	// recursively call the function to process remaining pairs
	std::vector<std::pair<int, int> >	remainingPairs(pairs.begin() + 1, pairs.end());
	mainChain = recursivelySortLargerElements(remainingPairs, pendingElements);

	// insert the larger value into the sorted position in mainChain
	typename Container::iterator	it = mainChain.begin();
	while (it != mainChain.end() && *it < larger)
	{
		++it;
	}
	mainChain.insert(it, larger);

	return (mainChain);
}

// template <typename Container>
// void	PmergeMe::insertFirstPendingElement(Container &mainChain, Container &pendingElements)
// {
// 	if (!pendingElements.empty())
// 	{
// 		// remove the first value from pendingElements
// 		int	firstPending = pendingElements.front();
// 		pendingElements.insert(0,)
// 		pendingElements.pop_front();

// 		// insert it at the start of mainChain
// 		mainChain.push_front(firstPending);
// 	}
// }

// template <typename Container>
// void PmergeMe::splitMainAndPendingChains(const std::vector<typename Container::value_type> &pairs, Container &mainChain, Container &pendingElements)
// {
// 	typename std::vector<typename Container::value_type>::const_iterator it = pairs.begin();
	
// 	while (it != pairs.end())
// 	{
// 		if (mainChain.size() < pairs.size() / 2)
// 		{
// 			mainChain = binaryInsert(*it, mainChain);
// 		}
// 		else
// 		{
// 			pendingElements.push_back(*it);
// 		}
// 		it++;
// 	}
// }

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
			// printSequence(mainChain, "Before inserting element at Jacobsthal index ", order[i], DEBUG);
			mainChain = binaryInsert(pendingElements[order[i]], mainChain);
			// printSequence(mainChain, "After inserting element at Jacobsthal index ", order[i], DEBUG);
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
	
	std::vector<std::pair<int, int> >	pairs = createPairs(container);
	// printPairs<std::vector<std::pair<int, int> >(pairs, "Pairs created: ", DEBUG);
	printPairs<std::vector<typename Container::value_type> >(pairs, "Pairs created: ", DEBUG);
	
	Container mainChain;
	Container pendingElements;
	mainChain = recursivelySortLargerElements(pairs, pendingElements);

	// insertFirstPendingElement(mainChain, pendingElements);

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
	
// 	Container	pairs;
// 	typename Container::const_iterator	it = container.begin();
// 	while (it != container.end())
// 	{
// 		T	first = *it;
// 		++it;
// 		if (it == container.end())
// 		{
// 			pairs.push_back(first);
// 			break ;
// 		}
// 		T	second = *it;
// 		++it;
// 		if (compareElements(first, second) > 0)
// 		{
// 			std::swap(first, second);
// 		}
// 		pairs.push_back(first);
// 		pairs.push_back(second);
// 	}

// 	printSequence(pairs, "Sorted pairs: ", DEBUG);

// 	Container	mainChain;
// 	Container	pendingElements;
	
// 	for (typename Container::const_iterator it = pairs.begin(); it != pairs.end(); ++it)
// 	{
// 		if (mainChain.size() < pairs.size() / 2)
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
