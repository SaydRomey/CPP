/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:13:09 by cdumais           #+#    #+#             */
/*   Updated: 2024/08/11 23:46:41 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <cstdlib>
# include <fstream>
# include <iostream>
# include <map>
# include <sstream>
# include <stdexcept>
# include <string>

class BitcoinExchange
{
	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &other);
		~BitcoinExchange(void);

		BitcoinExchange&	operator=(const BitcoinExchange &other);

		void	loadDatabase(const std::string &filename);
		bool	processInputFile(const std::string &filename);
	
	private:
		std::map<std::string, float>	_exchangeRates;

		bool	isValidDate(const std::string &date) const;
		bool	isValidValue(const std::string &value, float &outputValue) const;
		std::string	trim(const std::string &str) const;
		bool	isHeaderLine(const std::string &line) const;
		float	getPriceForDate(const std::string &date) const;
		void	processLine(const std::string &line);
};

#endif // BITCOINEXCHANGE_HPP
