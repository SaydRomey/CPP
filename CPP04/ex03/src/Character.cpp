/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:08:02 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/24 15:16:55 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void)
{
	std::cout << "Character default constructor" << std::endl;
}

Character::Character(const Character &other)
{
	*this = other;
}

Character&	Character::operator=(const Character &other)
{
	// if (this != &other)
	return (*this);
}

Character::~Character(void)
{
	std::cout << "Character default destructor" << std::endl;
}

/*
#include "Character.hpp"
#include <iostream>

Character::Character(const std::string &name) : name(name) {
    for (int i = 0; i < 4; ++i)
        inventory[i] = NULL;
}

Character::Character(const Character &src) : name(src.name) {
    for (int i = 0; i < 4; ++i) {
        if (src.inventory[i])
            inventory[i] = src.inventory[i]->clone();
        else
            inventory[i] = NULL;
    }
}

Character& Character::operator=(const Character &rhs) {
    if (this != &rhs) {
        name = rhs.name;
        for (int i = 0; i < 4; ++i) {
            delete inventory[i];
            if (rhs.inventory[i])
                inventory[i] = rhs.inventory[i]->clone();
            else
                inventory[i] = NULL;
        }
    }
    return *this;
}

Character::~Character() {
    for (int i = 0; i < 4; ++i)
        delete inventory[i];
}

std::string const & Character::getName() const {
    return name;
}

void Character::equip(AMateria* m) {
    for (int i = 0; i < 4; ++i) {
        if (inventory[i] == NULL) {
            inventory[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4)
        inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && inventory[idx] != NULL)
        inventory[idx]->use(target);
}
*/

/*	using fixed size array for floorMateria (will probably not use this)

#include "Character.hpp"

int Character::floorMateriaCount = 0;
AMateria* Character::floorMaterias[Character::maxFloorMaterias] = {NULL};

// ... [Other methods implementations]

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4 && inventory[idx] != NULL && floorMateriaCount < maxFloorMaterias) {
        floorMaterias[floorMateriaCount++] = inventory[idx];
        inventory[idx] = NULL;
    }
}

void Character::clearFloorMaterias() {
    for (int i = 0; i < floorMateriaCount; ++i) {
        delete floorMaterias[i];
        floorMaterias[i] = NULL;
    }
    floorMateriaCount = 0;
}

// ... [Rest of the implementation]
*/

/*	using a linked list for floorMateria

#include "Character.hpp"

MateriaNode* Character::floorMateriaHead = NULL;

// ... [Other methods implementations]

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4 && inventory[idx] != NULL) {
        MateriaNode* node = new MateriaNode(inventory[idx]);
        node->next = floorMateriaHead;
        floorMateriaHead = node;
        inventory[idx] = NULL;
    }
}

void Character::clearFloorMaterias() {
    MateriaNode* current = floorMateriaHead;
    while (current != NULL) {
        MateriaNode* next = current->next;
        delete current->materia;
        delete current;
        current = next;
    }
    floorMateriaHead = NULL;
}

// ... [Rest of the implementation]
*/

/*	updated version

#include "Character.hpp"

struct MateriaNode {
    AMateria* materia;
    MateriaNode* next;

    MateriaNode(AMateria* m) : materia(m), next(NULL) {}
};

MateriaNode* Character::floorMateriaHead = NULL;

Character::Character(const std::string &name) : name(name) {
    for (int i = 0; i < 4; ++i)
        inventory[i] = NULL;
}

Character::Character(const Character &src) : name(src.name) {
    for (int i = 0; i < 4; ++i) {
        if (src.inventory[i])
            inventory[i] = src.inventory[i]->clone();
        else
            inventory[i] = NULL;
    }
}

Character& Character::operator=(const Character &rhs) {
    if (this != &rhs) {
        name = rhs.name;
        for (int i = 0; i < 4; ++i) {
            delete inventory[i];
            if (rhs.inventory[i])
                inventory[i] = rhs.inventory[i]->clone();
            else
                inventory[i] = NULL;
        }
    }
    return *this;
}

Character::~Character() {
    for (int i = 0; i < 4; ++i)
        delete inventory[i];
    clearFloorMaterias();
}

std::string const & Character::getName() const {
    return name;
}

void Character::equip(AMateria* m) {
    for (int i = 0; i < 4; ++i) {
        if (inventory[i] == NULL) {
            inventory[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4 && inventory[idx] != NULL) {
        MateriaNode* node = new MateriaNode(inventory[idx]);
        node->next = floorMateriaHead;
        floorMateriaHead = node;
        inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && inventory[idx] != NULL)
        inventory[idx]->use(target);
}

void Character::clearFloorMaterias() {
    MateriaNode* current = floorMateriaHead;
    while (current != NULL) {
        MateriaNode* next = current->next;
        delete current->materia;
        delete current;
        current = next;
    }
    floorMateriaHead = NULL;
}
*/