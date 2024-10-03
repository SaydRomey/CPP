/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:19:35 by cdumais           #+#    #+#             */
/*   Updated: 2024/10/03 15:48:54 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_TPP
# define SPAN_TPP

# include "Span.hpp"

/*
"[...] it would be wonderful to fill your Span using a range of iterators.
Making thousands calls to addNumber() is so annoying.
Implement a member function to add many numbers to your Span in one call."
*/
template <typename Iterator>
void	Span::addNumbers(Iterator begin, Iterator end)
{
	unsigned int	rangeSize = static_cast<unsigned int>(std::distance(begin, end));
	unsigned int	availableSpace = _maxSize - _numbers.size();

	if (rangeSize > availableSpace)
	{
		throw (std::out_of_range("Not enough space in Span to add all numbers"));
	}

	Iterator	it = begin;

	while (it != end)
	{
		addNumber(*it);
		++it;
	}
}

// struct AddNumber
// {
// 	Span	*span;
	
// 	AddNumber(Span *s) : span(s) {}

// 	void	operator()(int number)
// 	{
// 		span->addNumber(number);
// 	}
// };

// template <typename Iterator>
// void	Span::addNumbers(Iterator begin, Iterator end)
// {
// 	unsigned int	rangeSize = static_cast<unsigned int>(std::distance(begin, end));
// 	unsigned int	availableSpace = _maxSize - _numbers.size();

// 	if (rangeSize > availableSpace)
// 	{
// 		throw (std::out_of_range("Not enough space in Span to add all numbers"));
// 	}

// 	std::for_each(begin, end, AddNumber(this));

// 	// std::for_each(begin, end, [this](int number) {this->addNumber(number); });
// }

template <typename Container>
void	printSequence(std::ostream &out, const Container &container)
{
	if (container.empty())
	{
		out << "Sequence is empty.\n";
		return ;
	}

	if (container.size() == 1)
	{
		out << container[0] << "\n";
		return ;
	}

	std::ostream_iterator<int>	outIt(out, ", ");
	std::copy(container.begin(), container.end() - 1, outIt);
	out << container.back() << "\n";
}

#endif // SPAN_TPP
