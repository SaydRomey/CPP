#include "BitcoinExchange.hpp"

/* ************************************************************************** */ // Constructors / Destructors

BitcoinExchange::BitcoinExchange(void)
{
	std::cout << GRAYTALIC << "BitcoinExchange [default constructor]" << RESET << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
	std::cout << GRAYTALIC << "BitcoinExchange [copy constructor]" << RESET << std::endl;
}

BitcoinExchange::~BitcoinExchange(void)
{
	std::cout << GRAYTALIC << "BitcoinExchange [default destructor]" << RESET << std::endl;
}

/* ************************************************************************** */ // Getters / Setters

/* ************************************************************************** */ // Functions / Methods

/* ************************************************************************** */ // Operators

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange &other)
{
	// if (this != &other)
	// {}
	
	return (*this);
}

// std::ostream&	operator<<(std::ostream &out, const BitcoinExchange &param)

/* ************************************************************************** */ // Exceptions

