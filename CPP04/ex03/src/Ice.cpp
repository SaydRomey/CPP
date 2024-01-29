/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:08:31 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/29 11:50:44 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
	std::cout << GRAYTALIC << "Ice default constructor" << RESET << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other)
{
	std::cout << GRAYTALIC << "Ice copy constructor" << RESET << std::endl;
}

Ice&	Ice::operator=(const Ice &other)
{
	AMateria::operator=(other);
	return (*this);
}

Ice::~Ice(void)
{
	std::cout << GRAYTALIC << "Ice default destructor" << RESET << std::endl;
}

/* ************************************************************************** */

AMateria*	Ice::clone(void) const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* " << CYAN << "shoots an ice bolt at " \
	<< target.getName() << RESET << " *" << std::endl;
}
