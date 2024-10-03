/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:14:52 by cdumais           #+#    #+#             */
/*   Updated: 2024/10/03 15:51:47 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# define UNDERLINE	"\033[4m"
# define RESET		"\033[0m"

# include <algorithm>
# include <iterator>
# include <iostream>
# include <limits>
# include <stdexcept>
# include <vector>

/*
"Develop a Span class that can store a maximum of N integers.
N is an unsigned int variable
and will be the only parameter passed to the constructor."
*/
class Span
{
	public:
		Span(void);
		Span(unsigned int N);
		// explicit Span(unsigned int N);
		Span(const Span &other);
		~Span(void);

		Span&	operator=(const Span &other);

		void	addNumber(int number);
		template <typename Iterator>
		void	addNumbers(Iterator begin, Iterator end);
		
		int		shortestSpan(void) const;
		int		longestSpan(void) const;

		const std::vector<int>&	getNumbers(void) const;

	private:
		std::vector<int>	_numbers;
		unsigned int		_maxSize;
};

template <typename Container>
void	printSequence(std::ostream &out, const Container &container);

std::ostream&	operator<<(std::ostream &out, const Span &param);

# include "Span.tpp"

#endif // SPAN_HPP
