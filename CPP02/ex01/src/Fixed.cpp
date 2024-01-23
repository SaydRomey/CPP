/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:58:04 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/22 17:34:32 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

/* ************************************************************* Constructors */

// Default constructor
Fixed::Fixed(void) : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

/*
Left-shifting by _fractionalBits is like multiplying the i by 2^_fractionalBits.
If _fractionalBits is 8, for example,
shifting left by 8 bits is the same as multiplying by 256.
This converts the integer into a fixed-point format
where the fractional part is initially zero.
*/
// Int constructor
Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called" << std::endl;

	this->_fixedPointValue = i * (1 << _fractionalBits);
	return;
}

/*
f is multiplied by 2^_fractionalBits to shift its decimal point to the right,
effectively converting it to a fixed-point format.
roundf() is used to round the result to the nearest integer,
ensuring precision is maintained in the conversion process.
*/
// Float constructor
Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;

	this->_fixedPointValue = roundf(f * (1 << _fractionalBits));
	return;
}

// Copy constructor
Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

// Default destructor
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

/* ********************************************************* Member functions */

// Returns raw value of the fixed point value
int		Fixed::getRawBits(void) const
{
	return (this->_fixedPointValue);
}

// Sets the raw value of the fixed point number
void	Fixed::setRawBits(const int raw)
{
	this->_fixedPointValue = raw;
}

/*
return ((float)this->fixedPointValue / (1 << this->_fractionalBits));
*/
// Converts fixed-point value to floating-point value
float	Fixed::toFloat(void) const
{
	// Convert fixed-point value to a floating-point number
	float	floatValue = (float)this->_fixedPointValue;

	// Calculate scaling factor (2 raised to the power of _fractionalBits)
	float	scalingFactor = (float)(1 << this->_fractionalBits);

	// Divide fixed-point value by scaling factor to get float representation
	float	result = floatValue / scalingFactor;

	return (result);
}

/*
return (this->_fixedPointValue >> this->_fractionalBits);
*/
// Converts fixed-point value to an integer value
int		Fixed::toInt(void) const
{
	// Right-shift the fixed point value by the number of fractional bits.
	// This removes the fractional part, leaving only the integer part.
	int	intValue = this->_fixedPointValue >> this->_fractionalBits;

	return (intValue);
}

/* **************************************************************** Operators */

// Copy assignment operator overload
Fixed&	Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fixedPointValue = rhs.getRawBits();
	return (*this);
}

// Insertion operator overload
std::ostream&	operator<<(std::ostream &out, const Fixed &rhs)
{
	out << rhs.toFloat();
	return (out);
}

/* ************************************************************************** */

// // Int constructor (using member initializer list)
// Fixed::Fixed(const int i) : _fixedPointValue(i << _fractionalBits)
// {
// 	std::cout << "Int constructor called" << std::endl;
// }

// // Int constructor (using member function)
// Fixed::Fixed(const int i)
// {
// 	std::cout << "Int constructor called" << std::endl;
// 	this->setRawBits(i << this->_fractionalBits);
// }

// // Int constructor (direct assignment in constructor body)
// Fixed::Fixed(const int i)
// {
// 	std::cout << "Int constructor called" << std::endl;
// 	this->_fixedPointValue = i * (1 << _fractionalBits);
// }
