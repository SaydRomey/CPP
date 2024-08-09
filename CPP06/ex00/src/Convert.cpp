/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 22:36:12 by cdumais           #+#    #+#             */
/*   Updated: 2024/08/09 15:05:56 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

bool	isNanOrInf(const std::string &literal)
{
	return (literal == "nan" || literal == "nanf" || 
			literal == "-inf" || literal == "-inff" || 
			literal == "+inf" || literal == "+inff" || 
			literal == "inf" || literal == "inff");
}

bool	isValidScalarType(const std::string &literal)
{
	char	*endptr;

	if (literal.empty())
		return (false);

	if (literal.length() == 1 && std::isprint(literal[0]))
		return (true); // valid char

	strtol(literal.c_str(), &endptr, 10);
	if (*endptr == '\0')
		return (true); // valid int

	if (isNanOrInf(literal))
		return (true); // pseudo-literals

	if (literal.length() > 1 && literal[literal.length() - 1] == 'f')
	{
		strtof(literal.c_str(), &endptr);
		if (*endptr == 'f' && *(endptr + 1) == '\0')
			return (true); // float with 'f' suffix
	}

	strtod(literal.c_str(), &endptr);
	if (*endptr == '\0')
		return (true); // valid double
	
	return (false);	// invalid input
}

void	handlePseudoLiteral(const std::string &literal)
{
	float	f = 0.0f;
	double	d = 0.0;

	if (literal == "nan" || literal == "nanf")
	{
		f = std::numeric_limits<float>::quiet_NaN();
		d = std::numeric_limits<double>::quiet_NaN();
	}
	else if (literal == "inf" || literal == "inff" || literal == "+inf" || literal == "+inff")
	{
		f = std::numeric_limits<float>::infinity();
		d = std::numeric_limits<double>::infinity();
	}
	else if (literal == "-inf" || literal == "-inff")
	{
		f = -std::numeric_limits<float>::infinity();
		d = -std::numeric_limits<double>::infinity();
	}
	std::cout << "char:   impossible" << std::endl;
	std::cout << "int:    impossible" << std::endl;
	std::cout << "float:  " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void	handleCharLiteral(const std::string &literal)
{
	char	c = literal[0];
	int		i = static_cast<int>(c);
	float	f = static_cast<float>(c);
	double	d = static_cast<double>(c);

	std::cout << "char:  '" << c << "'" << std::endl;
	std::cout << "int:    " << i << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float:  " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void	displayCharConversion(int i)
{
	char	c;

	if (i >= std::numeric_limits<char>::min() && i <= std::numeric_limits<char>::max())
	{
		c = static_cast<char>(i);
		if (std::isprint(c))
			std::cout << "char:  '" << c << "'" << std::endl;
		else
			std::cout << "char:   Non displayable" << std::endl;
	}
	else
	{
		std::cout << "char:   impossible" << std::endl;
	}
}

void	displayFloatingPointConversions(float f, bool floatOverflow, double d, bool doubleOverflow)
{
	std::cout << std::fixed << std::setprecision(1);

	if (floatOverflow)
		std::cout << "float:  impossible" << std::endl;
	else
		std::cout << "float:  " << f << "f" << std::endl;
	
	if (doubleOverflow)
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}

double	parseDouble(const std::string &literal, bool &overflow)
{
	double	d;
	char	*endptr;

	errno = 0;
	d = strtod(literal.c_str(), &endptr);
	overflow = errno == ERANGE || !std::isfinite(d);
	return (d);
}

float	parseFloat(double d, bool &overflow)
{
	float	f;

	errno = 0;
	f = static_cast<float>(d);
	overflow = errno == ERANGE || !std::isfinite(f);
	return (f);
}

bool	parseInt(double d, int &i)
{
	if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
	{
		i = static_cast<int>(d);
		return (false);
	}
	return (true);
}

void	handleNumericLiteral(const std::string &literal)
{
	bool	doubleOverflow;
	double	d = parseDouble(literal, doubleOverflow);

	bool	floatOverflow;
	float	f = parseFloat(d, floatOverflow);

	int		i;
	bool	intOverflow = parseInt(d, i);

	if (intOverflow)
	{
		std::cout << "char:   impossible" << std::endl;
		std::cout << "int:    impossible" << std::endl;
	}
	else
	{
		displayCharConversion(i);
		std::cout << "int:    " << i << std::endl;
	}
	displayFloatingPointConversions(f, floatOverflow, d, doubleOverflow);
}

void	convert(const std::string &literal)
{
	if (isNanOrInf(literal))
	{
		handlePseudoLiteral(literal);
	}
	else if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
	{
		handleCharLiteral(literal);
	}
	else
		handleNumericLiteral(literal);
}
