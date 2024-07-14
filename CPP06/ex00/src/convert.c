/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 22:36:12 by cdumais           #+#    #+#             */
/*   Updated: 2024/07/14 02:05:41 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <cstdlib>
#include <exception>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

bool	isNanOrInf(const std::string &str)
{
	return (str == "nan" || str == "nanf" || 
			str == "-inf" || str == "-inff" || 
			str == "+inf" || str == "+inff");
}

bool	isValidScalarType(const std::string &literal)
{
	// valid char
	if (literal.length() == 1 && std::isprint(literal[0]))
		return (true);
	
	// pseudo-literals
	if (isNanOrInf(literal))
		return (true);

	// float with 'f' suffix
	if (literal.length() > 1 && literal[literal.length() - 1] == 'f')
	{
		std::string	floatPart = literal.substr(0, literal.length() - 1);
		char	*end;
		strtof(floatPart.c_str(), &end);
		if (*end == '\0')
			return (true);
	}

	// 
	char	*end;
	strtod(literal.c_str(), &end);
	if (*end == '\0')
		return (true);
	
	std::cout << "Invalid scalar type. Accepted values are:" << std::endl;
	std::cout << "char: single printable character (e.g., 'a')" << std::endl;
	std::cout << "int: integer values (e.g., 42)" << std::endl;
	std::cout << "float: floating-point values with 'f' suffix (e.g., 42.0f)" << std::endl;
	std::cout << "double: floating-point values (e.g., 42.0)" << std::endl;
	return (false);	
}

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

void	convert(const std::string &literal)
{
	char	c;
	int		i;
	float	f;
	double	d;

	// check if pseudo litteral special case
	if (isNanOrInf(literal))
	{
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
		// display results
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
		return ;
	}

	// check if input is a single character [enclosed in single quotes]
	if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
	{
		c = literal[0];
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);

		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
		return ;
	}

	//attempt to convert to each type (checking overflows)
	char		*end;
	errno = 0;
	long long	ll = strtoll(literal.c_str(), &end, 10);
	bool	intOverflow = errno == ERANGE || 
			ll < std::numeric_limits<int>::min() || ll > std::numeric_limits<int>::max();
	
	errno = 0;
	f = strtof(literal.c_str(), &end);
	bool	floatOverflow = errno == ERANGE || (std::isfinite(f) && (f > std::numeric_limits<float>::max() || f < -std::numeric_limits<float>::max()));

	errno = 0;
	d = strtod(literal.c_str(), &end);
	bool	doubleOverflow = errno == ERANGE || (std::isfinite(d) && (d > std::numeric_limits<double>::max() || d < -std::numeric_limits<double>::max()));

	// display conversion results with overflow checks
	if (intOverflow)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		i = static_cast<int>(ll);
		if (i >= std::numeric_limits<char>::min() && i <= std::numeric_limits<char>::max())
		{
			c = static_cast<char>(i);
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

	if (floatOverflow)
	{
		std::cout << "float: impossible" << std::endl;
	}
	else
	{
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << f << "f" << std::endl;
	}

	if (doubleOverflow)
	{
		std::cout << "double: impossible" << std::endl;
	}
	else
	{
		std::cout << "double: " << d << std::endl;
	}
}

/*
c++ -Wall -Werror -Wextra -std=c++98 src/convert.c

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

	// attempt to convert to each type
	// try
	// {
	// 	i = atoi(literal.c_str());
	// 	f = atof(literal.c_str());
	// 	d = strtod(literal.c_str(), NULL);

	// 	// check if int is displayable as a char
	// 	if (i >= std::numeric_limits<char>::min() && i <= std::numeric_limits<char>::max())
	// 	{
	// 		c = static_cast<char>(i);
	// 		if (std::isprint(c))
	// 			std::cout << "char: '" << c << "'" << std::endl;
	// 		else
	// 			std::cout << "char: Non displayable" << std::endl;
	// 	}
	// 	else
	// 	{
	// 		std::cout << "char: impossible" << std::endl;
	// 	}
		
	// 	std::cout << "int: " << i << std::endl;
	// 	std::cout << std::fixed << std::setprecision(1);
	// 	std::cout << "float: " << f << "f" << std::endl;
	// 	std::cout << "double: " << d << std::endl;
	// }
	// catch (std::exception &e)
	// {
	// 	std::cout << "Error: " << e.what() << std::endl;
	// }

// int	main(void)
// {
// 	std::string literals[] = {"0", "nan", "42.0f", "-inf"};
	
// 	for (int i = 0; i < 4; ++i)
// 	{
// 		std::cout << "Input: \"" << literals[i] << "\"" << std::endl;
// 		convert(literals[i]);
// 		std::cout << std::endl;
// 	}
	
// 	return 0;
// }

/*
Valid Character Literals
./a.out 'a' - Treat as character 'a' (ASCII 97)
./a.out '1' - Treat as character '1' (ASCII 49)
./a.out '\n' - Treat as non-printable character (ASCII 10)

Valid Numeric Literals
./a.out 42 - Treat as integer 42
./a.out -42 - Treat as integer -42
./a.out 42.0 - Treat as double 42.0
./a.out 42.0f - Treat as float 42.0f
./a.out -42.0 - Treat as double -42.0
./a.out -42.0f - Treat as float -42.0f

Pseudo-literals
./a.out nan - Treat as NaN (double)
./a.out nanf - Treat as NaN (float)
./a.out +inf - Treat as positive infinity (double)
./a.out +inff - Treat as positive infinity (float)
./a.out -inf - Treat as negative infinity (double)
./a.out -inff - Treat as negative infinity (float)

Edge Cases and Invalid Inputs
./a.out 2147483648 - Integer overflow (greater than INT_MAX)
./a.out -2147483649 - Integer overflow (less than INT_MIN)
./a.out 340282346638528859811704183484516925440.0f - Float overflow
./a.out 1.7e+308 - Double close to overflow
./a.out 1.8e+308 - Double overflow
./a.out abc - Invalid scalar type
./a.out 4.2.0 - Invalid scalar type
./a.out --42 - Invalid scalar type
./a.out '*' - Treat as character '*' (ASCII 42)

Additional Tests for Characters
./a.out '\t' - Treat as non-printable character (ASCII 9)
./a.out '\b' - Treat as non-printable character (ASCII 8)
./a.out '\\' - Treat as character '\' (ASCII 92)
*/