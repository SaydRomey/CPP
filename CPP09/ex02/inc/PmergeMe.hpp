/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:56:01 by cdumais           #+#    #+#             */
/*   Updated: 2024/08/24 00:06:33 by cdumais          ###   ########.fr       */
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

class PmergeMe
{
	public:
		PmergeMe(void);
		PmergeMe(int argc, char *argv[]);
		PmergeMe(const PmergeMe &other);
		~PmergeMe(void);
		PmergeMe&	operator=(const PmergeMe &other);

		void	parseInput(int argc, char *argv[]);

		void	process(void); // tmp function to test stuff
		
		
		
		const std::list<int>	&getInputSequence(void) const;
		const std::vector<int>	&getVectorSequence(void) const;
		const std::deque<int>	&getDequeSequence(void) const;
	
	private:
		std::list<int>		_inputSequence;
		std::vector<int>	_vectorSequence;
		std::deque<int>		_dequeSequence;

		template <typename Container>
		void		setSequence(Container &seq);

		template <typename Container>
		std::vector<std::pair<int, int> >	groupPairs(const Container &container) const;

		template <typename Container>
		void	printPairs(const Container &pairs) const;

};

template <typename C>
void	printSequence(const C &seq, const std::string &str);

# include "PmergeMe.tpp"

#endif // PMERGEME_HPP
