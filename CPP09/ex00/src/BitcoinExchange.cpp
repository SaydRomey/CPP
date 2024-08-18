/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:53:53 by cdumais           #+#    #+#             */
/*   Updated: 2024/08/18 18:40:58 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _exchangeRates(other._exchangeRates) {}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		_exchangeRates = other._exchangeRates;
	}
	return (*this);
}

/* ************************************************************************** */ // Public Methods

/*
Loads into the '_exchangeRates' map, the Bitcoin exchange rates from given CSV file
(defined as 'DATABASE_PATH' in 'BitcoinExchange.hpp')
CSV file is expected to have lines formatted as "date,rate"
Throws 'std::runtime_error' with detailed information if the file cannot be opened
*/
void	BitcoinExchange::loadDatabase(const std::string &filename)
{
	std::ifstream	databaseFile(filename.c_str());
	if (!databaseFile.is_open())
	{
		std::string	errorMsg = "Error: could not open database file: " + filename + " - " + std::strerror(errno);
		throw (std::runtime_error(errorMsg));
	}
	std::string	line;
	while (std::getline(databaseFile, line))
	{
		std::istringstream	ss(line);
		std::string			date;
		float				rate;
		
		if (std::getline(ss, date, ',') && (ss >> rate))
		{
			_exchangeRates[date] = rate;
		}
	}
	databaseFile.close();
}

/*
Processes input file line by line
Each line is expected to be in the format "date | value"
If the fist line is a header ("date | value" as in the PDF example), it is skipped
Valid lines are proceessed using '_processLine()'
Throws 'std::runtime_error' with detailed information if the file cannot be opened or if the file is empty
*/
void	BitcoinExchange::processInputFile(const std::string &filename)
{
	std::ifstream	inputFile(filename.c_str());
	
	if (!inputFile.is_open())
	{
		std::string	errorMsg = "Error: could not open input file: " + filename + " - " + std::strerror(errno);
		throw (std::runtime_error(errorMsg));
	}
	std::string	line;
	if (!std::getline(inputFile, line))
	{
		std::string	errorMsg = "Error: input file is empty: " + filename;
		throw (std::runtime_error(errorMsg));
	}
	if (!_isHeaderLine(line))
	{
		_processLine(line);
	}
	while (std::getline(inputFile, line))
	{
		_processLine(line);
	}
	inputFile.close();
}

/* ************************************************************************** */ // Private Helper Methods

/*
Removes leading and trailing whitespace
*/
std::string	BitcoinExchange::_trim(const std::string &str) const
{
	size_t	first = str.find_first_not_of(" \n\r\t");
	size_t	last = str.find_last_not_of(" \n\r\t");

	if (first == std::string::npos || last == std::string::npos)
	{
		return ("");
	}
	else
	{
		return (str.substr(first, last - first + 1));
	}
}

/*
Validates the date string format
A valid date must be in the format "Year-Month-Day" with valid ranges:
- Year must be non-negative
- Month must be between 1 and 12
- Day must be between 1 and 31
*/
bool	BitcoinExchange::_isValidDate(const std::string &date) const
{
	std::istringstream	ss(date);
	int		year, month, day;
	char	dash1, dash2;

	bool	parsedCorrectly = (ss >> year >> dash1 >> month >> dash2 >> day);
	bool	dashesAreCorrect = (dash1 == '-' && dash2 == '-');

	bool	yearIsValid = (year >= 0);
	bool	monthIsValid = (month > 0 && month <= 12);
	bool	dayIsValid = (day > 0 && day <= 31);

	if (parsedCorrectly && dashesAreCorrect && yearIsValid && monthIsValid && dayIsValid)
	{
		return (true);
	}
	return (false);
}

/*
Validates the value string format
A valid value must be a float or positive integer, between 0 and 1000
If the validation fails, an appropriate error message is set in 'errorMsg'
*/
bool	BitcoinExchange::_isValidValue(const std::string &value, float &outputValue, std::string &errorMsg) const
{
	std::istringstream	ss(value);
	ss >> outputValue;

	if (ss.fail() || !ss.eof())
	{
		errorMsg = "Error: bad input";
		return (false);
	}
	if (outputValue < 0)
	{
		errorMsg = "Error: not a positive number.";
		return (false);
	}
	if (outputValue > 1000)
	{
		errorMsg = "Error: too large a number.";
		return (false);
	}
	return (true);
}

/*
Checks if 'line' is the header line ("date | value")
returns true if the line matches the header format
*/
bool	BitcoinExchange::_isHeaderLine(const std::string &line) const
{
	std::istringstream	ss(line);
	std::string	dateHeader;
	std::string	valueHeader;
	
	if (std::getline(ss, dateHeader, '|') && std::getline(ss, valueHeader))
	{
		dateHeader = _trim(dateHeader);
		valueHeader = _trim(valueHeader);
		return ((dateHeader == "date" && valueHeader == "value"));
	}
	return (false);
}

/*
Retrieves the Bitcoin exchange rate for a given date
If exact date is not found, returns the closest earlier date's rate
If no earlier date exists, returns 0.0f

'lower_bound()' returns an iterator pointing to the first element that is not less than the given 'date'
if 'date' is present in the map, 'it' will point directly to that element
if 'date' is not present, 'it' will point to the next higher date, or to the end of the map if no such element exists

If 'it' points to an element past the last element or to an element with a higher date than the given date,
it is decremented (--it) to point to the closest earlier date in the map
(only decremented if it does not already point to the first element to avoid going out of bounds)
*/
float	BitcoinExchange::_getPriceForDate(const std::string &date) const
{
	std::map<std::string, float>::const_iterator	it = _exchangeRates.lower_bound(date);

	if (it != _exchangeRates.begin() && (it == _exchangeRates.end() || it->first != date))
	{
		--it;
	}
	if (it != _exchangeRates.end())
		return (it->second);
	else
		return (0.0f);
}

/*
Centralized error message printing
If error is "Error: bad input", prints the line that triggered an error
Otherwise it prints a specific error message
*/
void	BitcoinExchange::_printError(const std::string &errorMsg, const std::string &line) const
{
	if (errorMsg == "Error: bad input")
	{
		std::cout << errorMsg << " => " << line << std::endl;
	}
	else
	{
		std::cout << errorMsg << std::endl;
	}
}

/*
Handles the extraction of 'date' and 'valueStr' from the input line
- Creates an input string stream from the input line
- Tries to extract the 'date' portion from the stream, stopping at the '|' character
	- Trims any leading or trailing whitespace from 'date'
- Tries to extract the 'valueStr' portion from the stream, reading until the end of the line
	- Trims any leading or trailing whitespace from 'valueStr'
If both parts were successfully extracted, returns true
*/
bool	BitcoinExchange::_parseLine(const std::string &line, std::string &date, std::string &valueStr) const
{
	std::istringstream	ss(line);

	if (!std::getline(ss, date, '|'))
		return (false);
	date = _trim(date);
	if (!_isValidDate(date))
		return (false);
	
	if (!std::getline(ss, valueStr))
		return (false);
	valueStr = _trim(valueStr);

	return (true);
}

/*
Handles the logic for processing and printing valid data
Retrieves the exchange rate for the given date, computes the result, and prints the output
Handles monetary values with precision:
- Converts value (in dollars) and the exchange rate to cents
	by multiplying it by 100 and rounding to the nearest integer
- Calculates the result in cents, then divides by 100 to maintain correct scaling
- Converts the result back to dollars to restore it to a floating-point (double)
Uses 'std::fixed' to avoid scientific notation,
and 'std::setprecision()' to format the result conditionally (as in the PDF example)
and print result in a monetary format (with between zero and two decimal places)
*/
void	BitcoinExchange::_processValidData(const std::string &date, float value) const
{
	long long int	valueInCents, rateInCents, resultInCents;
	float			rate = _getPriceForDate(date);
	double			result;

	valueInCents = static_cast<long long int>(std::round(value * 100.0));
	rateInCents = static_cast<long long int>(std::round(rate * 100.0));
	resultInCents = valueInCents * rateInCents / 100;
	
	result = static_cast<double>(resultInCents) / 100.0;

	std::ostringstream	resultStream;
	resultStream << std::fixed << std::setprecision(2);

	if (result == std::round(result))
		resultStream << std::setprecision(0); // no decimals if result is a whole number
	else if (std::round(result * 100) == std::round(result * 10) * 10)
		resultStream << std::setprecision(1); // one decimal if the second decimal is zero
	else
		resultStream << std::setprecision(2); // two decimals otherwise
	
	resultStream << result;
	
	std::cout << date << " => " << value << " = " << resultStream.str() << std::endl;
}

/*
Processes a single line from the input file
Trims the line, validates the date and value,
and either processes the data or prints an appropriate error message
(skips empty lines and lines containing whitespace)
*/
void	BitcoinExchange::_processLine(const std::string &line)
{
	std::string	trimmedLine = _trim(line);
	
	if (trimmedLine.empty())
		return ;
	
	std::string	date;
	std::string	valueStr;
	if (!(_parseLine(trimmedLine, date, valueStr)))
	{
		return (_printError("Error: bad input", trimmedLine));
	}
	
	float		value;
	std::string	errorMsg;
	if (!_isValidValue(valueStr, value, errorMsg))
	{
		return (_printError(errorMsg, trimmedLine));
	}
	_processValidData(date, value);
}
