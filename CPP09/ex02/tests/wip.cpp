/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wip.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 20:47:41 by cdumais           #+#    #+#             */
/*   Updated: 2024/08/23 23:55:11 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_TPP
# define PMERGEME_TPP

# include "PmergeMe.hpp"

template <typename C>
void	printSequence(const C &seq, const std::string &str)
{
	typename C::const_iterator it = seq.begin();
	
	std::cout << str;
	while (it != seq.end())
	{
		if (it != seq.begin())
			std::cout << ", ";
		std::cout << *it;
		++it;
	}
	std::cout << std::endl;
}

template <typename Container>
std::vector<std::pair<int, int> > PmergeMe::groupPairs(const Container &container) const
{
	std::vector<std::pair<int, int> > pairs;
	typename Container::const_iterator it = container.begin();

	while (it != container.end())
	{
		int first = *it;
		++it;
		if (it != container.end())
		{
			int second = *it;
			pairs.push_back(std::make_pair(first, second));
			++it;
		}
		else
		{
			// Handle the case where there is an odd number of elements
			pairs.push_back(std::make_pair(first, first));
		}
	}

	return pairs;
}

template <typename Container>
void PmergeMe::printPairs(const Container &pairs) const
{
	for (typename Container::const_iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		std::cout << "(" << it->first << ", " << it->second << ")" << std::endl;
	}
}

#endif // PMERGEME_TPP


#include "PmergeMe.hpp"

int	main(int argc, char *argv[])
{	
	if (argc < 2)
	{
		std::cout << "Error: No input sequence provided" << std::endl;
		return (1);
	}

	try
	{
		std::vector<int> inputVector = parseInput(argc, argv);

		// Convert vector to list
		std::list<int> inputList(inputVector.begin(), inputVector.end());

		PmergeMe sorter;
		sorter.setSequence(inputList);

		printSequence(sorter.getSequence(), "List Sequence: ");

		// Group and print pairs using the list sequence
		std::vector<std::pair<int, int> > pairs = sorter.groupPairs(sorter.getSequence());
		std::cout << "Grouped Pairs:" << std::endl;
		sorter.printPairs(pairs);

	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}

//

template <typename Container>
std::vector<std::pair<typename Container::value_type, typename Container::value_type>> PmergeMe::groupPairs(const Container &container) const
{
    // Define the pair type based on the container's value type
    typedef typename Container::value_type ValueType;
    typedef std::pair<ValueType, ValueType> PairType;

    // Create a vector to store pairs
    std::vector<PairType> pairs;

    // Use an iterator to go through the container
    typename Container::const_iterator it = container.begin();

    while (it != container.end())
    {
        ValueType first = *it;
        ++it;
        if (it != container.end())
        {
            ValueType second = *it;
            pairs.push_back(std::make_pair(first, second));
            ++it;
        }
        else
        {
            // Handle the case where there is an odd number of elements
            pairs.push_back(std::make_pair(first, first));
        }
    }

    return pairs;
}

/*
// Group and print pairs using the list sequence
std::vector<std::pair<int, int>> vectorPairs = sorter.groupPairs(inputVector);
std::cout << "Grouped Pairs from Vector:" << std::endl;
sorter.printPairs(vectorPairs);
*/

////

template <typename Container, typename ValueType>
std::vector<std::pair<ValueType, ValueType>> PmergeMe::groupPairs(const Container &container) const
{
    // Define the pair type explicitly
    typedef std::pair<ValueType, ValueType> PairType;

    // Create a vector to store pairs
    std::vector<PairType> pairs;

    // Use an iterator to go through the container
    typename Container::const_iterator it = container.begin();

    while (it != container.end())
    {
        ValueType first = *it;
        ++it;
        if (it != container.end())
        {
            ValueType second = *it;
            pairs.push_back(std::make_pair(first, second));
            ++it;
        }
        else
        {
            // Handle the case where there is an odd number of elements
            pairs.push_back(std::make_pair(first, first));
        }
    }

    return pairs;
}

/*
// Group and print pairs using the list sequence
std::vector<std::pair<int, int>> vectorPairs = sorter.groupPairs<std::vector<int>, int>(inputVector);
sorter.printPairs(vectorPairs);
*/

////

template <template <typename, typename> class PairContainer, typename Container>
PairContainer<std::pair<typename Container::value_type, typename Container::value_type>, std::allocator<std::pair<typename Container::value_type, typename Container::value_type>>>
PmergeMe::groupPairs(const Container &container) const
{
    typedef typename Container::value_type ValueType;
    typedef std::pair<ValueType, ValueType> PairType;

    PairContainer<PairType, std::allocator<PairType>> pairs;

    typename Container::const_iterator it = container.begin();

    while (it != container.end())
    {
        ValueType first = *it;
        ++it;
        if (it != container.end())
        {
            ValueType second = *it;
            pairs.push_back(std::make_pair(first, second));
            ++it;
        }
        else
        {
            pairs.push_back(std::make_pair(first, first));
        }
    }

    return pairs;
}

