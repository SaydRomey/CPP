/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:15:54 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/23 18:58:28 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("")
{
	std::cout << "Animal default constructor" << std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout << "Animal copy constructor" << std::endl;
	*this = other;
}

Animal&	Animal::operator=(const Animal &other)
{
	if (this != &other)
		_type = other._type;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor" << std::endl;
}

void	Animal::makeSound(void) const
{
	std::cout << "Animal makes a sound" << std::endl;
}

std::string	Animal::getType(void) const
{
	return (_type);
}
