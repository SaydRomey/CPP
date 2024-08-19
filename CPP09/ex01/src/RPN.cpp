/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:56:11 by cdumais           #+#    #+#             */
/*   Updated: 2024/08/18 21:35:53 by cdumais          ###   ########.fr       */
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

int	RPN::evaluate(const std::string &expression)
{
	std::stringstream	ss(expression);
	std::string			token;

	while (ss >> token)
	{
		if (isdigit(token[0]) && token.length() == 1)
		{
			_stack.push(token[0] - '0'); // convert char to int
		}
		else if (_isOperator(token))
		{
			if (_stack.size() < 2)
			{
				std::cout << "Error" << std::endl;
				return (-1);
			}
			int	b = _stack.top();
			_stack.pop();
			int	a = _stack.top();
			_stack.pop();
			_stack.push(_applyOperation(token, a, b));
		}
		else
		{
			std::cout << "Error" << std::endl;
			return (-1);
		}
	}
	if (_stack.size() != 1)
	{
		std::cout << "Error" << std::endl;
		return (-1);
	}
	return (_stack.top());
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
		return (a / b);
	return (0); // should not reach here
}
