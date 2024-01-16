/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:37:39 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/16 16:06:56 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sample.class.hpp"
#include <iostream>

Sample::Sample(void) : _value(0)
{
	std::cout << "Default constructor" << std::endl;
	return;
}

Sample::Sample(int const n) : _value(n)
{
	std::cout << "Parametric constructor" << std::endl;
	return;
}

Sample::Sample(Sample const & src)
{
	std::cout << "Copy constructor" << std::endl;
	*this = src;
	return;
}

Sample::~Sample(void)
{
	std::cout << "Sample destructor" << std::endl;
	return;
}

int	Sample::getValue(void) const
{
	return (this->_value);
}

Sample &	Sample::operator=(Sample const & rhs)
{
	std::cout << "Assignation operator called with " << this->_value;
	std::cout << " to " << rhs.getValue() << std::endl;

	this->_value = rhs.getValue();

	return (*this);
}

std::ostream & operator<<(std::ostream & o, Sample const & i)
{
	o << i.getValue();
	return (o);
}
