/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:26:56 by cdumais           #+#    #+#             */
/*   Updated: 2024/10/04 16:21:52 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* ************************************************************************** */ // Constructors / Destructors

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

/* ************************************************************************** */ // Getters / Setters

const std::vector<int>&	Span::getNumbers(void) const
{
	return (this->_numbers);
}

const	bool&	Span::getPrintNumbers(void) const
{
	return (this->_printNumbers);
}

void	Span::setPrintNumbers(bool print)
{
	_printNumbers = print;
}

/* ************************************************************************** */ // Functions / Methods

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

/* ************************************************************************** */ // Operators

std::ostream&	operator<<(std::ostream &out, const Span &param)
{
	const std::vector<int>	&numbers(param.getNumbers());
	
	if (numbers.empty())
	{
		out << "Span object is empty.\n";
	}
	else
	{
		if (param.getPrintNumbers())
		{
			printSequence(std::cout, numbers);
		}
		try
		{
			int	shortest = param.shortestSpan();
			int	longest = param.longestSpan();
			
			out << "Shortest span: " << shortest << "\n";
			out << "Longest span:  " << longest << "\n";
		}
		catch (const std::exception &e)
		{
			out << e.what() << "\n";
		}
	}
	return (out);
}

/* ************************************************************************** */ // Utils

/*
helper function to fill a vector with either sequential or random numbers
*/
void	fillVector(std::vector<unsigned int> &vec, unsigned int numElements, bool sequential)
{
	vec.clear();

	if (!sequential)
	{
		std::srand(static_cast<unsigned int>(std::time(0)));

		unsigned int	i = 0;
		while (i < numElements)
		{
			vec.push_back(std::rand()); // adding random numbers
			++i;
		}
	}
	else
	{
		unsigned int	i = 0;
		while (i < numElements)
		{
			vec.push_back(i + 1); // adding sequential numbers
			++i;
		}
	}
}

/*
wrapper function to output with ANSI escape sequences (defined in Span.hpp)
*/
void	print(const std::string &str, const std::string &color)
{
	std::cout << color << str << RESET << std::endl;
}

