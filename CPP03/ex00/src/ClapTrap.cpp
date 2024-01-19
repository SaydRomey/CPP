/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:51:14 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/18 21:43:03 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

// TODO: add "ClapTrap " in front of _name everywhere... ?

ClapTrap::ClapTrap(void) : _name(CLAPNAME), _hitPoints(CLAP_HP), _energyPoints(CLAP_EP), _attackDamage(CLAP_AD)
{
	std::cout << "Default " << CLAPNAME << " constructed" << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : _name(name), _hitPoints(CLAP_HP), _energyPoints(CLAP_EP), _attackDamage(CLAP_AD)
{
	std::cout << _name << " has been constructed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	*this = src;
	_name.append("'s clone");
	std::cout << _name << " has been copy-constructed" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << _name << " has returned to the void" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap &rhs)
{
	if (_name.empty())
		std::cout << "Copying " << rhs._name \
		<< "'s data in new shell" << std::endl;
	else
		std::cout << "Reformating " << _name \
		<< " with " << rhs._name << "'s data" << std::endl;
	if (this != &rhs)
	{
		// _name = (rhs._name + "'s doppleganger"); //?
		_name = rhs._name;
		_hitPoints = rhs._hitPoints;
		_energyPoints = rhs._energyPoints;
		_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

// causes its target to lose <attack damage> hit points
// Attacking and repairing cost 1 energy point each
// can't do anything if it has no hit points or energy points left
void	ClapTrap::attack(const std::string &target)
{
	if (isAble())
	{
		std::cout << "ClapTrap " << _name << " attacks " << target \
		<< ", causing " << _attackDamage << " points of damage" << std::endl;
		_energyPoints--; // uses 1 point of energy to attack
	}
	else
		isNotAble();
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " takes " \
		<< amount << " points of damage!" << std::endl;
		_hitPoints -= amount;
		if (_hitPoints <= 0)
		{
			std::cout << "The attack was fatal..." << std::endl;
			_hitPoints  = 0;
		}
		std::cout << _name << "'s life total is now " << _hitPoints << std::endl;
	}
	else
		isNotAble();
}

// gets <amount> hit points back
// Attacking and repairing cost 1 energy point each
// can't do anything if it has no hit points or energy points left
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (isAble())
	{
		if (_hitPoints == CLAP_HP)
			std::cout << _name << " is at full health" << std::endl;
		else if ((_hitPoints + amount) >= CLAP_HP)
		{
			std::cout << _name << " is back at full health" << std::endl;
			_hitPoints = CLAP_HP;
		}
		else
		{
			_hitPoints += amount;
			std::cout << _name << " repairs " << amount << " damage" << std::endl;
			std::cout << _name << "'s life total is now " << _hitPoints << std::endl;
		}
		_energyPoints--;
	}
	else
		isNotAble();
}

const std::string	&ClapTrap::getName(void) const
{
	return (this->_name);
}

const int	&ClapTrap::getHitPoints(void) const
{
	return (this->_hitPoints);
}

const int	&ClapTrap::getEnergyPoints(void) const
{
	return (this->_energyPoints);
}

const int	&ClapTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}

bool	ClapTrap::isAble(void)
{
	return ((_hitPoints > 0) && (_energyPoints > 0));
}

void	ClapTrap::isNotAble(void)
{
	if (_hitPoints == 0)
		std::cout << _name << " is out of commission..." << std::endl;
	if (_energyPoints == 0)
		std::cout << _name << " has no energy left ..." << std::endl;
	// ...no energy left to [repair/attack](with isNotAble(std::string str)) ?
}

void	ClapTrap::printStats(void)
{
	// std::cout << "-------- " << getName() << " --------" << std::endl;
	std::cout << "//" << std::endl;
	std::cout << "Name:\t\t" << getName() << std::endl;
	std::cout << "Hit Points:\t" << getHitPoints() << std::endl;
	std::cout << "Energy Points:\t" << getEnergyPoints() << std::endl;
	std::cout << "Attack Damage:\t" << getAttackDamage() << std::endl;
	std::cout << "//" << std::endl;
}
