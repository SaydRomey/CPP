/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:32:55 by cdumais           #+#    #+#             */
/*   Updated: 2024/10/04 18:41:42 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>
#include <iomanip>

template <typename TrapObj>
void	trapStat(const TrapObj &obj, std::string details = "")
{	
	std::cout << "/* ******************* */" << std::endl;
	std::cout << "Name\t\t" << obj.getName() << std::endl;
	std::cout << "Hit Points\t" << obj.getHitPoints() << std::endl;
	std::cout << "Energy Points\t" << obj.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage\t" << obj.getAttackDamage() << std::endl;
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

	DiamondTrap	nameless; // will be named CLP-T4P
	DiamondTrap	clappy("Clappy");

	std::cout << std::endl;
}

void	testCopyconstructor(void)
{
	std::cout << ORANGE << "\n[Copy]" << RESET << std::endl;

	DiamondTrap	sloan("Sloan");
	DiamondTrap	clone(sloan);

	std::cout << std::endl;
}

void	testAssignationOperator(void)
{
	std::cout << ORANGE << "\n[Assignation]" << RESET << std::endl;

	DiamondTrap	nameless;
	DiamondTrap	clappy("Clappy");
	
	nameless = clappy;

	std::cout << std::endl;
}

/* ************************************************************************** */
/* **************************************************** Member Functions Test */

void	testSnapFight(std::string name, std::string color=PURPLE, std::string enemyColor=BOLD)
{
	std::string	colorName(color + name + RESET);
	std::string	enemy(enemyColor + "Enemy" + RESET);
	std::cout << "\n[ " << colorName << " VS " << enemy << " ]\n" << std::endl;

	DiamondTrap	snap(colorName);
	trapStat(snap, ("Constructed " + snap.getName()));

	snap.attack(enemy);
	trapStat(snap, "Attacked an enemy");

	snap.takeDamage(42);

	snap.whoAmI();
	std::cout << std::endl;
}

void	compareEachType(void)
{
	ClapTrap	ctrap("clap");
	ScavTrap	strap("scav");
	FragTrap	ftrap("frag");
	DiamondTrap	dtrap("diamond");
	trapStat(ctrap);
	trapStat(strap);
	trapStat(ftrap);
	trapStat(dtrap);

	dtrap.whoAmI();
	dtrap.attack("some enemy");

	std::cout << "\n" << std::endl;
}

int	main(void)
{
	// testBasicConstructor();
	// testCopyconstructor();
	// testAssignationOperator();

	compareEachType();
	
	testSnapFight("Snapp");
	
	return (0);
}
