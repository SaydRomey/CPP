/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:10:04 by cdumais           #+#    #+#             */
/*   Updated: 2024/10/04 17:57:05 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int ScavTrap::_scavEP = SCAV_EP;

/* ************************************************************************** */
/* *********************************************** Constructors / Destructors */

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->_name = SCAVNAME;
	this->_hitPoints = SCAV_HP;
	this->_energyPoints = SCAV_EP;
	this->_attackDamage = SCAV_AD;
	// std::cout << "Default ScavTrap " << _name << " constructed" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	this->_hitPoints = SCAV_HP;
	this->_energyPoints = SCAV_EP;
	this->_attackDamage = SCAV_AD;
	// std::cout << "ScavTrap " << _name << " has been constructed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &rhs) : ClapTrap()
{
	*this = rhs;
	this->_name.append("'s clone");
	std::cout << "ScavTrap " << _name << " has been copy-constructed" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << _name << " has returned to the void" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap &rhs)
{
	if (_name.empty()) // when instance is copy constructed
		std::cout << "Copying " << rhs._name \
		<< "'s data in new shell" << std::endl;
	else
		std::cout << "Reformatting ScavTrap " << _name \
		<< " with ScavTrap " << rhs._name << "'s data" << std::endl;
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

void	ScavTrap::attack(const std::string &target)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " \
		<< CYAN << _attackDamage << RESET << " points of damage" << std::endl;
		_energyPoints--;
	}
	else
		std::cout << "ScavTrap " << _name << "can't attack" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << _name << " is now in Gate Keeper mode" << std::endl;
	std::cout << ORANGE << SCAV_MSG << RESET << std::endl;
}
