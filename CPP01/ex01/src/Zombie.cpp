/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:48:45 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/10 18:22:25 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	// std::cout << _name << " constructed" << std::endl;
	return;
}

Zombie::Zombie(const std::string name)
{
	_name = name;
	return;
}

Zombie::~Zombie(void)
{
	std::cout << ORANGE << _name << " destroyed" << RESET << std::endl;
	return;
}

void	Zombie::setName(const std::string name)
{
	_name = name;
}

void	Zombie::announce(void) const
{
	std::cout << _name << GREEN << Z_MSG << RESET << std::endl;
}
