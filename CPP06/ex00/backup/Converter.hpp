/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:15:37 by cdumais           #+#    #+#             */
/*   Updated: 2024/07/15 22:10:35 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <cmath>
# include <exception>
# include <iomanip>
# include <iostream>
# include <limits>
# include <sstream>
# include <string>

# define RESET		"\033[0m"
# define RED		"\033[91m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define PURPLE		"\033[95m"
# define ORANGE		"\033[38;5;208m"
# define GRAYTALIC	"\033[3;90m"

// using std::string;

class Converter
{
	public:
		// Constructors / Destructors
		Converter(void);
		Converter(const Converter &other);
		Converter(const std::string &input);
		~Converter(void);
		
		// Functions / Methods
		void	convert(void);

		// Operators
		Converter&	operator=(const Converter &other);

	private:
		// Attributes
		std::string	_input;

		void	_detectTypeAndConvert(void);
		bool	_isChar(void) const;
		bool	_isInt(void) const;
		bool	_isFloat(void) const;
		bool	_isDouble(void) const;

		void	_convertFromChar(char c);
		void	_convertFromInt(int i);
		void	_convertFromFloat(float f);
		void	_convertFromDouble(double d);

		void	_printChar(char c) const;
		void	_printInt(int i) const;
		void	_printFloat(float f) const;
		void	_printDouble(double d) const;

		// Exceptions
		class InvalidInputException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif // CONVERTER_HPP
