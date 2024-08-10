/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:37:54 by cdumais           #+#    #+#             */
/*   Updated: 2024/08/09 20:30:10 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Create aprogram which outputs the value of a certain amount of bitcoin on a certain date.

This program must use a database in csv format (comma-separated values)
which will represent bitcoin price over time.
This database is provided with this subject.

The program will take as input a second database,
storing the different prices/dates to evaluate.

Your program must respect these rules:

• The program name is btc.
• Your program must take a file as argument.
• Each line in this file must use the following format: "date | value".
• A valid date will always be in the following format: Year-Month-Day.
• A valid value must be either a float or a positive integer, between 0 and 1000.

You must use at least one container in your code to validate this exercise.
You should handle possible errors with an appropriate error message.

Here is an example of an input.txt file:
 
$> head input.txt
date | value
2011-01-03 | 3
2011-01-03 | 2
2011-01-03 | 1
2011-01-03 | 1.2
2011-01-09 | 1
2012-01-11 | -1
2001-42-42
2012-01-11 | 1
2012-01-11 | 2147483648
$>

Your program will use the value in your input file.

Your program should display on the standard output the result of the value multiplied by the exchange rate according to the date indicated in your database.

If the date used in the input does not exist in your DB
then you must use the closest date contained in your DB.
** Be careful to use the lower date and not the upper one.

The following is an example of the program’s use.

$> ./btc
Error: could not open file.
$> ./btc input.txt
2011-01-03 => 3 = 0.9
2011-01-03 => 2 = 0.6
2011-01-03 => 1 = 0.3
2011-01-03 => 1.2 = 0.36
2011-01-09 => 1 = 0.32
Error: not a positive number.
Error: bad input => 2001-42-42
2012-01-11 => 1 = 7.1
Error: too large a number.
$>

Warning: The container(s) you use to validate this exercise will no longer be usable for the rest of this module.

*/

#include "BitcoinExchange.hpp"

bool	isValidDate(const std::string &date)
{
	std::istringstream	ss(date);
	int		year, month, day;
	char	dash1, dash2;

	if (!(ss >> year >> dash1 >> month >> dash2 >> day) || dash1 != '-' || dash2 != '-' \
	|| year < 0 || month <= 0 || month > 12 || day <= 0 || day > 31)
	{
		return (false);
	}
	return (true);
}

bool	isValidValue(const std::string &value, float &outputValue)
{
	std::istringstream	ss(value);
	ss >> outputValue;

	if (ss.fail() || !ss.eof())
	{
		return (false); // non-numeric values or other invalid formats
	}
	
	if (outputValue < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (false);
	}
	
	if (outputValue > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return (false);
	}
	return (true);
}

/*
function to trim leading and trailing whitespaces
*/
std::string	trim(const std::string &str)
{
	size_t	first = str.find_first_not_of(" \n\r\t");
	size_t	last = str.find_last_not_of(" \n\r\t");

	if (first == std::string::npos || last == std::string::npos)
		return ("");
	else
		return (str.substr(first, last - first + 1));
}

/*
function to check if the fisrt line is a header
*/
bool	isHeaderLine(const std::string &line)
{
	std::istringstream	ss(line);
	std::string	dateHeader;
	std::string	valueHeader;
	
	if (std::getline(ss, dateHeader, '|') && std::getline(ss, valueHeader))
	{
		// trim whitespaces
		dateHeader = trim(dateHeader);
		valueHeader = trim(valueHeader);
		return ((dateHeader == "date" && valueHeader == "value"));
	}
	return (false);
}

void	processLine(const std::string &line, BitcoinExchange &btc)
{
	std::istringstream	ss(line);
	std::string	date;
	std::string	valueStr;

	if(std::getline(ss, date, '|') && std::getline(ss, valueStr))
	{
		date = trim(date);
		valueStr = trim(valueStr);
		
		if (!isValidDate(date))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			return ;
		}
			
		float	value;
		if (!isValidValue(valueStr, value))
		{
			return ; // error msg handled in 'isValidValue()'
		}
		float	rate = btc.getPriceForDate(date);
		float	result = value * rate;
		std::cout << date << " => " << value << " = " << result << std::endl;
	}
	else
	{
		std::cout << "Error: bad input => " << line << std::endl;
	}
}

/*
this version skips the line in the pdf example:
"date | value"
*/
bool	loadInputFile(const std::string &filename, BitcoinExchange &btc)
{
	std::ifstream	inputFile(filename.c_str());
	
	if (!inputFile.is_open())
	{
		std::cout << "Error: could not open file" << std::endl;
		return (false);
	}
	
	std::string	line;
	// read the first line and check if it's a header
	if (std::getline(inputFile, line))
	{
		if (!isHeaderLine(line))
		{
			// not a header, process it as data
			processLine(line, btc);
		}
	}

	// process the remaining lines
	while (std::getline(inputFile, line))
	{
		processLine(line, btc);
	}

	inputFile.close();
	return (true);
}

// bool	loadInputFile(const std::string &filename, BitcoinExchange &btc)
// {
// 	std::ifstream	inputFile(filename.c_str());
	
// 	if (!inputFile.is_open())
// 	{
// 		std::cout << "Error: could not open file" << std::endl;
// 		return (false);
// 	}

// 	std::string	line;
// 	while (std::getline(inputFile, line))
// 	{
// 		processLine(line, btc);
// 	}

// 	inputFile.close();
// 	return (true);
// }

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Error: could not open file" << std::endl;
		return (1);
	}

	BitcoinExchange	btc;
	try
	{
		btc.loadDatabase("data.csv"); // define as a constant in header ?
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}

	if (!loadInputFile(argv[1], btc))
	{
		return (1);
	}

	return (0);
}
