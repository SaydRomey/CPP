/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:09:38 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/24 15:09:43 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void)
{
	std::cout << "AMateria default constructor" << std::endl;
}

AMateria::AMateria(const AMateria &other)
{
	*this = other;
}

AMateria&	AMateria::operator=(const AMateria &other)
{
	// if (this != &other)
	return (*this);
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria default destructor" << std::endl;
}

/*
#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : type(type) {}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const { 
    return type; 
}

void AMateria::use(ICharacter& target) {
    // General use case, can be overridden in derived classes
}
*/