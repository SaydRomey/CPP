/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:03:33 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/24 20:45:18 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

void	pdfTest(void)
{
	IMateriaSource*	src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter*	player = new Character("Player");
	AMateria*	tmp;

	tmp = src->createMateria("ice");
	player->equip(tmp);
	tmp = src->createMateria("cure");
	player->equip(tmp);

	ICharacter*	otherPlayer = new Character("Other Player");
	player->use(0, *otherPlayer);
	player->use(1, *otherPlayer);

	// testing unequip and floor Materia management
	player->unequip(0); //ice materia is now on the floor
	player->unequip(1); //cure materia is now on the floor
	
	// materias could be available for other characters to pickup or something else
	
	Character::clearFloorMaterias(); //cleaning up unequiped Materia

	delete player;
	delete otherPlayer;
	delete src;
}

void	additionalTest(void)
{
	IMateriaSource*	src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	// src->learnMateria(NULL); //

	ICharacter*	player = new Character("Player");
	ICharacter*	otherPlayer = new Character("Other Player");

	// test valid index but no Materia
	player->use(0, *otherPlayer);

	AMateria*	ice = src->createMateria("ice");
	AMateria*	cure = src->createMateria("cure");
	AMateria*	unknown = src->createMateria("fire"); // edge case: unknown Materia

	player->equip(ice);
	player->equip(cure);
	player->equip(unknown); // should do nothing (need to add check for inventory capacity?)

	// fill inventory and test adding to full inventory !** this causes a segfault !!
	// player->equip(ice);
	// player->equip(cure);
	// player->equip(ice); // should be ignored

	// test using and unequipping non-existing Materias
	player->use(4, *otherPlayer);
	player->unequip(4);

	// test using valid Materias
	player->use(0, *otherPlayer);
	player->use(1, *otherPlayer);

	// testing unequip and floor Materia management
	player->unequip(0); //ice materia is now on the floor
	player->unequip(1); //cure materia is now on the floor

	// test using and unequiping empty Materia slot
	player->use(0, *otherPlayer);
	player->unequip(0);

	// reusing unequipped slot !** also causes a segfault
	// player->equip(ice);
	// player->use(0, *otherPlayer); //should use ice
	
	Character::clearFloorMaterias(); //cleaning up unequiped Materia

	delete player;
	delete otherPlayer;
	delete src;
}


int	main(void)
{
	pdfTest();

	// additionalTest(); //wip
	
	return (0);
}

/*	Materia in FFVII

Cure Materia: Allows characters to cast healing spells like Cure, Cura, and Curaga.

Ice Materia: Enables the casting of ice-based spells like Ice, Ice2, and Ice3.

Fire Materia: Similar to Ice, but for fire-based spells like Fire, Fire2, and Fire3.

Lightning Materia: Allows characters to cast lightning-based spells like Bolt, Bolt2, and Bolt3.

Restore Materia: Another healing Materia, similar to Cure, often used to restore HP.

Revive Materia: Grants abilities to resurrect fallen party members, like Life and Life2.

Barrier Materia: Provides protective spells like Barrier and MBarrier, which increase defense against physical and magical attacks.

Time Materia: Grants time-related spells like Haste (speeds up a character), Slow (slows down an enemy), and Stop (freezes an enemy).

Summon Materia: Unique in that they allow characters to summon powerful creatures for attacks, like Ifrit, Shiva, and Bahamut.

All Materia: Used in combination with other Materias to extend their effects to all targets or party members.

Enemy Skill Materia: Enables characters to learn and use certain abilities used by enemies.

Counter Materia: Used for counterattacking when a character is hit by a physical attack.
*/