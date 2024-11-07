/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:56:11 by cdumais           #+#    #+#             */
/*   Updated: 2024/11/02 20:56:21 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(const RPN &other) : _stack(other._stack) {}

RPN::~RPN(void) {}

RPN&	RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		this->_stack = other._stack;
	}
	return (*this);
}

/* ************************************************************************** */ // Public Methods

bool	RPN::_isSingleDigit(const std::string &expression) const
{
	std::stringstream	ss(expression);
	std::string			token;

	ss >> token;
	bool	ssIsEmpty = (ss.rdbuf()->in_avail() == 0);
	
	return (isdigit(token[0]) && token.length() == 1 && ssIsEmpty);
}

/*
Checks if expression has at least one operator and two operands
*/
RPN::e_valid	RPN::_isValidRPN(const std::string &expression) const
{
	std::stringstream	ss(expression);
	std::string			token;
	int					operandCount = 0;
	bool				operatorFound = false;

	while (ss >> token)
	{
		if (isdigit(token[0]) && token.length() == 1)
			operandCount++;
		else if (_isOperator(token))
			operatorFound = true;
		else
			return (INVALID_TOKEN);
	}
	if (operandCount == 0)
		return (MISSING_OPERAND);
	if (operandCount == 1)
		return (NOT_ENOUGH_OPERANDS);
	if (!operatorFound)
		return (MISSING_OPERATOR);
	return (VALID);
}

int	RPN::evaluate(const std::string &expression)
{
	try
	{
		if (_isSingleDigit(expression))
			return (expression[0] - '0');

		std::stringstream	ss(expression);
		std::string			token;
		
		while (ss >> token)
		{
			if (isdigit(token[0]))
			{
				if (token.length() > 1)
					throw (std::invalid_argument("Numbers must be single digit"));

				_stack.push(token[0] - '0'); // convert char to int
			}
			else if (_isOperator(token))
			{
				if (_stack.size() < 2 && !_stack.empty())
					throw (std::runtime_error("Not enough operands for operation"));

				int	b = _stack.top();
				_stack.pop();
				int	a = _stack.top();
				_stack.pop();
				_stack.push(_applyOperation(token, a, b));
			}
			else
				throw (std::invalid_argument("Invalid token encountered"));
		}
		
		switch (_isValidRPN(expression))
		{
			case VALID:
				break ;
			case MISSING_OPERATOR:
				throw (std::runtime_error("Missing operator in expression!!"));
			case MISSING_OPERAND:
				throw (std::runtime_error("Missing operand in expression!!"));
			case NOT_ENOUGH_OPERANDS:
				throw (std::runtime_error("Not enough operands for operation!!"));
			case INVALID_TOKEN:
				throw (std::runtime_error("Invalid token encountered in expression!!"));
			default:
				throw (std::runtime_error("Unexpected validation result!!"));
		}

		if (_stack.size() != 1)
			throw (std::runtime_error("Invalid expression - final stack size is not 1"));

		return (_stack.top());
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return (-1);
	}
}

/* ************************************************************************** */ // Private Helper Methods

bool	RPN::_isOperator(const std::string &token) const
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

int		RPN::_applyOperation(const std::string &operation, int a, int b) const
{
	if (operation == "+")
		return (a + b);
	if (operation == "-")
		return (a - b);
	if (operation == "*")
		return (a * b);
	if (operation == "/")
	{
		if (b == 0)
		{
			throw (std::runtime_error("Division by zero"));
		}
		return (a / b);
	}
	throw (std::logic_error("Unsupported operation"));
}
