/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stlt2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:25:51 by cdumais           #+#    #+#             */
/*   Updated: 2024/07/26 12:29:50 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <list>

void	displayInt(int i)
{
	std::cout << i << std::endl;
}

int	main(void)
{
	std::list<int>	lst;

	lst.push_back(10);
	lst.push_back(23);
	lst.push_back(3);
	lst.push_back(17);
	lst.push_back(20);

	for_each(lst.begin(), lst.end(), displayInt);

	return (0);
}
