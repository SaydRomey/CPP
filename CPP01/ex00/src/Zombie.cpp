/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:33:25 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/10 17:34:42 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(const std::string name)
{
	_name = name;
	// std::cout << _name << " constructed" << std::endl;
	return;
}

/*
Zombies must be destroyed when you don’t need them anymore.
The destructor must print a message
with the name of the zombie for debugging purposes.
*/
Zombie::~Zombie(void)
{
	std::cout << ORANGE << _name << " destroyed" << RESET << std::endl;
	return;
}

void	Zombie::announce(void)
{
	std::cout << _name << GREEN << Z_MSG << RESET << std::endl;
}
