/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:06:07 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/11 20:09:04 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string name) : _name(name), _weapon(NULL)
{
	std::cout << _name << " spawned unarmed " << std::endl;
	return;
}

HumanB::~HumanB(void)
{
	std::cout << _name << " returned to the void" << std::endl;
	return;
}

void	HumanB::attack(void) const
{
	if (_weapon)
		std::cout << _name << " takes a swing with " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " needs a weapon"  << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	if (_weapon)
		std::cout << _name << " dropped " << _weapon->getType() << std::endl;
	_weapon = &weapon;
	std::cout << _name << " equipped " << _weapon->getType() << std::endl;
}
