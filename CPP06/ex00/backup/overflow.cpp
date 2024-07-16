/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overflow.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 19:42:50 by cdumais           #+#    #+#             */
/*   Updated: 2024/07/14 23:05:09 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <cstdlib>
#include <cstring>
#include <exception>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

// bool	detectFloatOverflow(const std::string &floatLiteral) //maybe not optimal
// {
// 	// convert string literal to float
// 	float	originalFloat = strtof(floatLiteral.c_str(), NULL);

// 	// convert resulting float back to a string
// 	std::ostringstream	oss;
// 	oss.precision(8); // test with precision..
// 	oss << originalFloat;
// 	std::string	convertedString = oss.str();

// 	// compare the original string with the reconverted string
// 	return (floatLiteral != convertedString);
// }

// bool	isFloatConversionAccurate(const std::string &original, float converted)
// {
// 	std::ostringstream	oss;
// 	oss << std::setprecision(8) << std::fixed << converted;
// 	return (original == oss.str());
// }

void	convert(const std::string &literal)
{
	float	f;
	char	*end;

	errno = 0;
	f = strtof(literal.c_str(), &end);

	if (errno == ERANGE)
	{
		std::cout << "float: impossible" << std::endl;
		return ;
	}

	// convert float back to string
	std::string	convertedString = std::to_string(f);

	// remove any trailing zeros in the decimal part
	size_t	dotPos = convertedString.find('.');
	if (dotPos != std::string::npos)
	{
		convertedString.erase(convertedString.find_last_not_of('0') + 1, std::string::npos);
	}

	// compare original input with converted string
	if (literal == convertedString)
	{
		std::cout << "float: " << f << std::endl;
	}
	else
	{
		std::cout << "float: impossible" << std::endl;
	}
}

