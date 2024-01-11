/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:54:43 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/11 13:32:48 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void)
{
	// 
}

Weapon::Weapon(const std::string type) : _type(type)
{
	// Weapon(); //instead of two methods ?
	// this->_type = type;  //instead of initializing after declaration?
}

Weapon::~Weapon(void)
{
	// 
}

const std::string	&Weapon::getType(void) const
{
	return (this->_type);
	// return (_type); //also works?
}

void	Weapon::setType(std::string newType)
{
	_type = newType;
	std::cout << " now equipping " << _type << std::endl;
}
