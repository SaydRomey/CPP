/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:09:13 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/24 15:23:14 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	std::cout << "MateriaSource default constructor" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	*this = other;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource &other)
{
	// if (this != &other)
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	std::cout << "MateriaSource default destructor" << std::endl;
}

/*
#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; ++i)
        templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &src) {
    for (int i = 0; i < 4; ++i) {
        if (src.templates[i])
            templates[i] = src.templates[i]->clone();
        else
            templates[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource &rhs) {
    if (this != &rhs) {
        for (int i = 0; i < 4; ++i) {
            delete templates[i];
            if (rhs.templates[i])
                templates[i] = rhs.templates[i]->clone();
            else
                templates[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; ++i)
        delete templates[i];
}

void MateriaSource::learnMateria(AMateria* m) {
    for (int i = 0; i < 4; ++i) {
        if (templates[i] == NULL) {
            templates[i] = m;
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; ++i) {
        if (templates[i] && templates[i]->getType() == type)
            return templates[i]->clone();
    }
    return NULL;
}
*/
/*
#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; ++i)
        learnedMaterias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &source) {
    *this = source;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &source) {
    if (this != &source) {
        for (int i = 0; i < 4; ++i) {
            delete learnedMaterias[i];
            learnedMaterias[i] = source.learnedMaterias[i] ? source.learnedMaterias[i]->clone() : NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; ++i)
        delete learnedMaterias[i];
}

void MateriaSource::learnMateria(AMateria* m) {
    for (int i = 0; i < 4; ++i) {
        if (learnedMaterias[i] == NULL) {
            learnedMaterias[i] = m;
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; ++i) {
        if (learnedMaterias[i] && learnedMaterias[i]->getType() == type)
            return learnedMaterias[i]->clone();
    }
    return NULL;
}
*/