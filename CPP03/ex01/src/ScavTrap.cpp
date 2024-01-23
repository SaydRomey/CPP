/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:10:04 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/22 21:38:25 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* ************************************************************************** */
/* *********************************************** Constructors / Destructors */

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->_name = SCAVNAME;
	this->_hitPoints = SCAV_HP;
	this->_energyPoints = SCAV_EP;
	this->_attackDamage = SCAV_AD;
	std::cout << "Default " << *this << " constructed" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	this->_hitPoints = SCAV_HP;
	this->_energyPoints = SCAV_EP;
	this->_attackDamage = SCAV_AD;
	std::cout << *this << " has been constructed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &rhs) : ClapTrap()
{
	*this = rhs;
	this->_name.append("'s clone");
	std::cout << *this << " has been copy-constructed" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << *this << " has returned to the void" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap &rhs)
{
	if (_name.empty()) // when instance is copy constructed
		std::cout << "Copying " << rhs \
		<< "'s data in new shell" << std::endl;
	else
		std::cout << "Reformating " << *this \
		<< " with " << rhs << "'s data" << std::endl;
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
	if (isAble())
	{
		std::cout << *this << " attacks " << target << ", causing " \
		<< CYAN << _attackDamage << RESET << " points of damage" << std::endl;
		_energyPoints--;
		// std::cout << *this << "'s energy total is now " << _energyPoints << std::endl;
	}
	else
		isNotAble(" to attack");
}

void	ScavTrap::guardGate(void)
{
	std::cout << *this << " is now in Gate Keeper mode" << std::endl;
	std::cout << ORANGE << SCAV_MSG << RESET << std::endl;
}



/* ************************************************************************** */

std::ostream&	operator<<(std::ostream &out, ScavTrap const &rhs)
{
	out << rhs.getName();
	// out << "ScavTrap " << rhs.getName();
	return(out);
}
