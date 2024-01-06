/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:24:32 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/06 18:14:09 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"

Sample::Sample(int v) : _privateValue(v)
{
	std::cout << "Constructor called" << std::endl;
	return;
}

Sample::~Sample(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

int		Sample::getValue(void) const
{
	return (this->_privateValue);
}

int	Sample::compare(Sample *other) const
{
	if (this->_privateValue < other->getValue())
		return (-1);
	else if (this->_privateValue > other->getValue())
		return (1);
	
	return (0);
}
