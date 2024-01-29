/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:09:13 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/29 13:26:39 by cdumais          ###   ########.fr       */
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
	std::cout << GRAYTALIC << "MateriaSource default constructor" \
	<< RESET << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cout << GRAYTALIC << "MateriaSource copy constructor" \
	<< RESET << std::endl;
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
			// _learnedMaterias[i] = other._learnedMaterias[i] ? other._learnedMaterias[i]->clone() : NULL;
			if (other._learnedMaterias[i])
				_learnedMaterias[i] = other._learnedMaterias[i]->clone();
			else
				_learnedMaterias[i] = NULL;
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
	std::cout << GRAYTALIC << "MateriaSource default destructor" \
	<< RESET << std::endl;
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
			std::cout << "Materia '" << m->getType() \
			<< "' placed in Materia slot " << i << std::endl;
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
	std::cout << "Invalid Materia" << std::endl;
	return (NULL);
}
