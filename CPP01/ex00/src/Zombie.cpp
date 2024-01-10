/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:33:25 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/09 21:01:50 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(const std::string name)
{
	_name = name;
	std::cout << _name << " constructed" << std::endl;
	return;
}

Zombie::~Zombie(void)
{
	std::cout << _name << " destroyed" << std::endl;
	return;
}

void	Zombie::announce(void)
{
	std::cout << _name << Z_MSG << std::endl;
}
