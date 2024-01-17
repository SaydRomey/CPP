/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:05:26 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/17 17:06:31 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

/* *********************************************** Constructors / Destructors */

Fixed::Fixed(void) : _fixedPointValue(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const i)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = i * (1 << _fractionalBits);
}

Fixed::Fixed(float const f)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(f * (1 << _fractionalBits));
}

Fixed::Fixed(Fixed const &src)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" << std::endl;
}

/* ********************************************************* Member functions */

int		Fixed::getRawBits(void) const
{
	return (this->_fixedPointValue);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

float	Fixed::toFloat(void) const
{
	float	floatValue = (float)this->_fixedPointValue;
	float	scalingFactor = (float)(1 << this->_fractionalBits);
	return (floatValue / scalingFactor);
}

int		Fixed::toInt(void) const
{
	int	intValue = this->_fixedPointValue >> this->_fractionalBits;
	return (intValue);
}

Fixed&	Fixed::min(Fixed &lhs, Fixed &rhs)
{
	if (lhs._fixedPointValue < rhs._fixedPointValue)
		return (lhs);
	else
		return (rhs);
}

const Fixed&	Fixed::min(const Fixed &lhs, const Fixed &rhs)
{
	if (lhs._fixedPointValue < rhs._fixedPointValue)
		return (lhs);
	else
		return (rhs);
}

Fixed&	Fixed::max(Fixed &lhs, Fixed &rhs)
{
	if (lhs._fixedPointValue > rhs._fixedPointValue)
		return (lhs);
	else
		return (rhs);
}

const Fixed&	Fixed::max(const Fixed &lhs, const Fixed &rhs)
{
	if (lhs._fixedPointValue > rhs._fixedPointValue)
		return (lhs);
	else
		return (rhs);
}

/* **************************************************************** Operators */

// Copy assignment operator overload
Fixed&	Fixed::operator=(Fixed const &rhs)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fixedPointValue = rhs.getRawBits();
	return (*this);
}

// Insertion operator overload
std::ostream & operator<<(std::ostream &out, Fixed const &rhs)
{
	out << rhs.toFloat();
	return (out);
}
/* comparison */

bool	Fixed::operator>(const Fixed &rhs) const
{
	if (this->_fixedPointValue > rhs._fixedPointValue)
		return (true);
	else
		return (false);
}

bool	Fixed::operator<(const Fixed &rhs) const
{
	if (this->_fixedPointValue < rhs._fixedPointValue)
		return (true);
	else
		return (false);
}

bool	Fixed::operator>=(const Fixed &rhs) const
{
	if (this->_fixedPointValue >= rhs._fixedPointValue)
		return (true);
	else
		return (false);
}

bool	Fixed::operator<=(const Fixed &rhs) const
{
	if (this->_fixedPointValue <= rhs._fixedPointValue)
		return (true);
	else
		return (false);
}

bool	Fixed::operator==(const Fixed &rhs) const
{
	if (this->_fixedPointValue == rhs._fixedPointValue)
		return (true);
	else
		return (false);
}

bool	Fixed::operator!=(const Fixed &rhs) const
{
	if (this->_fixedPointValue != rhs._fixedPointValue)
		return (true);
	else
		return (false);
}

/* arithmetic */

Fixed	Fixed::operator+(const Fixed &rhs) const
{
	Fixed	result;
	result._fixedPointValue = this->_fixedPointValue + rhs._fixedPointValue;
	return (result);
}

Fixed	Fixed::operator-(const Fixed &rhs) const
{
	Fixed	result;
	result._fixedPointValue = this->_fixedPointValue - rhs._fixedPointValue;
	return (result);
}

Fixed	Fixed::operator*(const Fixed &rhs) const
{
	Fixed	result;
	result._fixedPointValue = \
		(this->_fixedPointValue * rhs._fixedPointValue) >> _fractionalBits;
	return (result);
	// return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &rhs) const
{
	// if (rhs._fixedPointValue == 0)
		// undefined for division by zero...
	Fixed	result;
	result._fixedPointValue = \
		(this->_fixedPointValue << _fractionalBits) / rhs._fixedPointValue;
	return (result);
	// return (Fixed(this->toFloat() / rhs.toFloat()));
}

// pre-increment
Fixed&	Fixed::operator++(void)
{
	this->_fixedPointValue += 1;
	return (*this);
}

// pre-decrement
Fixed&	Fixed::operator--(void)
{
	this->_fixedPointValue -= 1;
	return (*this);
}

// post-increment
Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	this->_fixedPointValue += 1;
	// operator++();
	return (tmp);
}

// post-decrement
Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	this->_fixedPointValue -= 1;
	// operator--();
	return (tmp);
}
