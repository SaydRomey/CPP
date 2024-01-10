/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:59:42 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/10 18:26:25 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*horde = NULL;
	int		i = 0;
	
	if (N <= 0)
		return (NULL);

	horde = new Zombie[N];

	while (i < N)
	{
		horde[i].setName(name);
		std::cout << "[" << i << "]\t";
		horde[i].announce();
		i++;
	}
	return (&horde[0]);	
}
