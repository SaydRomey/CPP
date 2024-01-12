/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:54:43 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/11 17:30:38 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string type) : _type(type)
{
	// this->_type = type;  //instead of initializing after declaration
	// _type = type; //also works
}

Weapon::~Weapon(void)
{
	// default destructor
}

const std::string	&Weapon::getType(void) const
{
	return (this->_type);
	// return (_type); //also works
}

void	Weapon::setType(std::string newType)
{
	_type = newType;
	std::cout << " now equipping " << _type << std::endl;
}
