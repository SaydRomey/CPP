/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:55:51 by cdumais           #+#    #+#             */
/*   Updated: 2024/09/14 20:49:31 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_TPP
# define PMERGEME_TPP

# include "PmergeMe.hpp"

template <typename Container>
PmergeMe<Container>::PmergeMe(void) : _sortingTime(0.0), _comparisons(0) {}

template <typename Container>
PmergeMe<Container>::PmergeMe(int argc, char *argv[]) : _sortingTime(0.0), _comparisons(0)
{
	parseInput(argc, argv);
}

template <typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe &other) : 
	_inputSequence(other._inputSequence), _pairs(other._pairs), _sorted(other._sorted), _pending(other._pending), _sortingTime(other._sortingTime), _comparisons(other._comparisons) {}

template <typename Container>
template <typename OtherContainer>
PmergeMe<Container>::PmergeMe(const PmergeMe<OtherContainer> &other) : _sortingTime(other.getSortingTime()), _comparisons(other.getComparisons())
{
	setSequence(_inputSequence, other.getInputSequence());
	setSequence(_sorted, other.getSortedSequence());
	setSequence(_pending, other.getPendingSequence());
}

template <typename Container>
PmergeMe<Container>::~PmergeMe(void) {}

template <typename Container>
PmergeMe<Container>&	PmergeMe<Container>::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_inputSequence = other._inputSequence;
		_sorted = other._sorted;
		_pending = other._pending;
		_sortingTime = other._sortingTime;
		_comparisons = other._comparisons;
	}
	return (*this);
}

template <typename Container>
template <typename OtherContainer>
PmergeMe<Container>&	PmergeMe<Container>::operator=(const PmergeMe<OtherContainer> &other)
{
	if (reinterpret_cast<void*>(this) != reinterpret_cast<void*>(&other))
	{
		setSequence(_inputSequence, other.getInputSequence());
		setSequence(_sorted, other.getSortedSequence());
		setSequence(_pending, other.getPendingSequence());
		_sortingTime = other.getSortingTime();
		_comparisons = other.getComparisons();
	}
	return (*this);
}

/* ************************************************************************** */

template <typename Container>
const Container&	PmergeMe<Container>::getInputSequence(void) const
{
	return (this->_inputSequence);
}

template <typename Container>
const Container&	PmergeMe<Container>::getSortedSequence(void) const
{
	return (this->_sorted);
}

template <typename Container>
const Container&	PmergeMe<Container>::getPendingSequence(void) const
{
	return (this->_pending);
}

template <typename Container>
const double&	PmergeMe<Container>::getSortingTime(void) const
{
	return (this->_sortingTime);
}

template <typename Container>
const int&	PmergeMe<Container>::getComparisons(void) const
{
	return (this->_comparisons);
}

template <typename Container>
const std::string	PmergeMe<Container>::getContainerType(void) const
{
	std::string	containerType = "unknown";
	
	if (is_vector<Container>::value)
		containerType = "std::vector";
	else if (is_deque<Container>::value)
		containerType = "std::deque";
	return (containerType);
}

/* ************************************************************************** */

template <typename Container>
void	PmergeMe<Container>::incrementComparisons(void)
{
	_comparisons++;
}

/*
Validates the number sequence (unique and positive integers)
Stores the values in PmergeMe's private attribute '_inputSequence'
*/
template <typename Container>
void	PmergeMe<Container>::parseInput(int argc, char *argv[])
{
	Container		inputSequence;
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
/* ************** Ford-Johnson Merge-Insertion Sort Algorithm *************** */

/*
1.
Group the elements of X into [n/2] pairs of elements, arbitrarily,
leaving one element unpaired if there is an odd number of elements
*/
template <typename Container>
void	PmergeMe<Container>::createPairs(void)
{
	typename Container::const_iterator	it = _inputSequence.begin();
	
	while (it != _inputSequence.end())
	{
		int	first = *it;
		++it;

		if (it != _inputSequence.end())
		{
			int	second = *it;
			_pairs.push_back(std::make_pair(first, second));
			++it;
		}
		else
		{
			print("Unpaired element: ", first);
			break ;
		}
	}
	printPairs(_pairs, "Created pairs:", DEBUG);
}

/*
2.
Perform [n/2] comparisons, one per pair,
to determine the larger of the two elements in each pair
*/
template <typename Container>
void	PmergeMe<Container>::compareAndSwapPairs()
{
	typename PairContainer::iterator	it = _pairs.begin();
	
	while (it != _pairs.end())
	{
		if (it->first < it->second)
		{
			std::swap(it->first, it->second);
		}
		incrementComparisons();
		++it;
	}
}

/* ************************************************************************** */

/*
Partition function for quicksort:
organizes pairs based on the first value of each pair
returns the index where pivot element was placed
*/
template <typename Container>
int	partition(Container &pairs, int low, int high)
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
template <typename Container>
void	quicksortPairs(Container &pairs, int low, int high)
{
	if (low < high)
	{
		int	pivotIndex = partition(pairs, low, high); // partition the array and get the pivot index

		quicksortPairs(pairs, low, pivotIndex - 1); // recursively sort left side of pivot
		quicksortPairs(pairs, pivotIndex + 1, high); // recursively sort right side of pivot
	}
}

/*
3.
Recursively sort the [n/2] larger elements from each pair,
creating a sorted sequence 'S' of [n/2] of the input elements,
in ascending order
*/
template <typename Container>
void	PmergeMe<Container>::sortPairs(void)
{
	quicksortPairs(_pairs, 0, _pairs.size() - 1);
	printPairs(_pairs, "Sorted pairs:", DEBUG);
}

template <typename Container>
void	PmergeMe<Container>::generateSortedSequence(void)
{
	_sorted.clear();
	_pending.clear(); // these might not be needed anymore

	typename PairContainer::const_iterator	it = _pairs.begin();
	
	while (it != _pairs.end())
	{
		_sorted.push_back(it->first);
		_pending.push_back(it->second);
		++it;
	}
	printSequence(_sorted, "Sorted sequence: ", DEBUG);
	printSequence(_pending, "Pending elements: ", DEBUG);
}

/* ************************************************************************** */

/*
4.
Insert at the start of S the element
that was paired with the first and smallest element of S
*/
template <typename Container>
void	PmergeMe<Container>::insertSmallestPairedElement(void)
{
	print("Inserting element paired with first and smallest element of 'sorted'");
	if (_sorted.empty() || _pending.empty())
		return ;

	_sorted.insert(_sorted.begin(), _pending.front());
	_pending.erase(_pending.begin());

	printSequence(_sorted, "Updated sorted sequence: ", DEBUG);
	printSequence(_pending, "Remaining pending elements: ", DEBUG);
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
Generates the Jacobsthal sequence up to a given size 'n'
*/
template <typename Container>
inline Container	generateJacobsthalSequence(int n)
{
	Container	jacobsthalSequence;

	int	j = 0;
	while (jacobsthal(j) < n)
	{
		jacobsthalSequence.push_back(jacobsthal(j));
		++j;
	}
	if (jacobsthalSequence.empty() || jacobsthalSequence.back() != n)
		jacobsthalSequence.push_back(n); // add the last number
	// printSequence(jacobsthalSequence, "Jacobsthal numbers generated: ", DEBUG);
	
	return (jacobsthalSequence);
}


/*
Generates order of insertion for the pending elements
using the Jacobsthal number sequence
*/
template <typename Container>
inline Container	generateInsertionOrder(const Container &jacobsthalSequence)
{
	Container	insertOrder;
	typename Container::const_iterator	it = jacobsthalSequence.begin();

	while (it != jacobsthalSequence.end() - 1)
	{
		int	k = *(it + 1) - 1;
		while (k >= *it)
		{
			insertOrder.push_back(k);
			--k;
		}
		++it;
	}
	// size_t	i = 0;
	// while (i < jacobsthalSequence.size() - 1)
	// {
		// int	k = jacobsthalSequence[i + 1] - 1;
		// while (k >= jacobsthalSequence[i])
		// {
			// insertOrder.push_back(k);
			// --k;
		// }
		// i++;
	// }
	
	// printSequence(insertOrder, "Jacobsthal order generated: ", DEBUG);
	return (insertOrder);
}

/* ************************************************************************** */

/*
Finds the correct insertion point for a given element in a sorted range
*/
template <typename Iterator>
Iterator	binarySearchInsertionPoint(Iterator lowerBound, Iterator upperBound, int element, int &comparisons)
{
	while (lowerBound <= upperBound)
	{
		Iterator	mid = lowerBound + (std::distance(lowerBound, upperBound) / 2);
		
		comparisons++;

		if (element < *mid)
		{
			upperBound = mid - 1;
		}
		else if (element > *mid)
		{
			lowerBound = mid + 1;
		}
		else
		{
			return (mid); // exact match found
		}
	}
	return (lowerBound); // correct insertion point
}

/*
5. Insert the remaining [n/2] - 1 elements of X\S into S, one at a time,
with a specially chosen insertion ordering (jacobsthal sequence)

Use binary search in subsequences of S, to determine 
the position at which each element should be inserted

Only search in the range [0, 2^k - 1], where k is the Jacobsthal index // to implement *!!
*/
template <typename Container>
void	PmergeMe<Container>::insertRemainingElements(void)
{
	Container	jacobsthalSequence = generateJacobsthalSequence<Container>(_pending.size());
	
	Container	insertOrder = generateInsertionOrder<Container>(jacobsthalSequence);

	typename Container::const_iterator	it = insertOrder.begin();
	
	while (it != insertOrder.end())
	{
		int	elementIndex = *it;

		if (elementIndex < static_cast<int>(_pending.size()))
		{
			// int	jacobsthalIndex = jacobsthal(static_cast<int>(it - insertOrder.begin()));
			// std::cout << "jacobsthal index: " << jacobsthalIndex << std::endl;

			// int	upperBoundIndex = (1 << jacobsthalIndex) - 1; // 2^k - 1 adjusted for zero-indexing
			// std::cout << "upper bound index: " << upperBoundIndex << std::endl;
			
			// if (upperBoundIndex >= static_cast<int>(_sorted.size()))
			// 	upperBoundIndex = static_cast<int>(_sorted.size() - 1);
			
			// typename Container::iterator	upperBoundIt = _sorted.begin() + upperBoundIndex;
			typename Container::iterator	upperBoundIt = _sorted.end();
			typename Container::iterator	insertIt = binarySearchInsertionPoint(_sorted.begin(), upperBoundIt + 1, _pending[elementIndex], _comparisons);
			
			_sorted.insert(insertIt, _pending[elementIndex]);
		}
		++it;
	}
}

/* ************************************************************************** */

/*
creates pairs from _inputSequence
swaps to ensure the first element in the pair is larger
recursively sorts the pairs (currently using quicksort, might test other ways)
populates _sorted and _pending
inserts at the start of _sorted the first element in _pending
handles unpaired element if input size is odd
inserts remaining elements based on Jacobsthal sequence
*/
template <typename Container>
void	PmergeMe<Container>::mergeInsertionSort(void)
{
	createPairs();
	compareAndSwapPairs();
	sortPairs();
	generateSortedSequence();
	
	insertSmallestPairedElement();

	if (_inputSequence.size() % 2 != 0)
	{
		print("Remaining unpaired element placed in 'pending'");
		_pending.push_back(_inputSequence.back());
		printSequence(_pending, "Updated pending elements: ", DEBUG);
	}
	insertRemainingElements();

	std::string	good = (std::string(GREEN) + " (sorted) " + std::string(RESET));
	std::string bad = (std::string(RED) + " (not sorted) " + std::string(RESET));
	std::string	result = isSorted(_sorted) ? good : bad;	
	printSequence(_sorted, "Final" + result + "sequence: ", DEBUG);
}

template <typename Container>
void	PmergeMe<Container>::process(void)
{
	if (!_sorted.empty())
	{
		print((getContainerType() + " already processed"), YELLOW);
		return ;
	}
	if (_inputSequence.empty())
	{
		throw (std::logic_error("No input sequence to process"));
	}
	
	std::clock_t start = std::clock();
	
	print(("\nProcessing container " + getContainerType()), UNDERLINE);

	mergeInsertionSort();
	
	print("Comparisons: ", _comparisons);

	std::clock_t end = std::clock();
	_sortingTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;
}

template <typename Container>
void	PmergeMe<Container>::printTimeToSort(void) const
{
	std::string containerType(getContainerType());
	
	if (_inputSequence.empty())
	{
		print((getContainerType() + " input sequence not found"), YELLOW);
		// std::cout << containerType << " input sequence not found" << std::endl;
		return ;
	}
	// if (_sorted.empty() || !isSorted(_sorted))
	if (!isSorted(_sorted))
	{
		print((getContainerType() + " is unsorted"), YELLOW);
		// std::cout << containerType << " is unsorted" << std::endl;
		return ;
	}
	std::cout << std::fixed
		<< "Time to process a range of " << _inputSequence.size()
		<< " elements with " << containerType << " : "
		<< _sortingTime << " seconds" << std::endl;
}

#endif // PMERGEME_TPP
