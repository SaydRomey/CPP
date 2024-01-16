/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Integer.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:35:22 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/16 15:16:32 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Integer.class.hpp"
#include <iostream>

Integer::Integer(int const n) : _n(n)
{
	std::cout << "Integer constructor called with value " << n << std::endl;
	return;
}

Integer::~Integer(void)
{
	std::cout << "Destructor called with value " << this->_n << std::endl;
	return;
}

int	Integer::getValue(void) const
{
	return (this->_n);
}

Integer &	Integer::operator=(Integer const & rhs)
{
	std::cout << "Assignation operator called with " << this->_n;
	std::cout << " to " << rhs.getValue() << std::endl;

	this->_n = rhs.getValue();

	return (*this);
}

Integer		Integer::operator+(Integer const & rhs) const
{
	std::cout << "Addition operator called with " << this->_n;
	std::cout << " and " << rhs.getValue() << std::endl;

	return (Integer(this->_n + rhs.getValue()));
}

std::ostream & operator<<(std::ostream & o, Integer const & rhs)
{
	o << rhs.getValue();
	return (o);
}
