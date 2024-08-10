/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:13:09 by cdumais           #+#    #+#             */
/*   Updated: 2024/08/09 20:14:50 by cdumais          ###   ########.fr       */
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

# define RESET		"\033[0m"
# define RED		"\033[91m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define PURPLE		"\033[95m"
# define ORANGE		"\033[38;5;208m"
# define GRAYTALIC	"\033[3;90m"

/*
This class will store the Bitcoin price data.
It will have methods to load data from a CSV file.
It will have a method to get the price for a given date,
using the closest lower date if the exact date isn't available.

*/
class BitcoinExchange
{
	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange&	operator=(const BitcoinExchange &other);
		~BitcoinExchange(void);

		void	loadDatabase(const std::string &filename);
		float	getPriceForDate(const std::string &date) const;
	
	private:
		std::map<std::string, float>	_exchangeRates;
};

#endif // BITCOINEXCHANGE_HPP
