/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:26:56 by cdumais           #+#    #+#             */
/*   Updated: 2024/08/11 19:55:33 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _maxSize(0)
{
	// 
}

Span::Span(unsigned int N) : _maxSize(N)
{
	// 
}

Span::Span(const Span &other) : _maxSize(other._maxSize)
{
	*this = other;
}

Span::~Span(void)
{
	// 
}

Span&	Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_numbers.clear();
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return (*this);
}

void	Span::addNumber(int number)
{
	if (_numbers.size() >= _maxSize)
	{
		throw (std::out_of_range("Span is already full"));
	}
	_numbers.push_back(number);
}

int	Span::shortestSpan(void) const
{
	if (_numbers.size() < 2)
	{
		throw (std::logic_error("Not enough numbers to find a span"));
	}
	std::vector<int>	sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());
	int		shortest = std::numeric_limits<int>::max();
	size_t	i = 1;
	while (i < sorted.size())
	{
		int	span = sorted[i] - sorted[i - 1];
		if (span < shortest)
		{
			shortest = span;
		}
		i++;
	}
	return (shortest);
}

int	Span::longestSpan(void) const
{
	if (_numbers.size() < 2)
	{
		throw (std::logic_error("Not enough numbers to find a span"));
	}
	int	min = *std::min_element(_numbers.begin(), _numbers.end());
	int	max = *std::max_element(_numbers.begin(), _numbers.end());
	return (max - min);
}
