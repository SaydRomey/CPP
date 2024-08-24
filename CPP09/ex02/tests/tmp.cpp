/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:49:51 by cdumais           #+#    #+#             */
/*   Updated: 2024/08/23 20:07:20 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <algorithm>
# include <cstdlib>
# include <ctime>
# include <deque>
# include <iostream>
# include <set>
# include <stdexcept>
# include <string>
# include <utility>
# include <vector>

// Function to generate Jacobsthal numbers up to a given limit
std::vector<int> generateJacobsthalSequence(int limit)
{
	std::vector<int> jacobsthal;
	
	jacobsthal.push_back(0); // J_0
	if (limit > 0)
	{
		jacobsthal.push_back(1); // J_1
	}
	int	n = 2;
	while (jacobsthal.back() < limit)
	{
		int nextJacobsthal = jacobsthal[n - 1] + 2 * jacobsthal[n - 2];
		jacobsthal.push_back(nextJacobsthal);
		n++;
	}
	return (jacobsthal);
}

// Function to create pairs from the input sequence
std::vector<std::pair<int, int> > createPairs(const std::vector<int>& numbers, int& unpaired)
{
	std::vector<std::pair<int, int> > pairs;

	// Create pairs of adjacent elements
	size_t	i = 0;
	while (i + 1 < numbers.size())
	{
		int first = numbers[i];
		int second = numbers[i + 1];

		// Sort each pair
		if (first > second)
		{
			std::swap(first, second);
		}

		pairs.push_back(std::make_pair(first, second));
		i+= 2;
	}

	// Check if there's an unpaired element
	if (numbers.size() % 2 != 0)
	{
		unpaired = numbers.back(); // Store the last unpaired element
	}
	else
	{
		unpaired = -1; // Indicate no unpaired element
	}

	return (pairs);
}

// Recursive function to sort pairs
std::vector<std::pair<int, int> > sortPairsRecursively(std::vector<std::pair<int, int> >& pairs)
{
	// Base case: if the list of pairs is empty or has only one pair, return
	if (pairs.size() <= 1)
	{
		return (pairs);
	}

	// Split the list of pairs into two halves
	size_t mid = pairs.size() / 2;
	std::vector<std::pair<int, int> > left(pairs.begin(), pairs.begin() + mid);
	std::vector<std::pair<int, int> > right(pairs.begin() + mid, pairs.end());

	// Recursively sort each half
	left = sortPairsRecursively(left);
	right = sortPairsRecursively(right);

	// Merge the sorted halves
	std::vector<std::pair<int, int> > sortedPairs;
	size_t	i = 0;
	size_t	j = 0;
	while (i < left.size() && j < right.size())
	{
		if (left[i].first < right[j].first)
		{
			sortedPairs.push_back(left[i]);
			++i;
		}
		else
		{
			sortedPairs.push_back(right[j]);
			++j;
		}
	}

	// Add remaining pairs from left
	while (i < left.size())
	{
		sortedPairs.push_back(left[i]);
		++i;
	}

	// Add remaining pairs from right
	while (j < right.size())
	{
		sortedPairs.push_back(right[j]);
		++j;
	}

	return (sortedPairs);
}

// Function to merge sorted pairs into a single sorted list
std::vector<int> mergePairs(const std::vector<std::pair<int, int> >& pairs)
{
	std::vector<int> sorted;
	size_t	i = 0;
	while (i < pairs.size())
	{
		sorted.push_back(pairs[i].first);
		sorted.push_back(pairs[i].second);
		i++;
	}
	return (sorted);
}

// Function to insert an element using binary search
void insertUsingBinarySearch(std::vector<int>& sorted, int element)
{
	// Use binary search to find the correct insertion point
	std::vector<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), element);
	sorted.insert(it, element);
}

/* ************************************************************************** */

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


int	main(int argc, char *argv[])
{	
	if (argc < 2)
	{
		std::cout << "Error: No input sequence provided" << std::endl;
		return (1);
	}
	
	// Example input sequence
	std::vector<int> numbers = parseInput(argc, argv);

	// Display unsorted numbers
	std::cout << "Before: ";
	size_t	i = 0;
	while (i < numbers.size())
	{
		std::cout << numbers[i] << " ";
		i++;
	}
	std::cout << std::endl;

	// Variable to store the unpaired element, if any
	int	unpaired = -1;

	// Step 1: Pair the elements
	std::vector<std::pair<int, int> > pairs = createPairs(numbers, unpaired);

	// Step 2: Sort pairs recursively
	pairs = sortPairsRecursively(pairs);

	// Step 3: Merge sorted pairs into a list
	std::vector<int> sorted = mergePairs(pairs);

	// Step 4: If there's an unpaired element, insert it using binary search
	if (unpaired != -1)
	{
		insertUsingBinarySearch(sorted, unpaired);
	}

	// Step 5: Generate Jacobsthal sequence for guiding insertion (for larger datasets)
	int	limit = numbers.size();
	std::vector<int> jacobsthalSequence = generateJacobsthalSequence(limit);

	// Display sorted list
	std::cout << "After: ";
	i = 0;
	while (i < sorted.size())
	{
		std::cout << sorted[i] << " ";
		i++;
	}
	std::cout << std::endl;

	return (0);
}
