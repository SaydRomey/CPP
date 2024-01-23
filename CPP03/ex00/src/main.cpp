/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:44:49 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/22 21:22:14 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <iomanip>

void	trapStat(const ClapTrap &rhs, std::string details = "")
{	
	std::cout << "/* ******************* */" << std::endl;
	std::cout << "Name\t\t" << rhs.getName() << std::endl;
	std::cout << "Hit Points\t" << rhs.getHitPoints() << std::endl;
	std::cout << "Energy Points\t" << rhs.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage\t" << rhs.getAttackDamage() << std::endl;
	if (!details.empty())
		std::cout << "Last Action\t" \
		<< ITALIC << GRAY << details << RESET << std::endl;
	std::cout << "/* ****************** */\n" << std::endl;
}

/* ************************************************************************** */
/* ****************************************************** Constructor testing */

void	testBasicConstructor(void)
{
	std::cout << ORANGE << "[Default and String]" << RESET << std::endl;

	ClapTrap	nameless; // will be named CLP-T4P
	ClapTrap	clappy("Clappy");

	std::cout << std::endl;
}

void	testCopyconstructor(void)
{
	std::cout << ORANGE << "[Copy]" << RESET << std::endl;

	ClapTrap	sloan("Sloan");
	ClapTrap	clone(sloan);

	std::cout << std::endl;
}

void	testAssignationOperator(void)
{
	std::cout << ORANGE << "[Assignation]" << RESET << std::endl;

	ClapTrap	nameless;
	ClapTrap	clappy("Clappy");
	
	nameless = clappy;

	std::cout << std::endl;
}

/* ************************************************************************** */
/* **************************************************** Member Functions Test */

void	testSnapFight(std::string name, \
	std::string color=PURPLE, std::string enemyColor=BOLD)
{
	std::string	colorName(color + name + RESET);
	std::string	enemy(enemyColor + "Enemy" + RESET);
	std::cout << "\n[ " << colorName << " VS " << enemy << " ]\n" << std::endl;

	ClapTrap	snap(colorName);
	trapStat(snap, ("Initialized " + snap.getName()));

	snap.attack(enemy);
	trapStat(snap, "Attacked an enemy");

	snap.takeDamage(8);
	trapStat(snap, "Took 8 damage");

	snap.beRepaired(4);
	trapStat(snap, "Healed some hp, but not all");
	
	snap.beRepaired(12);
	trapStat(snap, "Over healed"); // (caps at default)
	
	snap.beRepaired(1);
	trapStat(snap, "Tried healing when at full health");

	snap.attack(enemy); // spend remaining energy
	snap.attack(enemy);
	snap.attack(enemy);
	snap.attack(enemy);
	snap.attack(enemy);
	snap.attack(enemy);
	trapStat(snap, "Used up remaining energy points");

	snap.attack(enemy);
	snap.beRepaired(1);
	trapStat(snap, "Tried attacking and then healing with no energy");

	snap.takeDamage(9);
	trapStat(snap, "Took 9 damage"); // now at 1 hit point
	
	snap.takeDamage(42);
	trapStat(snap, "Took more damage than remaining hp"); // overkill (minimum hp is 0)
	
	snap.takeDamage(1);
	trapStat(snap, "Took damage when already at 0 hp");
}

int	main(void)
{
	// testBasicConstructor();
	// testCopyconstructor();
	// testAssignationOperator();

	testSnapFight("Snapp");

	return (0);
}
