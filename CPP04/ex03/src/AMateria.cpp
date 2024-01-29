/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:09:38 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/29 13:16:15 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void)
{
	std::cout << GRAYTALIC << "AMateria default constructor" \
	<< RESET << std::endl;
}

AMateria::AMateria(const std::string &type) : _type(type)
{
	std::cout << GRAYTALIC << "AMateria '" \
	<< _type << "' param(string) constructor" << RESET << std::endl;
}


AMateria::AMateria(const AMateria &other)
{
	*this = other;
	std::cout << GRAYTALIC << "AMateria copy constructor" \
	<< RESET << std::endl;
}

AMateria&	AMateria::operator=(const AMateria &other)
{
	if (this != &other)
		this->_type = other._type;
	return (*this);
	std::cout << GRAYTALIC << "AMateria assignation overload" \
	<< RESET << std::endl;
}

AMateria::~AMateria(void)
{
	std::cout << GRAYTALIC << "AMateria default destructor" \
	<< RESET << std::endl;
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
