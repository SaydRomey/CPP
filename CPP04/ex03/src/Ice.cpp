/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:08:31 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/24 15:08:36 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void)
{
	std::cout << "Ice default constructor" << std::endl;
}

Ice::Ice(const Ice &other)
{
	*this = other;
}

Ice&	Ice::operator=(const Ice &other)
{
	// if (this != &other)
	return (*this);
}

Ice::~Ice(void)
{
	std::cout << "Ice default destructor" << std::endl;
}

/*
#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &other) : AMateria(other) {}

Ice& Ice::operator=(const Ice &other) {
    AMateria::operator=(other);
    return *this;
}

Ice::~Ice() {}

AMateria* Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
*/