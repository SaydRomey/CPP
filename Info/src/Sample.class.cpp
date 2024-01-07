/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:24:32 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/07 17:05:55 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"

Sample::Sample(void) : value(0)
{
	std::cout << "Constructor called" << std::endl;

	return;
}

Sample::~Sample(void)
{
	std::cout << "Destructor called" << std::endl;

	return;
}

void	Sample::func(void) const
{
	std::cout << "Member function 'func' called" << std::endl;
	return;
}
