/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:14:52 by cdumais           #+#    #+#             */
/*   Updated: 2024/07/26 14:19:23 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <stdexcept>

class Span
{
	public:
		Span(void);
		Span(unsigned int N);
		~Span(void);

		void	addNumber(int number);
		template <typename Iterator>
		void	addNumbers(Iterator begin, Iterator end);
		int		shortestSpan(void) const;
		int		longestSpan(void) const;

	private:
		std::vector<int>	_numbers;
		unsigned int		_maxSize;
};

# include "Span.tpp"

#endif // SPAN_HPP
