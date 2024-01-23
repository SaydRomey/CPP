/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:30:52 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/22 23:32:29 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/* ************************************************************************** */
/* *********************************************** Constructors / Destructors */

FragTrap::FragTrap(void) : ClapTrap()
{
	this->_name = FRAGNAME;
	this->_hitPoints = FRAG_HP;
	this->_energyPoints = FRAG_EP;
	this->_attackDamage = FRAG_AD;
	std::cout << "Default FragTrap " << _name << " constructed" << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	this->_hitPoints = FRAG_HP;
	this->_energyPoints = FRAG_EP;
	this->_attackDamage = FRAG_AD;
	std::cout << "FragTrap " << _name << " has been constructed" << std::endl;
}

FragTrap::FragTrap(const FragTrap &rhs) : ClapTrap()
{
	*this = rhs;
	this->_name.append("'s clone");
	std::cout << "FragTrap " << _name << " has been copy-constructed" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << _name << " has returned to the void" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap &rhs)
{
	if (_name.empty()) // when instance is copy constructed
		std::cout << "Copying FragTrap " << rhs._name \
		<< "'s data in new shell" << std::endl;
	else
		std::cout << "Reformating FragTrap " << _name \
		<< " with FragTrap " << rhs._name << "'s data" << std::endl;
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

void	FragTrap::attack(const std::string &target)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout << "FragTrap " << _name << " attacks " << target << ", causing " \
		<< CYAN << _attackDamage << RESET << " points of damage" << std::endl;
		_energyPoints--;
	}
	else
		std::cout << "FragTrap " << _name << "can't attack" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " requests a positive high five!" << std::endl;
	// std::cout << ORANGE << FRAG_MSG << RESET << std::endl;
}
