/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:55:51 by cdumais           #+#    #+#             */
/*   Updated: 2024/08/24 00:05:38 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_TPP
# define PMERGEME_TPP

# include "PmergeMe.hpp"

/*
Fills the container with values from the list '_inputSequence'
*/
template <typename Container>
void	PmergeMe::setSequence(Container &seq)
{
	seq.assign(this->_inputSequence.begin(), this->_inputSequence.end());
}

template <typename Container>
std::vector<std::pair<int, int> >	PmergeMe::groupPairs(const Container &container) const
{
	std::vector<std::pair<int, int> >	pairs;
	typename Container::const_iterator	it = container.begin();

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
			// handling odd number of elements
			pairs.push_back(std::make_pair(first, first));
		}
	}
	return (pairs);
}

template <typename Container>
void	PmergeMe::printPairs(const Container &pairs) const
{
	typename Container::const_iterator	it = pairs.begin();
	
	while (it != pairs.end())
	{
		std::cout << "(" << it->first << ", " << it->second << ")" << std::endl;
		it++;
	}
}


/* ************************************************************************** */

template <typename C>
void	printSequence(const C &seq, const std::string &str)
{
	typename C::const_iterator	it = seq.begin();
	
	std::cout << str;
	while (it != seq.end())
	{
		std::cout << *it;
		if (++it != seq.end())
			std::cout << ", ";
	}
	std::cout << std::endl;
}

#endif // PMERGEME_TPP
