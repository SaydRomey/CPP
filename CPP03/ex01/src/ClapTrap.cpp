/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:51:14 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/22 23:15:52 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

/* ************************************************************************** */
/* *********************************************** Constructors / Destructors */

ClapTrap::ClapTrap(void) : \
_name(CLAPNAME), \
_hitPoints(CLAP_HP), \
_energyPoints(CLAP_EP), \
_attackDamage(CLAP_AD)
{
	std::cout << "Default ClapTrap " << _name << " constructed" << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : \
_name(name), \
_hitPoints(CLAP_HP), \
_energyPoints(CLAP_EP), \
_attackDamage(CLAP_AD)
{
	std::cout << "ClapTrap " << _name << " has been constructed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	_name = src._name;
	this->_name.append("'s clone");
	std::cout << "ClapTrap" << _name << " has been copy-constructed" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << _name << " has returned to the void" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap &rhs)
{
	if (_name.empty()) // when instance is copy constructed
		std::cout << "Copying ClapTrap " << rhs._name \
		<< "'s data in new shell" << std::endl;
	else
		std::cout << "Reformating " << "ClapTrap " << _name \
		<< " with " << "ClapTrap " << rhs._name << "'s data" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

/* ************************************************************************** */
/* ********************************************************* Member functions */

void	ClapTrap::attack(const std::string &target)
{
	if (isAble())
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " \
		<< CYAN << _attackDamage << RESET << " points of damage" << std::endl;
		_energyPoints--;
	}
	else
		isNotAble(" to attack");
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " takes " \
		<< RED << amount << RESET << " points of damage!" << std::endl;
		_hitPoints -= amount;
		if (_hitPoints <= 0)
		{
			std::cout << "The attack was fatal..." << std::endl;
			_hitPoints = 0;
		}
	}
	else
		isNotAble();
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (isAble())
	{
		if (_hitPoints == CLAP_HP)
			std::cout << "ClapTrap " << _name << " is at full health" << std::endl;
		else if ((_hitPoints + amount) >= CLAP_HP)
		{
			std::cout << "ClapTrap " << _name << " is back at full health" << std::endl;
			_hitPoints = CLAP_HP;
		}
		else
		{
			_hitPoints += amount;
			std::cout << "ClapTrap " << _name << " repairs " \
			<< GREEN << amount << RESET << " damage" << std::endl;
			// std::cout << _name << "'s life total is now " << _hitPoints << std::endl;
		}
		_energyPoints--;
		// std::cout << _name << "'s energy total is now " << _energyPoints << std::endl;
	}
	else
		isNotAble(" to repair itself");
}

/* ************************************************************************** */
/* **************************************************************** Accessors */

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

/* ************************************************************************** */

bool	ClapTrap::isAble(void) const
{
	return ((this->_hitPoints > 0) && (this->_energyPoints > 0));
}

void	ClapTrap::isNotAble(std::string str) const
{
	if (str.empty())
		str = "";
	if (_hitPoints == 0)
		std::cout << "ClapTrap " << _name << " is out of commission..." << std::endl;
	else if (_energyPoints == 0)
		std::cout << "ClapTrap " << _name << " has no energy left" << str << std::endl;
}
