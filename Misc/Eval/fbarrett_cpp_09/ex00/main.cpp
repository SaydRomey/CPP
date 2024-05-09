/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrett <fbarrett@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:06:29 by fbarrett          #+#    #+#             */
/*   Updated: 2024/05/09 09:31:16 by fbarrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

using std::cout;
using std::endl;

class InvalidDate : public std::exception {
	public:
		const char *what(void) const throw() {
			return ("Invalid date in input file.");
		}
};

int check_input_date(std::string line) {
	int date;
	if (line.at(4) != '-' || line.at(7) != '-' || line.at(10) != ' ' || 
			line.at(11) != '|' || line.at(12) != ' ') {
		cout << "Invalid data format in: " << line << endl;
		return (0);
	}
	int year = std::stoi(line.substr(0, 4));
	int month = std::stoi(line.substr(5, 7));
	int day = std::stoi(line.substr(8, 10));
	if (year < 2009 || year > 2022 || month < 1 || month > 12 || 
		day < 1 || day > 31) {
		cout << "Invalid date provided: " << line.substr(0, 10);
		cout << " is out of range." << endl;
		return (0);
	}
	date = (year - 2000) * 372 + (month - 1) * 31 + day;
	return (date);
}

int main(int argc, char** argv) {
	int bar;
	int date;
	try {
		if (argc != 2) {
			std::cerr << "You need to provide exactly 1 file." << endl;
			return (1);
		}
		BitcoinExchange data;
		std::string line;
		std::ifstream inputFile(argv[1]);
		if (!inputFile) {
			std::cerr << "Could not open input file." << endl;
			return (1);
		}
		while (getline(inputFile, line)) {
			if (line.empty())
				continue ;
			date = check_input_date(line);
			if (!date)
				continue ;
			bar = line.find('|');
			data.print_value(line.substr(0, bar - 1), date, 
				std::stod(line.substr(bar + 2))); 
		}
		inputFile.close();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << endl;
		return (1);
	}
	return (0);
}
