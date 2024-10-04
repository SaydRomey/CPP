/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:36:20 by cdumais           #+#    #+#             */
/*   Updated: 2024/10/04 18:40:19 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	_name = DIAMNAME;
	ClapTrap::_name.append("_clap_name");
	_hitPoints = FragTrap::_fragHP;
	_energyPoints = ScavTrap::_scavEP;
	_attackDamage = FragTrap::_fragAD;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	_name = DIAMNAME;
	ClapTrap::_name.append("_clap_name");
	_hitPoints = FragTrap::_fragHP;
	_energyPoints = ScavTrap::_scavEP;
	_attackDamage = FragTrap::_fragAD;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src)
{
	ClapTrap::_name.append("_clap_name");
	*this = src;
	this->_name.append("'s clone");
	std::cout << "DiamondTrap " << _name << " has been copy-constructed" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << _name << " has returned to the void" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap &rhs)
{
	if (_name.empty())
		std::cout << "Copying " << rhs._name \
		<< "'s data in new shell" << std::endl;
	else
		std::cout << "Reformatting " << _name \
		<< " with DiamondTrap " << rhs._name << "'s data" << std::endl;
	if (this != &rhs)
	{
		FragTrap::operator=(rhs);
		ScavTrap::operator=(rhs);
		_name = rhs._name;
	}
	std::cout << "DiamonTrap assignement operator" << std::endl;
	return (*this);
}

// void	DiamondTrap::attack(const std::string &target)
// {
// 	ScavTrap::attack(target);
// }

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap's name:\t" << _name << std::endl;
	std::cout << "ClapTrap's name:\t" << ClapTrap::_name << std::endl;
}
