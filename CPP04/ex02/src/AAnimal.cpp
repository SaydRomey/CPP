/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:06:44 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/24 13:08:24 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) : _type("")
{
	std::cout << "AAnimal default constructor" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
	std::cout << "AAnimal copy constructor" << std::endl;
	*this = other;
}

AAnimal&	AAnimal::operator=(const AAnimal &other)
{
	if (this != &other)
		_type = other._type;
	return (*this);
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal destructor" << std::endl;
}

// makeSound() implementation removed, is now a pure virtual function

std::string	AAnimal::getType(void) const
{
	return (_type);
}
