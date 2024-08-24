/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:55:51 by cdumais           #+#    #+#             */
/*   Updated: 2024/08/23 15:57:29 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_TPP
# define PMERGEME_TPP

# include "PmergeMe.hpp"

/*
Starts with the first two terms of the Jacobsthal sequence: 0 and 1
Then, generates subsequent terms using the recurrence relation
J(n) = J(n-1) + 2 * J(n-2)
*/
template <typename T, typename Container>
Container	generateJacobsthalOrder(T size)
{
	Container	order;

	if (size < 1)
		return (order);

	order.push_back(0);
	if (size > 1)
		order.push_back(1);
	
	T	n1 = 0;
	T	n2 = 1;
	T	n3;

	T	i = 2;
	while (i <= size)
	{
		n3 = n2 + 2 * n1;
		order.push_back(n3);
		
		n1 = n2;
		n2 = n3;
		i++;
	}

	i = 1;
	while (i < size)
	{
		if (std::find(order.begin(), order.end(), i) == order.end())
		{
			order.push_back(i);
		}
		i++;
	}
	
	return (order);
}

#endif // PMERGEME_TPP
