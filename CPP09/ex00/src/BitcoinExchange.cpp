/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:53:53 by cdumais           #+#    #+#             */
/*   Updated: 2024/08/12 22:03:27 by cdumais          ###   ########.fr       */
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

void	BitcoinExchange::loadDatabase(const std::string &filename)
{
	std::ifstream	file(filename.c_str());
	if (!file.is_open())
	{
		throw (std::runtime_error("Error: could not open file"));
	}

	std::string	line;
	while (std::getline(file, line))
	{
		std::istringstream	ss(line);
		std::string	date;
		float	rate;

		if (std::getline(ss, date, ',') && (ss >> rate))
		{
			_exchangeRates[date] = rate;
		}
	}
	file.close();
}

bool	BitcoinExchange::processInputFile(const std::string &filename)
{
	std::ifstream	inputFile(filename.c_str());
	
	if (!inputFile.is_open())
	{
		std::cout << "Error: could not open file" << std::endl;
		return (false);
	}
	
	std::string	line;
	if (std::getline(inputFile, line))
	{
		if (!isHeaderLine(line)) // check if the first line is a header
		{
			processLine(line); // if not, process it as data
		}
	}
	while (std::getline(inputFile, line))
	{
		processLine(line); // process the remaining lines
	}
	
	inputFile.close();
	return (true);
}

/* ************************************************************************** */ // Private Helper Methods

std::string	BitcoinExchange::trim(const std::string &str) const
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
"A valid date will always be in the following format: Year-Month-Day."

// 	if (!(ss >> year >> dash1 >> month >> dash2 >> day) || dash1 != '-' || dash2 != '-' || year < 0 || month <= 0 || month > 12 || day <= 0 || day > 31)
// 		return (false);

*/
bool	BitcoinExchange::isValidDate(const std::string &date) const
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

bool	BitcoinExchange::isValidValue(const std::string &value, float &outputValue, std::string &errorMsg) const
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

bool	BitcoinExchange::isHeaderLine(const std::string &line) const
{
	std::istringstream	ss(line);
	std::string	dateHeader;
	std::string	valueHeader;
	
	if (std::getline(ss, dateHeader, '|') && std::getline(ss, valueHeader))
	{
		dateHeader = trim(dateHeader);
		valueHeader = trim(valueHeader);
		return ((dateHeader == "date" && valueHeader == "value"));
	}
	return (false);
}

float	BitcoinExchange::getPriceForDate(const std::string &date) const
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

/* ** need to split this in subfunctions **!

*/
void	BitcoinExchange::processLine(const std::string &line)
{
	if (line.empty())
	{
		return ;
	}
	
	std::istringstream	ss(line);
	std::string	date;
	std::string	valueStr;

	if(std::getline(ss, date, '|') && std::getline(ss, valueStr))
	{
		date = trim(date);
		valueStr = trim(valueStr);
		
		if (!isValidDate(date))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			return ;
		}
			
		float	value;
		std::string	errorMsg;
		if (!isValidValue(valueStr, value, errorMsg))
		{
			if (errorMsg == "Error: bad input")
			{
				std::cout << errorMsg << " => " << line << std::endl;
			}
			else
			{
				std::cout << errorMsg << std::endl;
			}
			return ;
		}
		
		float	rate = getPriceForDate(date);
		float	result = value * rate;
		std::cout << date << " => " << value << " = " << result << std::endl;
	}
	else
	{
		std::cout << "Error: bad input => " << line << std::endl;
	}
}
