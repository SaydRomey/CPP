/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:55:51 by cdumais           #+#    #+#             */
/*   Updated: 2024/09/10 20:56:56 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_TPP
# define PMERGEME_TPP

/*
*!!	use ++i for small optimization with iterators
post-increment creates a tmp copy before incr.
pre-increment directly modifies the iterator.

for primitive types (int), negligable, compilers optimize this
*/

# include "PmergeMe.hpp"

/*
Fills 'container' with values from 'inputSequence'
*/
template <typename Container, typename InputContainer>
void	PmergeMe::setSequence(Container &container, InputContainer &inputSequence)
{
	container.assign(inputSequence.begin(), inputSequence.end());
}

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
			print("Unpaired element: ", container.back());
			// print("Unpaired element: ", first);
			break ;
		}
	}
	printPairs(pairs, "Created pairs:", DEBUG);
	// if (container.size() % 2 != 0)
	// 	print("Unpaired element: ", container.back());
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
	printSequence(sorted, "Sorted sequence: ", DEBUG);
	printSequence(pending, "Pending elements: ", DEBUG);
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
	print("Inserting element paired with first and smallest element of 'sorted'");
	if (sorted.empty() || pending.empty())
		return ;

	sorted.insert(sorted.begin(), pending.front());
	pending.erase(pending.begin());

	printSequence(sorted, "Updated sorted sequence: ", DEBUG);
	printSequence(pending, "Remaining pending elements: ", DEBUG);
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
template <typename Container>
inline Container	getJacobsthalOrder(int n)
{
	// generate Jacobsthal numbers until the number exceeds n
	Container	jacobsthalSequence;

	int	j = 0;
	while (jacobsthal(j) < n)
	{
		jacobsthalSequence.push_back(jacobsthal(j));
		j++;
	}
	jacobsthalSequence.push_back(n); // add the last number
	// printSequence(jacobsthalSequence, "Jacobsthal numbers generated: ", DEBUG);

	// generate the insertion order based on Jacobsthal's sequence
	Container	insertOrder;

	typename Container::const_iterator	it = jacobsthalSequence.begin();

	while (it != jacobsthalSequence.end() - 1)
	{
		int	k = *(it + 1) - 1;
		while (k >= *it)
		{
			insertOrder.push_back(k);
			k--;
		}
		++it;
	}
	
	// size_t	i = 0;
	// while (i < jacobsthalSequence.size() - 1)
	// {
	// 	int	k = jacobsthalSequence[i + 1] - 1;
	// 	while (k >= jacobsthalSequence[i])
	// 	{
	// 		insertOrder.push_back(k);
	// 		k--;
	// 	}
	// 	i++;
	// }
	
	// printSequence(insertOrder, "Jacobsthal order generated: ", DEBUG);
	return (insertOrder);
}


// inline std::vector<int>	getJacobsthalOrder(int n)
// {
// 	// generate Jacobsthal numbers until the number exceeds n
// 	std::vector<int>	jacobsthalSequence;

// 	int	j = 0;
// 	while (jacobsthal(j) < n)
// 	{
// 		jacobsthalSequence.push_back(jacobsthal(j));
// 		j++;
// 	}
// 	jacobsthalSequence.push_back(n); // add the last number
// 	// printSequence(jacobsthalSequence, "Jacobsthal numbers generated: ", DEBUG);

// 	// generate the insertion order based on Jacobsthal's sequence
// 	std::vector<int>	insertOrder;
	
// 	size_t	i = 0;
// 	while (i < jacobsthalSequence.size() - 1)
// 	{
// 		int	k = jacobsthalSequence[i + 1] - 1;
// 		while (k >= jacobsthalSequence[i])
// 		{
// 			insertOrder.push_back(k);
// 			k--;
// 		}
// 		i++;
// 	}
// 	// printSequence(insertOrder, "Jacobsthal order generated: ", DEBUG);
// 	return (insertOrder);
// }

/* ************************************************************************** */

template <typename Container>
typename Container::iterator	binarySearchInsertionPoint(Container &sorted, int element, typename Container::iterator upperBound)
// inline int	binarySearchInsertionPoint(Container &sorted, int element, int lowerBound, int upperBound)
{
	 typename Container::iterator	lowerBound = sorted.begin();
	// int	lowerBound = 0;
	// int	upperBound = sorted.size() - 1;


	while (lowerBound <= upperBound)
	{
		typename Container::iterator	mid = lowerBound + (std::distance(lowerBound, upperBound) / 2);
		// int	mid = (lowerBound + upperBound) / 2;
		
		if (element < *mid)
		// if (element < sorted[mid])
		{
			upperBound = mid - 1;
		}
		else if (element > *mid)
		// else if (element > sorted[mid])
		{
			lowerBound = mid + 1;
		}
		else
		{
			return (mid); // exact match found
		}
	}
	return (lowerBound); // correct insertion point

	/* or */
	
	// typename Container::const_iterator	it;
	
	// it = std::lower_bound(sorted.begin() + lowerBound, sorted.begin() + upperBound + 1, element);
	
	// int	insertionPoint = it - sorted.begin();
	
	// return (it - sorted.begin());
}

// int	calculatePowerOfTwo(int batchIndex)
// {
// 	int	result = 1;
// 	int	i = 0;
	
// 	while (i < batchIndex)
// 	{
// 		result *= 2;
// 		++i;
// 	}
// 	return (result);
// }

/*
5. Insert the remaining [n/2] - 1 elements of X\S into S, one at a time,
with a specially chosen insertion ordering (jacobsthal sequence)

Use binary search in subsequences of S, to determine 
the position at which each element should be inserted

Only search in the range [0, 2^k - 1], where k is the Jacobsthal index
*/
template <typename Container>
void	PmergeMe::insertRemainingElements(Container &sorted, Container &pending)
{
	Container	insertOrder = getJacobsthalOrder<Container>(pending.size());

	// 
	typename Container::const_iterator	it = insertOrder.begin();
	size_t	batchIndex = 0;
	
	while (it != insertOrder.end())
	{
		int	elementIndex = *it;

		if (elementIndex < static_cast<int>(pending.size()))
		{
			typename Container::iterator	upperBoundIt = sorted.begin();
			std::advance(upperBoundIt, std::min(static_cast<int>(sorted.size()) - 1, (1 << batchIndex) - 1));
			
			typename Container::iterator	insertIt = binarySearchInsertionPoint(sorted, pending[elementIndex], upperBoundIt);
			
			sorted.insert(insertIt, pending[elementIndex]);
		}
		++it;
		++batchIndex;
	}

	// or

	// size_t	i = 0;
	// while (i < insertOrder.size())
	// {
	// 	int	elementIndex = insertOrder[i];

	// 	if (elementIndex < static_cast<int>(pending.size()))
	// 	{
	// 		// find the batch index k corresponding to the current element
	// 		int	batchIndex = i; // this is the index in the Jacobsthal sequence

	// 		int	powerOfTwo = 1 << batchIndex; // 2^batchIndex
	// 		// int	powerOfTwo = static_cast<int>(std::pow(2, batchIndex)); // 2^batchIndex
	// 		// int	powerOfTwo = calculatePowerOfTwo(batchIndex); using a loop  (helper function)
			
	// 		int	maxIndexForBatch = powerofTwo - 1; // max index in the sorted sequence for this batch
	// 		int	upperBound = std::min(static_cast<int>(sorted.size()) - 1, maxIndexForBatch);

	// 		int	upperBound = std::min(static_cast<int>(sorted.size()) - 1, (1 << batchIndex) - 1); // 2^k - 1
			
	// 		int	insertIndex = binarySearchInsertionPoint(sorted, pending[elementIndex], 0, upperBound);
			
	// 		sorted.insert(sorted.begin() + insertIndex, pending[elementIndex]);
	// 	}
	// 	i++;
	// }

	printSequence(sorted, "\nFinal sorted sequence: ", DEBUG);
}

/* ************************************************************************** */

// template <typename Container>
// void	PmergeMe::process(Container &container, double &duration)
// {
// 	std::clock_t	start = std::clock();

// 	setSequence(container, getInputSequence());
	
// 	if (is_vector<Container>::value)
// 	{
// 		print("\nProcessing std::vector\n", ORANGE);
// 		// print("Sequence length: ", container.size());
		
// 		std::vector<std::pair<int, int> >	pairs;

// 		createPairs(container, pairs);
// 		compareAndSwapPairs(pairs);
		
// 		std::vector<int>	pending;
// 		std::vector<int>	sorted = sortPairs(pairs, pending);

// 		if (container.size() % 2 != 0)
// 		{
// 			// std::stringstream	unpairedValue;
// 			// unpairedValue << container.back();
// 			// print("Remaining unpaired element (" + unpairedValue.str() + ") added to 'pending'");

// 			print("Remaining unpaired element placed in 'pending'");
// 			pending.push_back(container.back());
// 			printSequence(pending, "Updated pending elements: ", DEBUG);
// 		}

// 		insertSmallestPairedElement(sorted, pending);
		
// 		insertRemainingElements(sorted, pending);

// 		setSequence(container, sorted);
// 	}
// 	else if (is_deque<Container>::value)
// 	{
// 		print("\nProcessing std::deque", ORANGE);

// 		std::deque<std::pair<int, int> >	pairs;
		
// 		createPairs(container, pairs);
// 		compareAndSwapPairs(pairs);

// 		std::deque<int>	sorted;
// 		std::deque<int>	pending;
		
// 		sorted = sortPairs(pairs, pending);

// 		if (container.size() % 2 != 0)
// 		{
// 			// std::stringstream	unpairedValue;
// 			// unpairedValue << container.back();
// 			// print("Remaining unpaired element (" + unpairedValue.str() + ") added to 'pending'");

// 			print("Remaining unpaired element placed in 'pending'");
// 			pending.push_back(container.back());
// 			printSequence(pending, "Updated pending elements: ", DEBUG);
// 		}

// 		insertSmallestPairedElement(sorted, pending);
		
// 		insertRemainingElements(sorted, pending);

// 		setSequence(container, sorted);
// 	}
// 	else
// 	{
// 		// maybe implement list and other containers ?
// 		std::cout << "Handling other container type" << std::endl;
// 	}
	
// 	std::clock_t	end = std::clock();
// 	duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
// }


/* ************************************************************************** */

template <typename Container>
void	PmergeMe::mergeInsertionSort(Container &container)
{
	// deduce the correct container type for pairs
	// typedef typename PairType<Container>::type PairContainerType;
	// PairContainerType	pairs;

	typename PairType<Container>::type	pairs;
	
	createPairs(container, pairs);
	compareAndSwapPairs(pairs);

	Container	pending;
	Container	sorted = sortPairs(pairs, pending);

	if (container.size() % 2 != 0)
	{
		print("Remaining unpaired element placed in 'pending'");
		pending.push_back(container.back());
		printSequence(pending, "Updated pending elements: ", DEBUG);
	}

	insertSmallestPairedElement(sorted, pending);
	insertRemainingElements(sorted, pending);

	setSequence(container, sorted);
}

template <typename Container>
void	PmergeMe::process(Container &container, double &duration)
{
	std::clock_t start = std::clock();
	setSequence(container, getInputSequence());

	// Handle type-specific messages
	if (is_vector<Container>::value)
	{
		print("\nProcessing std::vector\n", ORANGE);
		
		// // idea: pre-allocate space for vector to reduce reallocations
		// typename PairType<Container>::type	pairs;
		// pairs.reserve(container.size() / 2);
		// Container	pending;
		// pending.reserve(container.size() / 2); // + 1); ?? should we add odd value after putting smallest paired value
		// Container	sorted;
		// sorted.reserve(container.size());
		
		mergeInsertionSort(container);
	}
	else if (is_deque<Container>::value)
	{
		print("\nProcessing std::deque\n", ORANGE);
		mergeInsertionSort(container);
	}
	else
	{
		std::cout << "Handling other container type" << std::endl;
	}

	std::clock_t end = std::clock();
	duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
}
#endif // PMERGEME_TPP
