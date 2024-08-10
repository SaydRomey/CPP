/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:53:53 by cdumais           #+#    #+#             */
/*   Updated: 2024/08/09 19:10:52 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	// std::cout << GRAYTALIC << "BitcoinExchange [default constructor]" << RESET << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) \
: _exchangeRates(other._exchangeRates)
{
	// std::cout << GRAYTALIC << "BitcoinExchange [copy constructor]" << RESET << std::endl;
}


BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		_exchangeRates = other._exchangeRates;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
	// std::cout << GRAYTALIC << "BitcoinExchange [default destructor]" << RESET << std::endl;
}

/* ************************************************************************** */

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
