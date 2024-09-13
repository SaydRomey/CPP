/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:56:01 by cdumais           #+#    #+#             */
/*   Updated: 2024/09/13 16:09:42 by cdumais          ###   ########.fr       */
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
# include <iterator>
# include <limits>
# include <list>
# include <set>
# include <sstream>
# include <stdexcept>
# include <string>
# include <utility>
# include <vector>

# define RESET		"\033[0m"
# define RED		"\033[91m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define PURPLE		"\033[95m"
# define ORANGE		"\033[38;5;208m"
# define GRAYTALIC	"\033[3;90m"

# ifndef DEBUG
#  define DEBUG	false	// 'make debug' to toggle this and print debug messages
# endif // DEBUG

// general template for type trait
template <typename T>
struct is_vector
{
	static const bool	value = false;
};

template <typename T>
struct is_deque
{
	static const bool	value = false;
};

// specialization for std::vector
template <typename T, typename Alloc>
struct is_vector<std::vector<T, Alloc> >
{
	static const bool	value = true;
};

// specialization for std::deque
template <typename T, typename Alloc>
struct is_deque<std::deque<T, Alloc> >
{
	static const bool	value = true;
};

// general template for mapping a container type to a container of pairs of int
template <typename Container>
struct PairType;

// specialisation for std::vector<int>
template <>
struct PairType<std::vector<int> >
{
	typedef std::vector<std::pair<int, int>	> type;
};

// specialisation for std::deque
template <>
struct PairType<std::deque<int> >
{
	typedef std::deque<std::pair<int, int> > type;
};

template <typename Container>
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
		
		const Container&	getInputSequence(void) const;
		const Container&	getSortedSequence(void) const;
		const double&		getSortingTime(void) const;
	
	private:

		typedef typename PairType<Container>::type PairContainer;
	
		Container		_inputSequence;
		
		PairContainer	_pairs;
		Container		_sorted;
		Container		_pending;

		double	_sortingTime;
		
		int		_comparisons;
		void	incrementComparisons(void);
		
		// Ford-Johnson's algorithm
		void	createPairs(void);
		void	compareAndSwapPairs(void);
		void	sortPairs(void);
		void	generateSortedSequence(void);
		void	insertSmallestPairedElement(void);
		void	insertRemainingElements(void);
		void	mergeInsertionSort(void);
};

template <typename Container>
void	printSequence(const Container &container, const std::string &str, bool shouldPrint = true);

template <typename PairContainer>
void	printPairs(const PairContainer &pairs, const std::string &str, bool shouldPrint = true);

template <typename Container>
void	printTime(const Container &container, double time);

void	print(const std::string &str, const std::string &color = GRAYTALIC);
void	print(const std::string &str, int value, const std::string &color = GRAYTALIC);
// void	printTime(const size_t &containerSize, const std::string &containerType, double time);

# include "PmergeMe.tpp"
# include "printUtils.tpp"

#endif // PMERGEME_HPP
