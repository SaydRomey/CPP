/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:56:14 by cdumais           #+#    #+#             */
/*   Updated: 2024/11/07 13:41:07 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <cctype>		// isdigit: identifying numeric characters
# include <iostream>	// cout, endl: standard input and output stream operations
# include <sstream>		// istringstream, ostringstream: string stream operations (parsing and formatting strings)
# include <stack>		// stack: containers operating in a LIFO context (last-in first-out)
# include <stdexcept>	// runtime_error: throwing exceptions when file operations fail
# include <string>		// string: handling and manipulating strings

class RPN
{
	public:
		RPN(void);
		RPN(const RPN &other);
		~RPN(void);
		RPN&	operator=(const RPN &other);

		int	evaluate(const std::string &expression);

	private:
		std::stack<int>	_stack;

		enum e_valid
		{
			VALID,
			MISSING_OPERATOR,
			MISSING_OPERAND,
			NOT_ENOUGH_OPERANDS,
			INVALID_TOKEN
		};

		bool	_isOperator(const std::string &token) const;
		int		_applyOperation(const std::string &operation, int a, int b) const;
		bool	_isSingleDigit(const std::string &expression) const;
		e_valid	_isValidRPN(const std::string &expression) const;

};

#endif // RPN_HPP
