#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <string>
# include <iostream>
# include <map>
# include <fstream>
# include <cmath>
# include <ctype.h>

class BitcoinExchange {
	public:
		std::map<int, double> bitcoin_map;
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange& old);
		~BitcoinExchange(void);
		BitcoinExchange & operator=(const BitcoinExchange & rhs);

		void print_value(std::string date, int key, double nbr);

	class InvalidDataFile : public std::exception {
		public:
			const char *what(void) const throw();
	};
};

#endif
