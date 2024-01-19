/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:44:49 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/18 21:44:51 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

void	title(std::string str, std::string color = ORANGE)
{
	std::cout << color << str << RESET << std::endl;
}

void	testBasicConstructor(void)
{
	title("[Default and String]");

	ClapTrap	nameless; // will be named CLP-T4P
	ClapTrap	clappy("Clappy");	
}

void	testCopyconstructor(void)
{
	title("[Copy]");

	ClapTrap	sloan("Sloan");
	ClapTrap	clone(sloan);
}

void	testAssignationOperator(void)
{
	title("[Assignation]");

	ClapTrap	nameless; // will be named CLP-T4P
	ClapTrap	clappy("Clappy");
	
	nameless = clappy;
}

void	testSnapFight(void)
{
	ClapTrap	snap("Snap");
	std::string	enemy("Enemy-string");

	title("[ " + snap.getName() + " VS " + enemy + " ]");

	snap.printStats();

	snap.attack(enemy);
	snap.printStats();

	snap.takeDamage(8);
	snap.printStats();

	snap.beRepaired(4); // heal some hp, but not all
	snap.printStats();
	
	snap.beRepaired(12); // over heal (caps at default)
	snap.printStats();
	
	snap.beRepaired(1); // heal when at full health
	snap.printStats();

	snap.attack(enemy); // using up remaining energy points
	snap.attack(enemy);
	snap.attack(enemy);
	snap.attack(enemy);
	snap.attack(enemy);
	snap.attack(enemy);
	snap.printStats(); // now at 0 energy points

	snap.attack(enemy);
	snap.beRepaired(1); // heal when at full health and no energy

	snap.takeDamage(9);
	snap.printStats(); // now at 1 hit point
	
	snap.takeDamage(9);
	snap.printStats(); // overkill (minimum hp is 0)
	
	snap.takeDamage(1); // damage when already at 0 hp
}

int	main(void)
{
	// testing the constructors
	/*
	testBasicConstructor();
	std::cout << std::endl;
	testCopyconstructor();
	std::cout << std::endl;
	testAssignationOperator();
	std::cout << std::endl;
	*/

	testSnapFight();


	return (0);
}
