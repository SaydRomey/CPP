/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:08:02 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/29 13:11:43 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

struct MateriaNode
{
	AMateria*		materia;
	MateriaNode*	next;

	MateriaNode(AMateria* m) : materia(m), next(NULL) {}
};

MateriaNode*	Character::_floorMateriaHead = NULL;

/* ************************************************************************** */

Character::Character(void) : _name("")
{
	int	i = 0;
	while (i < 4)
	{
		_inventory[i] = NULL;
		i++;
	}
	std::cout << GRAYTALIC << "Character default constructor" \
	<< RESET << std::endl;
}

Character::Character(const std::string &name) : _name(name)
{
	int	i = 0;
	while (i < 4)
	{
		_inventory[i] = NULL;
		i++;
	}
	std::cout << GRAYTALIC << "Character param(string) constructor: " \
	<< _name << RESET << std::endl;
}

Character::Character(const Character &other) : _name(other._name)
{
	int	i = 0;
	while (i < 4)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
		i++;
	}
	*this = other;
	std::cout << GRAYTALIC << "Character copy constructor" \
	<< _name << RESET << std::endl;
}

Character&	Character::operator=(const Character &other)
{
	if (this != &other)
	{
		_name = other._name;
		int	i = 0;
		while (i < 4)
		{
			delete _inventory[i];
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = NULL;
			i++;
		}
	}
	return (*this);
}

Character::~Character(void)
{
	int	i = 0;
	while (i < 4)
	{
		delete _inventory[i];
		i++;
	}
	clearFloorMaterias();
	std::cout << GRAYTALIC << "Character default destructor" \
	<< RESET << std::endl;
}

/* ************************************************************************** */

const std::string&	Character::getName(void) const
{
	return (_name);
}
		
void	Character::equip(AMateria* m)
{
	int	i = 0;
	while (i < 4)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			std::cout << "Equipped '" << m->getType() \
			<< "' in Character slot " << i << std::endl;
			break;
		}
		i++;
	}
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && _inventory[idx] != NULL)
	{
		MateriaNode*	node = new MateriaNode(_inventory[idx]);
		node->next = _floorMateriaHead;
		_floorMateriaHead = node;
		std::cout << "unequipped '" << _inventory[idx]->getType() \
		<< "' from Character slot " << idx << std::endl;
		_inventory[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && _inventory[idx] != NULL)
		_inventory[idx]->use(target);
}

void	Character::clearFloorMaterias(void)
{
	MateriaNode*	current = _floorMateriaHead;
	while (current != NULL)
	{
		MateriaNode*	next = current->next;
		delete current->materia;
		delete current;
		current = next;
	}
	_floorMateriaHead = NULL;
}
