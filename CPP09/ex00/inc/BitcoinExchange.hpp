/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:13:09 by cdumais           #+#    #+#             */
/*   Updated: 2024/08/18 18:04:40 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <cerrno>		// errno: what error occured during last function call
# include <cmath>		// std::round: rounding floating-point values to the nearest integer
# include <cstring>		// std::strerror: convert errno value to error message string
# include <fstream>		// std::ifstream: file input operations
# include <iomanip>		// std::fixed, std::setprecision: formatting output to ensure consistent decimal places
# include <iostream>	// std::cout, std::endl: standard input and output stream operations
# include <map>			// std::map: storing the exchange rates with dates as keys
# include <sstream>		// std::istringstream, std::ostringstream: string stream operations (parsing and formatting strings)
# include <stdexcept>	// std::runtime_error: throwing exceptions when file operations fail
# include <string>		// std::string: handling and manipulating strings

# define DATABASE_PATH	"data.csv"

class BitcoinExchange
{
	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &other);
		~BitcoinExchange(void);
		BitcoinExchange&	operator=(const BitcoinExchange &other);

		void	loadDatabase(const std::string &filename);
		void	processInputFile(const std::string &filename);
	
	private:
		std::map<std::string, float>	_exchangeRates;
		
		std::string	_trim(const std::string &str) const;
		bool	_isValidDate(const std::string &date) const;
		bool	_isValidValue(const std::string &value, float &outputValue, std::string &errorMsg) const;
		bool	_isHeaderLine(const std::string &line) const;
		float	_getPriceForDate(const std::string &date) const;
		void	_printError(const std::string &errorMsg, const std::string &line) const;
		bool	_parseLine(const std::string &line, std::string &date, std::string &valueStr) const;
		void	_processValidData(const std::string &date, float value) const;
		void	_processLine(const std::string &line);
};

#endif // BITCOINEXCHANGE_HPP
