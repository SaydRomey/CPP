/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:09:38 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/24 20:06:18 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void)
{
	std::cout << "AMateria default constructor" << std::endl;
}

AMateria::AMateria(const std::string &type) : _type(type)
{
	// 
}


AMateria::AMateria(const AMateria &other)
{
	*this = other;
}

AMateria&	AMateria::operator=(const AMateria &other)
{
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria default destructor" << std::endl;
}

/* ************************************************************************** */

const std::string&	AMateria::getType(void) const
{
	return (_type);
}

void	AMateria::use(ICharacter &target)
{
	// General use case, can be overridden in derived classes
	(void) target;
}
