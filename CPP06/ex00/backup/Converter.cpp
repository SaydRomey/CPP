/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:12:00 by cdumais           #+#    #+#             */
/*   Updated: 2024/07/15 22:10:49 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"
#include <cstdlib>
#include <cstring>

/* ************************************************************************** */ // Constructors / Destructors

Converter::Converter(void)
{
	// std::cout << GRAYTALIC << "Converter [default constructor]" << RESET << std::endl;
}

Converter::Converter(const std::string &input) : _input(input)
{
	// std::cout << GRAYTALIC << "Converter [parametrized constructor]" << RESET << std::endl;
}

Converter::Converter(const Converter &other)
{
	*this = other;
	// std::cout << GRAYTALIC << "Converter [copy constructor]" << RESET << std::endl;
}

Converter::~Converter(void)
{
	// std::cout << GRAYTALIC << "Converter [default destructor]" << RESET << std::endl;
}

/* ************************************************************************** */ // Functions / Methods

void	Converter::convert(void)
{
	_detectTypeAndConvert();
}

void Converter::_detectTypeAndConvert(void)
{
	if (_isChar())
	{
		char	c = _input[1];
		_convertFromChar(c);
	}
	else if (_isInt())
	{
		int		i = atoi(_input.c_str());
		_convertFromInt(i); 
	}
	else if (_isFloat())
	{
		float	f = atof(_input.c_str());
		_convertFromFloat(f);
	}
	else if (_isDouble())
	{
		double	d = _strtod(_input);
		_convertFromDouble(d);
	}
	else
	{
		throw (InvalidInputException());
	}
}

bool	Converter::_isChar(void) const
{
	return (_input.length() == 3 && _input[0] == '\'' && _input[2] == '\'');
}

bool	Converter::_isInt(void) const
{
	std::istringstream	iss(_input);
	int	i;
	iss >> i;
	return (iss.eof() && !iss.fail());
}

bool	Converter::_isFloat(void) const
{
	if (_input == "-inff" || _input == "+inff" || _input == "nanf")
		return (true);
	
	std::istringstream	iss(_input);
	float	f;
	iss >> f;
	return (iss.eof() && !iss.fail() && _input.find('f') == _input.size() - 1);
}

bool	Converter::_isDouble(void) const
{
	if (_input == "-inf" || _input == "+inf" || _input == "nan")
		return (true);

	std::istringstream	iss(_input);
	double	d;
	iss >> d;
	return (iss.eof() && !iss.fail());
}

void	Converter::_convertFromChar(char c)
{
	_printChar(c);
	_printInt(static_cast<int>(c));
	_printFloat(static_cast<float>(c));
	_printDouble(static_cast<double>(c));
}

void	Converter::_convertFromInt(int i)
{
	_printChar(static_cast<char>(i));
	_printInt(i);
	_printFloat(static_cast<float>(i));
	_printDouble(static_cast<double>(i));
}

void	Converter::_convertFromFloat(float f)
{
	_printChar(static_cast<char>(f));
	_printInt(static_cast<int>(f));
	_printFloat(f);
	_printDouble(static_cast<double>(f));
}

void	Converter::_convertFromDouble(double d)
{
	_printChar(static_cast<char>(d));
	_printInt(static_cast<int>(d));
	_printFloat(static_cast<float>(d));
	_printDouble(d);
}

void	Converter::_printChar(char c) const
{
	std::cout << "char: ";
	if (c < CHAR_MIN || c > CHAR_MAX)
		std::cout << "impossible" << std::endl;
	else
	{
		if (!isprint(c))
			std::cout << "Non displayable";
		else
			std::cout << "'" << c << "'";
	}
	std::cout << std::endl;
}

void	Converter::_printInt(int i) const
{
	std::cout << "int: ";
	// 
	std::cout << i << std::endl;
}

void	Converter::_printFloat(float f) const
{
	if (isnan(f) || isinf(f))
		std::cout << "float: " << f << "f" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void	Converter::_printDouble(double d) const
{
	if (isnan(d) || isinf(d))
		std::cout << "double: " << d << "d" << std::endl;
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

double	Converter::_strtod(const std::string &str)
{
	char		*endptr;
	const char	*cstr = str.c_str();
	double		result = std::strtod(cstr, &endptr);
	
	if (endptr == cstr || *endptr != '\0')
	{
		throw (std::invalid_argument("Invalid double conversion"));
	}
	return (result);
}

/* ************************************************************************** */ // Operators

Converter&	Converter::operator=(const Converter &other)
{
	(void)other;
	return (*this);
}

// std::ostream&	operator<<(std::ostream &out, const Converter &param)

/* ************************************************************************** */ // Exceptions

const char* Converter::InvalidInputException::what() const throw()
{
	return ("Error: Invalid input");
}
