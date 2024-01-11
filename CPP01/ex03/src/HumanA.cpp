/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:04:03 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/11 13:25:50 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// HumanA::HumanA(void)
// {
// 	// 
// }

HumanA::HumanA(const std::string name, Weapon& weapon) : _name(name), _weapon(weapon)
{
	std::cout << _name << " spawned with " << _weapon.getType() << std::endl;
	return;
}

HumanA::~HumanA(void)
{
	std::cout << _name << " returned to the void" << std::endl;
	return;
}

void	HumanA::attack(void) const
{
	std::cout << _name << " takes a swing with " << _weapon.getType() << std::endl;
	return;
}

