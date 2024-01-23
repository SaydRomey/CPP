/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:09:32 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/22 21:35:33 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>
#include <iomanip>

void	trapStat(const ScavTrap &rhs, std::string details = "")
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
	std::cout << ORANGE << "\n[Default and String]" << RESET << std::endl;

	ScavTrap	nameless; // will be named CLP-T4P
	ScavTrap	clappy("Clappy");

	std::cout << std::endl;
}

void	testCopyconstructor(void)
{
	std::cout << ORANGE << "\n[Copy]" << RESET << std::endl;

	ScavTrap	sloan("Sloan");
	ScavTrap	clone(sloan);

	std::cout << std::endl;
}

void	testAssignationOperator(void)
{
	std::cout << ORANGE << "\n[Assignation]" << RESET << std::endl;

	ScavTrap	nameless;
	ScavTrap	clappy("Clappy");
	
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

	ScavTrap	snap(colorName);
	trapStat(snap, (snap.getName() + " was constructed"));

	snap.attack(enemy);
	trapStat(snap, "Attacked an enemy");

	snap.guardGate();

	snap.takeDamage(42);
}

int	main(void)
{
	// testBasicConstructor();
	// testCopyconstructor();
	// testAssignationOperator();

	testSnapFight("Snapp");

	return (0);
}
