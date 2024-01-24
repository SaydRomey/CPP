/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:35:33 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/23 19:28:38 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	WrongAnimal::_type = "WrongCat";
	std::cout << "WrongCat default constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other)
{
	*this = other;
	std::cout << "WrongCat copy constructor" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
		_type = other._type;
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat default destructor" << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Ptkptkptkptkptkptkptk" << std::endl;
}
