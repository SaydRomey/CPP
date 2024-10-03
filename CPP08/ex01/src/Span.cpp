/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:26:56 by cdumais           #+#    #+#             */
/*   Updated: 2024/10/03 15:51:21 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _maxSize(0) {}

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span &other) : _maxSize(other._maxSize)
{
	*this = other;
}

Span::~Span(void) {}

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

/*
"This class will have a member function called addNumber()
to add a single number to the Span.
It will be used in order to fill it.

Any attempt to add a new element if there are already N elements stored
should throw an exception."
*/
void	Span::addNumber(int number)
{
	if (_numbers.size() >= _maxSize)
	{
		throw (std::out_of_range("Span is already full"));
	}
	_numbers.push_back(number);
}

/*
"[...] find out the shortest span (or distance, if you prefer)
between all the numbers stored, and return it.

If there are no numbers stored, or only one, no span can be found.
Thus, throw an exception."
*/
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

// int	Span::shortestSpan(void) const
// {
// 	if (_numbers.size() < 2)
// 	{
// 		throw (std::logic_error("Not enough numbers to find a span"));
// 	}
	
// 	std::vector<int>	sorted = _numbers;
// 	std::sort(sorted.begin(), sorted.end());
	
// 	std::vector<int>	diffs(sorted.size() - 1);
	
// 	// substracting each element from the next one
// 	std::transform(sorted.begin() + 1, sorted.end(), sorted.begin(), diffs.begin(), std::minus<int>());

// 	return (*std::min_element(diffs.begin(), diffs.end()));
// }

/*
"[...] find out the longest span (or distance, if you prefer)
between all the numbers stored, and return it.

If there are no numbers stored, or only one, no span can be found.
Thus, throw an exception."
*/
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

const std::vector<int>&	Span::getNumbers(void) const
{
	return (this->_numbers);
}

std::ostream&	operator<<(std::ostream &out, const Span &param)
{
	const std::vector<int>	&numbers(param.getNumbers());
	
	if (numbers.empty())
	{
		out << "Span is empty.\n";
	}
	else
	{
		size_t	size = numbers.size();

		std::cout << UNDERLINE << "Span of " << size << " numbers" << RESET << "\n";
		
		// print the numbers
		// std::ostream_iterator<int>	outIt(out, ", ");
		// std::copy(numbers.begin(), numbers.end() - 1, outIt);
		// out << numbers.back();
		// out << "\n";

		printSequence(std::cout, numbers);

		// size_t	i = 0;
		// while (i < numbers.size())
		// {
		// 	out << numbers[i];
		// 	if (i < numbers.size() - 1)
		// 	{
		// 		out << ", ";
		// 	}
		// 	++i;
		// }
		// out << "\n";

		// print the shortest and longest spans
		try
		{
			out << "Shortest span: " << param.shortestSpan() << "\n";
			out << "Longest span:  " << param.longestSpan() << "\n";
		}
		catch (const std::exception &e)
		{
			out << "Error: " << e.what() << "\n";
		}
	}
	
	return (out);
}
