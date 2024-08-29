/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:56:01 by cdumais           #+#    #+#             */
/*   Updated: 2024/08/27 20:13:24 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <algorithm>
# include <cstdlib>
# include <cerrno>
# include <ctime>
# include <deque>
# include <iostream>
# include <limits>
# include <list>
# include <set>
# include <stdexcept>
# include <string>
# include <utility>
# include <vector>

# ifndef DEBUG
// #  define DEBUG	false	// 'make debug' target to toggle this and print debug messages
#  define DEBUG	true //tmp
# endif // DEBUG

class PmergeMe
{
	public:
		PmergeMe(void);
		PmergeMe(int argc, char *argv[]);
		PmergeMe(const PmergeMe &other);
		~PmergeMe(void);
		PmergeMe&	operator=(const PmergeMe &other);

		void	parseInput(int argc, char *argv[]);
		void	process(void);


		template <typename C>
		void	printSequence(const C &seq, const std::string &str, bool shouldPrint = true);

		template <typename C>
		void	printSequence(const C &seq, const std::string &str, int value, bool shouldPrint = true);

		template <typename Container>
		void	printPairs(const std::vector<typename Container::value_type> &pairs, const std::string &str, bool shouldPrint = true);

		// merge-insertion sort function for any container type
		template <typename Container>
		Container mergeInsertionSort(const Container &container);

		const std::list<int>	&getInputSequence(void) const;
		const std::vector<int>	&getVectorSequence(void) const;
		const std::deque<int>	&getDequeSequence(void) const;
	
	private:
		std::list<int>		_inputSequence;
		std::vector<int>	_vectorSequence;
		std::deque<int>		_dequeSequence;

		// calculates the nth Jacobsthal number
		int	jacobsthal(int n);

		// gets the order of pending elements using the Jacobsthal numbers
		std::vector<int>	getJacobsthalOrder(int n);


		// // merge-insertion sort function for any container type
		// template <typename Container>
		// Container mergeInsertionSort(const Container &container);

		// helper function to compare two elements
		template <typename Container>
		int	compareElements(const typename Container::value_type &a, const typename Container::value_type &b);

		template <typename T>
		int	compareElements(const T &a, const T &b);

		// binary search to find insertion point in a sorted container
		template <typename T, typename Container>
		int	binarySearchInsertionPoint(const T &element, const Container &container, int lowerBound, int upperBound);

		// inserts an element into a container at a specified position
		template <typename T, typename Container>
		Container	insertElement(const Container &container, const T &element, int position);

		// binary insert into a sorted container
		template <typename T, typename Container>
		Container	binaryInsert(const T &element, const Container &container);

		template <typename Container>
    	std::vector<typename Container::value_type> createPairs(const Container &container);

    	template <typename Container>
    	void splitMainAndPendingChains(const std::vector<typename Container::value_type> &sortedPairs, Container &mainChain, Container &pendingElements);
		
    	template <typename Container>
    	void applyJacobsthalOrder(Container &mainChain, const Container &pendingElements);

		std::vector<int>	processVector(double &duration);

		template <typename Container>
		void	setSequence(Container &seq);

		template <typename Container>
		void	printTime(const Container &container, const std::string &containerType, double time) const;

};

# include "PmergeMe.tpp"

#endif // PMERGEME_HPP
