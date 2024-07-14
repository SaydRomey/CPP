/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 22:16:25 by cdumais           #+#    #+#             */
/*   Updated: 2024/07/13 23:08:19 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Conversion of scalar types

Turn-in directory : ex00/
Files to turn in : Makefile, *.cpp, *.{h, hpp}

Allowed functions : Any function to convert from a string to an int, a float or a double.
This will help, but won’t do the whole job.
Write a program that takes as parameter a string representation of a C++ literal in its most common form.
This literal must belong to one of the following a scalar types:
char, int, float or double.
Except for char parameters, only the decimal notation will be used.
Examples of char literals: ’c’, ’a’, ...
To make things simple, please note that non displayable characters shouldn’t be used as inputs.
If a conversion to char is not displayable, prints an informative message.
Examples of int literals: 0, -42, 42...
Examples of float literals: 0.0f, -4.2f, 4.2f...
You have to handle these pseudo literals as well (you know, for science): -inff, +inff and nanf.
Examples of double literals: 0.0, -4.2, 4.2...
You have to handle these pseudo literals as well (you know, for fun): -inf, +inf and nan.

You have to first detect the type of the literal passed as parameter,
convert it from string to its actual type,
then convert it explicitly to the three other data types.
Lastly, display the results as shown below.

If a conversion does not make any sense or overflows,
display a message to inform the user that the type conversion is impossible.
Include any header you need in order to handle numeric limits and special values.

./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0

./convert nan
char: impossible
int: impossible
float: nanf
double: nan

./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0
*/


/*
Identify the Type:

Use functions to detect whether the string represents a char, int, float, or double.
Convert to the Identified Type:

Use appropriate C++ casting for the conversions.
Print the Converted Values:

Handle special cases where conversion is not possible or not displayable.
*/


/*
special floating-point values like: -inff, +inff, nanf, -inf, +inf, nan
IEEE 754 standard for floating-point arithmetic

Infinities: -inf, +inf, -inff, +inff
typically represented using constants INFINITY and -INFINITY from <cmath>

Not-a-Number: nan, nanf
typically represented using constant NAN from <cmath>

*/

bool	isNanOrInf(const std::string &str)
{
	return (str == "nan" || str == "nanf" || 
			str == "-inf" || str == "-inff" || 
			str == "+inf" || str == "+inff");
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <limits>
#include <cmath>
#include <iomanip>

class Converter
{
public:
	Converter(const std::string &input);
	void convert();

private:
	std::string input;

	void detectTypeAndConvert();
	bool isChar() const;
	bool isInt() const;
	bool isFloat() const;
	bool isDouble() const;

	void convertFromChar(char c);
	void convertFromInt(int i);
	void convertFromFloat(float f);
	void convertFromDouble(double d);

	void printChar(char c) const;
	void printInt(int i) const;
	void printFloat(float f) const;
	void printDouble(double d) const;

	// Helper function for string to double conversion
	double strtod(const std::string &str);
};

#endif // CONVERTER_HPP

/////

/*
String to Numeric Conversion:

Instead of std::stoi, std::stof, and std::stod, you should use atoi for converting to int, atof for converting to float, and strtod for converting to double. These functions are part of the C standard library and have been available in C++.
Character Checking:

Replace std::isprint with a custom function or check manually if a character is printable.
Special Values:

Handle special values (nan, inf) manually or using macros if your compiler supports them.
*/

#include "Converter.hpp"
#include <cstdlib>
#include <cstring>

Converter::Converter(const std::string &input) : input(input) {}

void Converter::convert()
{
	detectTypeAndConvert();
}

void Converter::detectTypeAndConvert()
{
	if (isChar())
	{
		char c = input[1];
		convertFromChar(c);
	}
	else if (isInt())
	{
		int i = atoi(input.c_str());
		convertFromInt(i);
	}
	else if (isFloat())
	{
		float f = atof(input.c_str());
		convertFromFloat(f);
	}
	else if (isDouble())
	{
		double d = strtod(input);
		convertFromDouble(d);
	}
	else
	{
		std::cerr << "Error: Invalid input" << std::endl;
	}
}

bool Converter::isChar() const
{
	return input.length() == 3 && input[0] == '\'' && input[2] == '\'';
}

bool Converter::isInt() const
{
	std::istringstream iss(input);
	int i;
	iss >> i;
	return iss.eof() && !iss.fail();
}

bool Converter::isFloat() const
{
	if (input == "-inff" || input == "+inff" || input == "nanf")
		return true;

	std::istringstream iss(input);
	float f;
	iss >> f;
	return iss.eof() && !iss.fail() && input.find('f') == input.size() - 1;
}

bool Converter::isDouble() const
{
	if (input == "-inf" || input == "+inf" || input == "nan")
		return true;

	std::istringstream iss(input);
	double d;
	iss >> d;
	return iss.eof() && !iss.fail();
}

void Converter::convertFromChar(char c)
{
	printChar(c);
	printInt(static_cast<int>(c));
	printFloat(static_cast<float>(c));
	printDouble(static_cast<double>(c));
}

void Converter::convertFromInt(int i)
{
	printChar(static_cast<char>(i));
	printInt(i);
	printFloat(static_cast<float>(i));
	printDouble(static_cast<double>(i));
}

void Converter::convertFromFloat(float f)
{
	printChar(static_cast<char>(f));
	printInt(static_cast<int>(f));
	printFloat(f);
	printDouble(static_cast<double>(f));
}

void Converter::convertFromDouble(double d)
{
	printChar(static_cast<char>(d));
	printInt(static_cast<int>(d));
	printFloat(static_cast<float>(d));
	printDouble(d);
}

void Converter::printChar(char c) const
{
	if (isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

void Converter::printInt(int i) const
{
	std::cout << "int: " << i << std::endl;
}

void Converter::printFloat(float f) const
{
	if (isnan(f) || isinf(f))
		std::cout << "float: " << f << "f" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void Converter::printDouble(double d) const
{
	if (isnan(d) || isinf(d))
		std::cout << "double: " << d << std::endl;
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

// Helper function to convert string to double
double Converter::strtod(const std::string &str)
{
	char *endptr;
	const char *cstr = str.c_str();
	double result = std::strtod(cstr, &endptr);
	if (endptr == cstr || *endptr != '\0')
	{
		throw std::invalid_argument("Invalid double conversion");
	}
	return result;
}

#include "Converter.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
		return 1;
	}

	Converter converter(argv[1]);
	converter.convert();

	return 0;
}
