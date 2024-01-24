/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:10:08 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/24 17:42:50 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	_type = "Dog";
	_brain = new Brain();
	std::cout << "Dog default constructor" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	_brain = new Brain(*other._brain);
	std::cout << "Dog copy constructor" << std::endl;
}

Dog&	Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return (*this);
}

Dog::~Dog(void)
{
	delete _brain;
	std::cout << "Dog destructor" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Wouf Wouf" << std::endl;
}

/* ************************************************************************** */

void	Dog::setIdea(std::string idea, int index)
{
	this->_brain->setIdea(idea, index);
}
const std::string&	Dog::getIdea(int index) const
{
	return (this->_brain->getIdea(index));
}
