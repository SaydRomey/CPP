/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:14:52 by cdumais           #+#    #+#             */
/*   Updated: 2024/10/04 15:21:48 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# define RESET		"\033[0m"
# define UNDERLINE	"\033[4m"
# define RED		"\033[91m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define ORANGE		"\033[38;5;208m"
# define BLUE		"\033[94m"
# define PURPLE		"\033[95m"
# define GRAYTALIC	"\033[3;90m"

# include <algorithm>
# include <iterator>
# include <iostream>
# include <limits>
# include <stdexcept>
# include <stdlib.h>
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
		Span(const Span &other);
		~Span(void);

		Span&	operator=(const Span &other);

		const std::vector<int>&	getNumbers(void) const;
		const	bool&			getPrintNumbers(void) const;
		void					setPrintNumbers(bool print);

		void	addNumber(int number);
		
		template <typename Iterator>
		void	addNumbers(Iterator begin, Iterator end);
		
		int		shortestSpan(void) const;
		int		longestSpan(void) const;

	private:
		std::vector<int>	_numbers;
		unsigned int		_maxSize;
		bool	_printNumbers;
};

std::ostream&	operator<<(std::ostream &out, const Span &param);

void	fillVector(std::vector<unsigned int> &vec, unsigned int numElements, bool sequential);

void	print(const std::string &str, const std::string &color = GRAYTALIC);

template <typename Container>
void	printSequence(std::ostream &out, const Container &container, const std::string &color = GRAYTALIC);

# include "Span.tpp"

#endif // SPAN_HPP
