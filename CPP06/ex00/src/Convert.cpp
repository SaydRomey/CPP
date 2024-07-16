/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 22:36:12 by cdumais           #+#    #+#             */
/*   Updated: 2024/07/15 22:55:49 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

bool	isNanOrInf(const std::string &literal)
{
	return (literal == "-inff" || literal == "+inff" || literal == "nanf" || 
			literal == "-inf" || literal == "+inf" || literal == "nan");
}

bool	isScientificNotation(const std::string &literal)
{
	size_t	e_pos = literal.find('e');
	if (e_pos == std::string::npos)
	{
		e_pos = literal.find('E');
	}
	return (e_pos != std::string::npos);
}

double	scientificToFixed(const std::string &literal)
{
	char	*endptr;
	errno = 0;
	double	result = strtod(literal.c_str(), &endptr);
	if (errno == ERANGE)
	{
		throw std::overflow_error("Overflow during scientific to fixed conversion");
	}
	return (result);
}

/*
maybe add check for input format:
	check how we can handle numbers passed as chars : '1' is the char '1', not the int 1 ...
*/
bool	isValidScalarType(const std::string &literal)
{
	char	*endptr;
	
	// valid char
	if (literal.length() == 1 && std::isprint(literal[0]))
		return (true);

	// valid int
	strtol(literal.c_str(), &endptr, 10);
	if (*endptr == '\0')
		return (true);

	// pseudo-literals
	if (isNanOrInf(literal))
		return (true);
	
	// float with 'f' suffix
	if (literal.length() > 1 && literal[literal.length() - 1] == 'f')
	{
		strtof(literal.c_str(), &endptr);
		if (*endptr == 'f' && *(endptr + 1) == '\0')
			return (true);
	}

	// double
	strtod(literal.c_str(), &endptr);
	if (*endptr == '\0')
		return (true);
	
	std::cout << INVALID_TYPE << std::endl;
	return (false);	
}

void	handlePseudoLiteral(const std::string &literal)
{
	float	f;
	double	d;

	if (literal == "nan" || literal == "nanf")
	{
		f = std::numeric_limits<float>::quiet_NaN();
		d = std::numeric_limits<double>::quiet_NaN();
	}
	else if (literal == "+inf" || literal == "+inff")
	{
		f = std::numeric_limits<float>::infinity();
		d = std::numeric_limits<double>::infinity();
	}
	else if (literal == "-inf" || literal == "-inff")
	{
		f = -std::numeric_limits<float>::infinity();
		d = -std::numeric_limits<double>::infinity();
	}
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void	handleCharLiteral(const std::string &literal)
{
	char	c = literal[0];
	int		i = static_cast<int>(c);
	float	f = static_cast<float>(c);
	double	d = static_cast<double>(c);

	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

/* ************************************************************************** */


void	handleNumericLiteral(const std::string &literal)
{
	char	*endptr;

	double d = 0;
	if (isScientificNotation(literal))
	{
		d = scientificToFixed(literal);
	}
	else
	{
		errno = 0;
		d = strtod(literal.c_str(), &endptr);
		if (*endptr != '\0' && *endptr != 'f')
		{
			std::cout << "Invalid input" << std::endl;
			return ;
		}
	}
	bool	doubleOverflow = errno == ERANGE || !std::isfinite(d);

	// errno = 0;
	// double	d = strtod(literal.c_str(), &endptr);
	// bool	doubleOverflow = errno == ERANGE || !std::isfinite(d);

	errno = 0;
	float	f = strtof(literal.c_str(), &endptr);
	bool	floatOverflow = errno == ERANGE || !std::isfinite(f);

	// // check if double value can be represented as an integer
	bool	isIntegerRepresentable = !doubleOverflow && d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max();
	int		i = static_cast<int>(d);
	bool	intOverflow = !isIntegerRepresentable;
	
	// errno = 0;
	// long	l = strtol(literal.c_str(), &endptr, 10);
	// bool	intOverflow = errno == ERANGE || l < std::numeric_limits<int>::min() || l > std::numeric_limits<int>::max();

	// display conversion results with overflow checks
	if (intOverflow)
	{		
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		// int	i = static_cast<int>(l);
		if (i >= std::numeric_limits<char>::min() && i <= std::numeric_limits<char>::max())
		{
			char	c = static_cast<char>(i);
			if (std::isprint(c))
				std::cout << "char: '" << c << "'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
		}
		else
		{
			std::cout << "char: impossible" << std::endl;
		}
		std::cout << "int: " << i << std::endl;
	}
	
	std::cout << std::fixed << std::setprecision(1);
	if (floatOverflow)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;

	if (doubleOverflow)
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
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

/* ************************************************************************** */


// ////

// void	convert(const std::string &literal)
// {
// 	char	c;
// 	int		i;
// 	float	f;
// 	double	d;

// 	// check if pseudo litteral special case
// 	if (isNanOrInf(literal))
// 	{
// 		if (literal == "nan" || literal == "nanf")
// 		{
// 			f = std::numeric_limits<float>::quiet_NaN();
// 			d = std::numeric_limits<double>::quiet_NaN();
// 		}
// 		else if (literal == "+inf" || literal == "+inff")
// 		{
// 			f = std::numeric_limits<float>::infinity();
// 			d = std::numeric_limits<double>::infinity();
// 		}
// 		else if (literal == "-inf" || literal == "-inff")
// 		{
// 			f = -std::numeric_limits<float>::infinity();
// 			d = -std::numeric_limits<double>::infinity();
// 		}
// 		// display results
// 		std::cout << "char: impossible" << std::endl;
// 		std::cout << "int: impossible" << std::endl;
// 		std::cout << "float: " << f << "f" << std::endl;
// 		std::cout << "double: " << d << std::endl;
// 		return ;
// 	}

// 	// check if input is a single character [enclosed in single quotes]
// 	if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
// 	{
// 		c = literal[0];
// 		i = static_cast<int>(c);
// 		f = static_cast<float>(c);
// 		d = static_cast<double>(c);

// 		std::cout << "char: '" << c << "'" << std::endl;
// 		std::cout << "int: " << i << std::endl;
// 		std::cout << std::fixed << std::setprecision(1);
// 		std::cout << "float: " << f << "f" << std::endl;
// 		std::cout << "double: " << d << std::endl;
// 		return ;
// 	}

// 	//attempt to convert to each type (checking overflows)
// 	char		*endptr;
	
// 	errno = 0;
// 	long long	ll = strtoll(literal.c_str(), &endptr, 10);
// 	bool	intOverflow = errno == ERANGE || *endptr != '\0' || ll < std::numeric_limits<int>::min() || ll > std::numeric_limits<int>::max();
	
// 	errno = 0;
// 	f = strtof(literal.c_str(), &endptr);
// 	// bool	floatOverflow = errno == ERANGE || f == HUGE_VALF || f == -HUGE_VALF;
// 	bool	floatOverflow = errno == ERANGE || !std::isfinite(f);

// 	errno = 0;
// 	d = strtod(literal.c_str(), &endptr);
// 	// bool	doubleOverflow = errno == ERANGE || d == HUGE_VAL || d == -HUGE_VAL;
// 	bool	doubleOverflow = errno == ERANGE || !std::isfinite(d);

// 	// display conversion results with overflow checks
// 	if (intOverflow)
// 	{
// 		std::cout << "char: impossible" << std::endl;
// 		std::cout << "int: impossible" << std::endl;
// 	}
// 	else
// 	{
// 		i = static_cast<int>(ll);
// 		if (i >= std::numeric_limits<char>::min() && i <= std::numeric_limits<char>::max())
// 		{
// 			c = static_cast<char>(i);
// 			if (std::isprint(c))
// 				std::cout << "char: '" << c << "'" << std::endl;
// 			else
// 				std::cout << "char: Non displayable" << std::endl;
// 		}
// 		else
// 		{
// 			std::cout << "char: impossible" << std::endl;
// 		}
// 		std::cout << "int: " << i << std::endl;
// 	}

// 	if (floatOverflow)
// 	{
// 		std::cout << "float: impossible" << std::endl;
// 	}
// 	else
// 	{
// 		std::cout << std::fixed << std::setprecision(1);
// 		std::cout << "float: " << f << "f" << std::endl;
// 	}

// 	if (doubleOverflow)
// 	{
// 		std::cout << "double: impossible" << std::endl;
// 	}
// 	else
// 	{
// 		std::cout << "double: " << d << std::endl;
// 	}
// }

/*
c++ -Wall -Werror -Wextra -std=c++98 src/convert.cpp

*/
int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Usage: " << argv[0] << " <literal>" << std::endl;
		return (1);
	}
	if (!isValidScalarType(argv[1]))
	{
		return (1);
	}
	convert(argv[1]);
	
	return (0);
}

/*
Edge Cases and Invalid Inputs


3.4e+38f - Float close to overflow
3.5e+38f - Float overflow

1.7e+308 - Double close to overflow
1.8e+308 - Double overflow

./a.out abc - Invalid scalar type
./a.out 4.2.0 - Invalid scalar type
./a.out --42 - Invalid scalar type
*/