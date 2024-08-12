/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:19:35 by cdumais           #+#    #+#             */
/*   Updated: 2024/08/11 19:55:20 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_TPP
# define SPAN_TPP

# include "Span.hpp"

template <typename Iterator>
void	Span::addNumbers(Iterator begin, Iterator end)
{
	Iterator	it = begin;

	while (it != end)
	{
		addNumber(*it);
		it++;
	}
}

#endif // SPAN_TPP
