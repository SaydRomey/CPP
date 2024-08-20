/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:56:01 by cdumais           #+#    #+#             */
/*   Updated: 2024/08/20 00:54:55 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <algorithm>
# include <cstdlib>
# include <ctime>
# include <deque>
# include <iostream>
# include <set>
# include <stdexcept>
# include <string>
# include <vector>

# include "Jacobsthal.hpp"

class PmergeMe
{
	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe &other);
		~PmergeMe(void);
		PmergeMe&	operator=(const PmergeMe &other);

		void	setSequence(const std::vector<int> &seq);
		void	mergeInsertSort(std::vector<int> &vec);
		void	mergeInsertSort(std::deque<int> &deq);
		void	displayResults(void) const;
	
	private:
		std::vector<int>	_sequence;
		std::vector<int>	_sortedVector;
		std::deque<int>		_sortedDeque;
		double				_vectorTime;
		double				_dequeTime;

		void	sortAndMeasureVector(void);
		void	sortAndMeasureDeque(void);

		void	mergeInsertSortImpl(std::vector<int> &seq);
		void	mergeInsertSortImpl(std::deque<int> &seq);

		template <typename T>
		size_t	binarySearchPosition(T &mainChain, typename T::value_type element);
};

std::vector<int>	parseInput(int argc, char *argv[]);

#endif // PMERGEME_HPP
