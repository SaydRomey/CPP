/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:06:29 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/18 13:42:17 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int	main(void)
{
	Fixed		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	// 
	// std::cout << "additionnal tests" << std::endl;
	
	// Fixed		c;
	// Fixed const	d( Fixed(10.05f) * Fixed(2));

	// std::cout << "c = " << c << std::endl;
	// std::cout << "d = " << d << std::endl;

	// std::cout << Fixed::max( c, d ) << " is bigger" << std::endl;
	// std::cout << Fixed::min( c, d ) << " is smaller" << std::endl;

	// std::cout << "Half of " << d << " is " << (d / 2) << std::endl;

	return (0);
}

/* (expected result)

0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016
*/
