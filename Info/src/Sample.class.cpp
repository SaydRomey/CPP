/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:37:39 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/16 12:45:08 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sample.class.hpp"
#include <iostream>

Sample::Sample(void)
{
	std::cout << "Sample constructor" << std::endl;
	return;
}

Sample::~Sample(void)
{
	std::cout << "Sample destructor" << std::endl;
	return;
}

void	Sample::func(char const c) const
{
	std::cout << "Member function 'func' called with char overload : " << c << std::endl;
	return;
}

void	Sample::func(int const n) const
{
	std::cout << "Member function 'func' called with int overload : " << n << std::endl;
	return;
}

void	Sample::func(float const z) const
{
	std::cout << "Member function 'func' called with float overload : " << z << std::endl;
	return;
}

void	Sample::func(Sample const &i) const
{
	(void) i;
	std::cout << "Member function 'func' called with Sample class overload" << std::endl;
	return;
}
