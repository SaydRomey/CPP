/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:10:28 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/24 13:14:12 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : AAnimal()
{
	_type = "Cat";
	_brain = new Brain();
	std::cout << "Cat default constructor" << std::endl;
}

Cat::Cat(const Cat &other) : AAnimal(other)
{
	_brain = new Brain(*other._brain);
	std::cout << "Cat copy constructor" << std::endl;
}

Cat&	Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		AAnimal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);	
	}
	return (*this);
}

Cat::~Cat(void)
{
	delete _brain;
	std::cout << "Cat destructor" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}
