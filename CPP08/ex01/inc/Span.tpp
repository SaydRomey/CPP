/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:19:35 by cdumais           #+#    #+#             */
/*   Updated: 2024/07/26 15:44:06 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_TPP
# define SPAN_TPP

# include "Span.hpp"

template <typename Iterator>
void	Span::addNumbers(Iterator begin, Iterator end)
{
	while (begin != end)
	{
		addNumber(*begin++);
	}
}

#endif // SPAN_TPP
