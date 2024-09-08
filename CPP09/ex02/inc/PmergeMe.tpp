/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:55:51 by cdumais           #+#    #+#             */
/*   Updated: 2024/09/08 04:39:30 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_TPP
# define PMERGEME_TPP

# include "PmergeMe.hpp"

/*
Fills the container with values from the list '_inputSequence'
*/
template <typename Container, typename InputContainer>
void	PmergeMe::setSequence(Container &container, InputContainer &inputSequence)
{
	container.assign(inputSequence.begin(), inputSequence.end());
}
// template <typename Container>
// void	PmergeMe::setSequence(Container &container)
// {
// 	container.assign(this->_inputSequence.begin(), this->_inputSequence.end());
// }

/* ************************************************************************** */
/* ************** Ford-Johnson Merge-Insertion Sort Algorithm *************** */

/*
1.
Group the elements of X into [n/2] pairs of elements, arbitrarily,
leaving one element unpaired if there is an odd number of elements
*/
template <typename Container, typename PairContainer>
void	PmergeMe::createPairs(const Container &container, PairContainer &pairs)
{
	typename Container::const_iterator	it;
	// int	unpaired = -1;
	
	it = container.begin();
	while (it != container.end())
	{
		int	first = *it;
		++it;

		if (it != container.end())
		{
			int	second = *it;
			pairs.push_back(std::make_pair(first, second));
			++it;
		}
		else
		{
			// unpaired = first;
			if (DEBUG)
				std::cout << "Unpaired element: " << first << std::endl;
			break ;
		}
	}
	printPairs(pairs, "Created pairs:", DEBUG);
	// if (DEBUG && container.size() % 2 != 0)
		// std::cout << "Unpaired element: " << unpaired << std::endl;
}

/*
2.
Perform [n/2] comparisons, one per pair,
to determine the larger of the two elements in each pair
*/
template <typename PairContainer>
void	PmergeMe::compareAndSwapPairs(PairContainer &pairs)
{
	typename PairContainer::iterator	it;
	// std::pair<int, int>	&currentPair;
	
	it = pairs.begin();
	while (it != pairs.end())
	{
		std::pair<int, int>	&currentPair = *it;
		if (currentPair.first < currentPair.second)
			std::swap(currentPair.first, currentPair.second);
		++it;
	}
	printPairs(pairs, "Swapped pairs:", DEBUG);
}

/* ************************************************************************** */

/*		** (todo: add better explanation)
Partition function for quicksort:
organizes pairs based on the first value
returns the index where pivot was placed
*/
template <typename PairContainer>
int	partition(PairContainer &pairs, int low, int high)
{
	int	pivot = pairs[high].first; // use first element of the last pair as the pivot
	int	i = low - 1;
	int	j = low;
	
	while (j < high)
	{
		if (pairs[j].first <= pivot)
		{
			++i;
			std::swap(pairs[i], pairs[j]); // move smaller elements to the left of the pivot
		}
		++j;
	}
	std::swap(pairs[++i], pairs[high]); // place the pivot in its correct position
	return (i);
}

/*
QuickSort for pairs: sorts pairs based on the first element of each pair
*/
template <typename PairContainer>
void	quicksort_pair(PairContainer &pairs, int low, int high)
{
	if (low < high)
	{
		int	pivotIndex = partition(pairs, low, high); // partition the array and get the pivot index

		quicksort_pair(pairs, low, pivotIndex - 1); // recursively sort left side of pivot
		quicksort_pair(pairs, pivotIndex + 1, high); // recursively sort right side of pivot
	}
}

/*
3.
Recursively sort the [n/2] larger elements from each pair,
creating a sorted sequence 'S' of [n/2] of the input elements,
in ascending order
*/
template <typename PairContainer, typename Container>
Container	PmergeMe::sortPairs(PairContainer &pairs, Container &pending)
{
	quicksort_pair(pairs, 0, pairs.size() - 1);
	printPairs(pairs, "Sorted pairs:", DEBUG);

	Container	sorted;
	typename PairContainer::const_iterator	it;
	
	it = pairs.begin();
	while (it != pairs.end())
	{
		sorted.push_back(it->first);
		pending.push_back(it->second);
		++it;
	}
	return (sorted);
}

/* ************************************************************************** */

/*
4.
Insert at the start of S the element
that was paired with the first and smallest element of S
*/
template <typename Container>
void	PmergeMe::insertSmallestPairedElement(Container &sorted, Container &pending)
{
	print("insertSmallestPairedElement");
	if (sorted.empty() || pending.empty())
		return ;

	sorted.insert(sorted.begin(), pending.front());
	pending.erase(pending.begin());

	printSequence(sorted, "Sorted larger elements: ", DEBUG);
	printSequence(pending, "Pending smaller elements: ", DEBUG);
}

/* ************************************************************************** */

/*
Calculates the nth Jacobsthal number

(sequence starts with 0 and 1, then each following number is found by
adding the number before it to twice the number before that)

// return (static_cast<int>((pow(2, n) + pow(-1, n - 1)) / 3));
*/
inline int	jacobsthal(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);

	int	prev2 = 0;  // J_0
	int	prev1 = 1;  // J_1
	int	current = 0;

	int	j = 2;
	while (j <= n)
	{
		current = prev1 + 2 * prev2; // J_n = J_{n-1} + 2 * J_{n-2}
		prev2 = prev1;
		prev1 = current;
		j++;
	}
	return (current);
}

/*
Generates order of insertion for the pending elements
using the Jacobsthal number sequence
*/
inline std::vector<int>	getJacobsthalOrder(int n)
{
	// generate Jacobsthal numbers until the number exceeds n
	std::vector<int>	jacobsthalSequence;

	int	j = 0;
	while (jacobsthal(j) < n)
	{
		jacobsthalSequence.push_back(jacobsthal(j));
		j++;
	}
	jacobsthalSequence.push_back(n);	// add the last number
	printSequence(jacobsthalSequence, "Jacobsthal numbers generated: ", DEBUG);

	// generate the insertion order based on Jacobsthal's sequence
	std::vector<int>	insertOrder;
	
	size_t	i = 0;
	while (i < jacobsthalSequence.size() - 1)
	{
		int	k = jacobsthalSequence[i + 1] - 1;
		while (k >= jacobsthalSequence[i])
		{
			insertOrder.push_back(k);
			k--;
		}
		i++;
	}
	printSequence(insertOrder, "Jacobsthal order generated: ", DEBUG);
	return (insertOrder);
}

/* ************************************************************************** */

template <typename Container>
inline int	binarySearchInsertionPoint(Container &sorted, int element)
{
	int	lowerBound = 0;
	int	upperBound = sorted.size() - 1;

	while (lowerBound <= upperBound)
	{
		int	mid = (lowerBound + upperBound) / 2;
		
		if (element < sorted[mid])
		{
			upperBound = mid - 1;
		}
		else if (element > sorted[mid])
		{
			lowerBound = mid + 1;
		}
		else
		{
			return (mid);
		}
	}
	return (lowerBound);



	/* or */
	
	// typename Container::const_iterator	it;
	
	// it = std::lower_bound(sorted.begin() + lowerBound, sorted.begin() + upperBound + 1, element);
	
	// int	insertionPoint = it - sorted.begin();
	
	// return (it - sorted.begin());
}

/*
5. Insert the remaining [n/2] - 1 elements of X\S into S, one at a time,
with a specially chosen insertion ordering (jacobsthal sequence)

Use binary search in subsequences of S, to determine 
the position at which each element should be inserted
*/
template <typename Container>
void	PmergeMe::insertRemainingElements(Container &sorted, Container &pending)
{
	std::vector<int>	insertOrder = getJacobsthalOrder(pending.size());

	size_t	i = 0;
	while (i < insertOrder.size())
	{
		int	elementIndex = insertOrder[i];

		if (elementIndex < static_cast<int>(pending.size()))
		{
			int	insertIndex = binarySearchInsertionPoint(sorted, pending[elementIndex]);
			
			sorted.insert(sorted.begin() + insertIndex, pending[elementIndex]);
		}
		i++;
	}
}

/* ************************************************************************** */

template <typename Container>
void	PmergeMe::process(Container &container, double &duration)
{
	std::clock_t	start = std::clock();

	// setSequence(container);
	setSequence(container, getInputSequence());
	
	if (is_vector<Container>::value)
	{
		std::vector<std::pair<int, int> >	pairs;

		createPairs(container, pairs);
		compareAndSwapPairs(pairs);
		
		std::vector<int>	sorted;
		std::vector<int>	pending;
		
		sorted = sortPairs<std::vector<std::pair<int, int> >, std::vector<int> >(pairs, pending);

		if (container.size() % 2 != 0)
		{
			std::stringstream	unpairedValue;
			unpairedValue << container.back();
			print("adding unpaired element [" + unpairedValue.str() + "] to 'pending'");
			pending.push_back(container.back());
		}

		// tmp to check odd element being added to sorted sequence
		printSequence(sorted, "Sorted larger elements: ", DEBUG);
		printSequence(pending, "Pending smaller elements: ", DEBUG);
		//

		insertSmallestPairedElement(sorted, pending);

		insertRemainingElements(sorted, pending);

		// container = sorted;
		setSequence(container, sorted);
		
	}
	else if (is_deque<Container>::value)
	{
		std::deque<std::pair<int, int> >	pairs;
		
		createPairs(container, pairs);
		compareAndSwapPairs(pairs);

		std::deque<int>	sorted;
		std::deque<int>	pending;
		
		sorted = sortPairs<std::deque<std::pair<int, int> >, std::deque<int> >(pairs, pending);

		if (container.size() % 2 != 0)
		{
			std::stringstream	unpairedValue;
			unpairedValue << container.back();
			print("adding unpaired element [" + unpairedValue.str() + "] to 'pending'");
			pending.push_back(container.back());
		}

		// tmp to check odd element being added to sorted sequence
		printSequence(sorted, "Sorted larger elements: ", DEBUG);
		printSequence(pending, "Pending smaller elements: ", DEBUG);
		//

		insertSmallestPairedElement(sorted, pending);

		insertRemainingElements(sorted, pending);

		setSequence(container, sorted);

	}
	else
	{
		// maybe implement list and other containers ?
		std::cout << "Handling other container type" << std::endl;
	}
	
	std::clock_t	end = std::clock();
	duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
}


/* ************************************************************************** */


#endif // PMERGEME_TPP
