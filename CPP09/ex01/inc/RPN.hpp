/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:56:14 by cdumais           #+#    #+#             */
/*   Updated: 2024/08/18 21:35:04 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <cctype>
# include <iostream>
# include <sstream>
# include <stack>
# include <string>

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

		bool	_isOperator(const std::string &token) const;
		int		_applyOperation(const std::string &operation, int a, int b) const;
};

#endif // RPN_HPP
