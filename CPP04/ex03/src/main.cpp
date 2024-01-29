/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:03:33 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/29 13:30:29 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

using std::string;
using std::ostringstream;
using std::cout;
using std::endl;

#define RESET	"\033[0m"
#define PURPLE	"\033[95m"
#define ORANGE	"\033[38;5;208m"

void	print(string str, string color=ORANGE)
{
	cout << color << "\n[ " << str << " ]" << RESET << endl;
}


void	pdfTest(void)
{
	print("*** PDF TEST ***", PURPLE);

	print("IMateriaSource* src = new MateriaSource()");
	IMateriaSource*	src = new MateriaSource();
	print("src->learnMateria(new Ice())");
	src->learnMateria(new Ice());
	print("src->learnMateria(new Cure())");
	src->learnMateria(new Cure());

	print("ICharacter* player = new Character(\"Player\")");
	ICharacter*	player = new Character("Player");

	print("AMateria* tmp");
	AMateria*	tmp;

	print("tmp = src->createMateria(\"ice\")");
	tmp = src->createMateria("ice");
	print("player->equip(tmp)");
	player->equip(tmp);
	print("tmp = src->createMateria(\"cure\")");
	tmp = src->createMateria("cure");
	print("player->equip(tmp)");
	player->equip(tmp);

	print("ICharacter* otherPlayer = new Character(\"Other Player\")");
	ICharacter*	otherPlayer = new Character("Other Player");

	print("player->use(0, *otherPlayer)");
	player->use(0, *otherPlayer);
	print("player->use(0, *otherPlayer)");
	player->use(0, *otherPlayer);
	print("player->use(1, *otherPlayer)");
	player->use(1, *otherPlayer);

	print("player->use(2, *otherPlayer)");
	player->use(2, *otherPlayer);
	print("player->use(42, *otherPlayer)");
	player->use(42, *otherPlayer);

	// testing unequip and floor Materia management
	print("player->unequip(0)");
	player->unequip(0);
	print("player->unequip(1)");
	player->unequip(1);
	print("player->unequip(1)");
	player->unequip(1); // unequip pre unequipped slot
	
	// materias could be available for other characters to pickup or something else ?
	
	print("Character::clearFloorMaterias()");
	Character::clearFloorMaterias(); //cleaning up unequiped Materia

	print("delete player");
	delete player;
	print("delete otherPlayer");
	delete otherPlayer;
	print("delete src");
	delete src;
	print("end of 'pdfTest'");
}

int	main(void)
{
	pdfTest();
	
	return (0);
}
