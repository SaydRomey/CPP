/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:52:33 by cdumais           #+#    #+#             */
/*   Updated: 2024/08/18 21:08:49 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
You must create a program with these constraints:
• The program name is RPN.
• Your program must take an inverted Polish mathematical expression as an argu- ment.
• The numbers used in this operation and passed as arguments will always be less than 10.
	The calculation itself but also the result do not take into account this rule.
• Your program must process this expression and output the correct result on the standard output.
• If an error occurs during the execution of the program an error message should be displayed on the standard output.
• Your program must be able to handle operations with these tokens: "+ - / *".

You must use at least one container in your code to validate this exercise.
(the std::map container is already used in previous exercise and cannot be used again)

You don’t need to manage the brackets or decimal numbers.

Here is an example of a standard use:
$> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42
$> ./RPN "7 7 * 7 -"
42
$> ./RPN "1 2 * 2 / 2 * 2 4 - +"
0
$> ./RPN "(1 + 1)"
Error
$>



*/

#include "RPN.hpp"

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	return (0);
}

