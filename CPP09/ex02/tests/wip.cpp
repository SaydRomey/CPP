/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wip.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 20:47:41 by cdumais           #+#    #+#             */
/*   Updated: 2024/08/29 15:42:46 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>
#include <utility>
#include <ctime>

template <typename Container>
Container PmergeMe::mergeInsertionSort(const Container &container)
{
    // Base case: if the container has fewer than 2 elements, return it as is
    if (container.size() < 2)
    {
        return container;
    }

    // Step 1: Create pairs from the input container
    std::vector<std::pair<int, int>> pairs = createPairs(container);
    printPairs<std::vector<std::pair<int, int>> >(pairs, "Pairs created: ", DEBUG);

    // Step 2: Recursively sort the larger elements of each pair to create the mainChain
    Container mainChain;
    Container pendingElements;
    mainChain = recursivelySortLargerElements(pairs, pendingElements);

    // Step 3: Insert the first pending element into the start of the mainChain
    insertFirstPendingElement(mainChain, pendingElements);

    // Debug prints to track the main chain and pending elements after sorting
    printSequence(mainChain, "Main Chain after splitting: ", DEBUG);
    printSequence(pendingElements, "Pending elements after splitting: ", DEBUG);

    // Step 4: Apply Jacobsthal order (assuming this is a defined step elsewhere)
    applyJacobsthalOrder(mainChain, pendingElements);

    // Final debug print to show the main chain after all insertions
    printSequence(mainChain, "Final Main Chain after all insertions: ", DEBUG);

    return mainChain;
}

// Example implementations for processVector and process functions

std::vector<int> PmergeMe::processVector(double &duration)
{
    std::clock_t start = std::clock();

    setSequence(this->_vectorSequence);

    std::vector<int> sortedSequence = mergeInsertionSort(_vectorSequence);

    std::clock_t end = std::clock();
    duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    return sortedSequence;
}

void PmergeMe::process(void)
{
    printSequence(getInputSequence(), "Before: ");

    double vectorTime;
    std::vector<int> sortedSequence = processVector(vectorTime);

    printSequence(sortedSequence, "After: ");
    printTime(_vectorSequence, "std::vector", vectorTime);
}

/* ************************************************************************** */

#include <vector>
#include <deque>
#include <utility> // For std::make_pair

template <typename Container>
std::vector<std::pair<int, int>> PmergeMe::createPairs(const Container& container)
{
    std::vector<std::pair<int, int>> pairs;
    typename Container::const_iterator it = container.begin();

    while (it != container.end())
    {
        int first = *it;
        ++it;
        if (it == container.end())
        {
            // Handle odd value case, mark it with -1 as a placeholder
            pairs.push_back(std::make_pair(first, -1));
            break;
        }

        int second = *it;
        ++it;

        // Create pair with (larger, smaller)
        if (first < second)
        {
            std::swap(first, second);
        }

        pairs.push_back(std::make_pair(first, second));
    }
    return pairs;
}

template <typename Container>
Container PmergeMe::recursivelySortLargerElements(const std::vector<std::pair<int, int>>& pairs, Container& pendingElements)
{
    Container mainChain;

    // Base case: if no pairs, return empty mainChain
    if (pairs.empty()) {
        return mainChain;
    }

    // Process pairs one at a time
    int larger = pairs[0].first;
    int smaller = pairs[0].second;

    if (smaller != -1) {
        // Normal pair processing
        pendingElements.push_back(smaller);  // Add smaller value to pendingElements
    } else {
        // Handle odd value
        pendingElements.push_back(larger);  // The odd value
        return mainChain;  // No need to sort odd value
    }

    // Recursively call the function to process remaining pairs
    std::vector<std::pair<int, int>> remainingPairs(pairs.begin() + 1, pairs.end());
    mainChain = recursivelySortLargerElements(remainingPairs, pendingElements);

    // Insert the larger value into the sorted position in mainChain
    typename Container::iterator it = mainChain.begin();
    while (it != mainChain.end() && *it < larger) {
        ++it;
    }
    mainChain.insert(it, larger);

    return mainChain;
}

template <typename Container>
void PmergeMe::insertFirstPendingElement(Container& mainChain, Container& pendingElements)
{
    if (!pendingElements.empty()) {
        // Remove the first value from pendingElements
        int firstPending = pendingElements.front();
        pendingElements.pop_front();

        // Insert it at the start of mainChain
        mainChain.push_front(firstPending);
    }
}

...
std::deque<int> sequence = {3, 1, 5, 4, 2, 7};  // Example sequence
std::deque<int> pendingElements;
PmergeMe pmergeMeInstance;

// Step 1: Create pairs
std::vector<std::pair<int, int>> pairs = pmergeMeInstance.createPairs(sequence);

// Step 2: Recursively sort larger elements and populate pendingElements
std::deque<int> sortedSequence = pmergeMeInstance.recursivelySortLargerElements(pairs, pendingElements);

// Step 3: Insert the first value of pendingElements at the start of sortedSequence
pmergeMeInstance.insertFirstPendingElement(sortedSequence, pendingElements);
...
