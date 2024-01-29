/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:36:59 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/29 11:50:31 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	std::cout << GRAYTALIC << "Cure default constructor" << RESET << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other)
{
	std::cout << GRAYTALIC << "Cure copy constructor" << RESET << std::endl;
}

Cure&	Cure::operator=(const Cure &other)
{
	AMateria::operator=(other);
	return (*this);
}

Cure::~Cure(void)
{
	std::cout << GRAYTALIC << "Cure default destructor" << RESET << std::endl;
}

/* ************************************************************************** */

AMateria*	Cure::clone(void) const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* " << GREEN << "heals " \
	<< target.getName() << "'s wounds" << RESET << " *" << std::endl;
}
