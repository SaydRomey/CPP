#include "BitcoinExchange.hpp"

using std::cout;
using std::endl;

BitcoinExchange::BitcoinExchange(void) {
	int coma;
	int year;
	int month;
	int day;
	int date;
	std::string line;
	std::ifstream dataFile("data.csv");
	if (!dataFile) {
		std::cerr << "Could not open data csv file." << endl;
		throw (InvalidDataFile());
	}
	while (getline(dataFile, line)) {
		if (line.at(0) != '2')
			continue ;
		year = std::stoi(line.substr(0, 4)) - 2000;
		month = std::stoi(line.substr(5, 7)) - 1;
		day = std::stoi(line.substr(8, 10));
		date = year * 372 + month * 31 + day;
		coma = line.find(',');
		bitcoin_map.insert(std::pair<int, double> (date, std::stod(line.substr(coma + 1))));
	}
	dataFile.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& old) {
	bitcoin_map = old.bitcoin_map;
}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange & rhs) {
	bitcoin_map = rhs.bitcoin_map;
	return (*this);
}

const char *BitcoinExchange::InvalidDataFile::what(void) const throw() {
	return ("Invalid file.");
}

void BitcoinExchange::print_value(std::string date, int key, double nbr) {
	int min_date = 3350;
	bool is_invalid_key = true;
	while (is_invalid_key) {
		try {bitcoin_map.at(key);}
		catch (...) {
			key--;
			if (key <= min_date) {
				cout << date << " => " << nbr << " = 0" << endl;
				return ;
			}
			continue;
		}
		is_invalid_key = false;
	}
	if (nbr < 0 || nbr > 1000) {
		cout << "Error: " << nbr << " is not a valid amount of bitcoin." << endl;
		return ;
	}
	double final_value = nbr * bitcoin_map[key];
	int precision = 1;
	while (pow(10, precision) < final_value) {
		precision += 1;
	}
	precision += 2;
	cout << std::setprecision(precision) << date << " => " << nbr << " = " << bitcoin_map[key] * nbr << endl;
}
