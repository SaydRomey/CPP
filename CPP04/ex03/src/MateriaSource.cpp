/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:09:13 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/24 19:50:26 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	int	i = 0;
	while (i < 4)
	{
		_learnedMaterias[i] = NULL;
		i++;
	}
	std::cout << "MateriaSource default constructor" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	*this = other;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		int	i = 0;
		while (i < 4)
		{
			delete _learnedMaterias[i];
			_learnedMaterias[i] = other._learnedMaterias[i] ? other._learnedMaterias[i]->clone() : NULL;
			i++;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	int	i = 0;
	while (i < 4)
	{
		delete _learnedMaterias[i];
		i++;
	}
	std::cout << "MateriaSource default destructor" << std::endl;
}

/* ************************************************************************** */

void	MateriaSource::learnMateria(AMateria* m)
{
	int	i = 0;
	while (i < 4)
	{
		if (_learnedMaterias[i] == NULL)
		{
			_learnedMaterias[i] = m;
			// message about learned materia?
			break;
		}
		i++;
	}
}

AMateria*	MateriaSource::createMateria(const std::string &type)
{
	int	i = 0;
	while (i < 4)
	{
		if (_learnedMaterias[i] && _learnedMaterias[i]->getType() == type)
			return (_learnedMaterias[i]->clone());
		i++;
	}
	return (NULL);
}
