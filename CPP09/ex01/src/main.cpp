/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:52:33 by cdumais           #+#    #+#             */
/*   Updated: 2024/11/02 20:25:42 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
You must create a program with these constraints:
• The program name is RPN.
• Your program must take an inverted Polish mathematical argument as an argument.
• The numbers used in this operation and passed as arguments will always be less than 10.
	The calculation itself but also the result do not take into account this rule.
• Your program must process this argument and output the correct result on the standard output.
• If an error occurs during the execution of the program
	an error message should be displayed on the standard output.
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

#define RESET		"\033[0m"
#define GRAY		"\033[90m"
#define ITALIC		"\033[3m"
#define UNDERLINE	"\033[4m"

void	comment(const std::string &str, const std::string &details)
{
	std::cout << GRAY << ITALIC << "\n" << str << RESET;
	std::cout << GRAY << ITALIC << details << RESET;
}

void	testPrint(const int result)
{
	if (result >= 0)
		std::cout << result;
	else
		std::cout << GRAY << ITALIC << "[Invalid result]";
	std::cout << RESET << std::endl;
}

void	testEdgeCases(void)
{
	RPN	rpn;
	int	result;

	comment(std::string(42, '*'), "\n");
	comment(std::string(UNDERLINE) + "Testing edge cases", "\n");

	comment("Valid one-digit single argument (\"6\")", "\n");
	result = rpn.evaluate("6");
	testPrint(result);

	comment("Two-digit single number as argument (\"42\")", "\n");
	result = rpn.evaluate("42");
	testPrint(result);
	
	comment("Multi-digit number (\"8 9 * 42 +\")", "\n");
	rpn.evaluate("8 9 * 42 +");
	testPrint(result);

	comment("Invalid character (\"8 9 * a +\")", "\n");
	rpn.evaluate("8 9 * a +");
	testPrint(result);

	comment("Missing operands (\"+ *\")", "\n");
	rpn.evaluate("+ *");
	testPrint(result);

	comment("Not enough operands (\"2 *\")", "\n");
	rpn.evaluate("2 *");
	testPrint(result);

	comment("Missing operator (\"8 2\")", "\n");
	rpn.evaluate("8 2");
	testPrint(result);

	// Check the stack's size at the end to confirm only one result remains
	comment("Invalid final stack size (\"8 9 * 9 -\")", "\n");
	rpn.evaluate("8 9 * 9 -");
	testPrint(result);

	// Handle division by zero
	comment("Division by zero (\"1 0 /\")", "\n");
	rpn.evaluate("1 0 /");
	testPrint(result);

	comment(std::string(42, '*'), "\n");
}

int	main(int argc, char *argv[])
{
	testEdgeCases();
	
	if (argc != 2)
	{
		std::cout << "ERROR" << std::endl;
		return (1);
	}
	
	RPN	rpn;
	
	int	result = rpn.evaluate(argv[1]);

	if (result != -1)
	{
		std::ostringstream	oss;
		oss << result;
		comment(std::string(UNDERLINE) + "Evaluating argument", ": \"" + std::string(argv[1]) + "\" = ");
		
		std::cout << result << "\n" << std::endl;
	}
	return (0);
}

/*
Reverse Polish Notation (RPN)
(write mathematical arguments without needing parentheses)
Also known as postfix notation:
(operators like +, -, *, and / come after the numbers they apply to.)
As opposed to the standard "infix" notation (e.g., 3 + 4),
where operators are placed between numbers,

This makes it easy to evaluate arguments from left to right
without worrying about which parts to calculate first.

In RPN:
- The argument "3 4 +" means "3 + 4" and evaluates to 7.
- "5 1 2 + 4 * + 3 -" represents "5 + ((1 + 2) * 4) - 3" and evaluates to 14.

The key benefits of RPN:
- Removes the need for parentheses because the order of operations is always unambiguous.
- Easier for computers to evaluate arguments directly,
as they can process operators immediately once the operands are available.

To evaluate an RPN argument:
1. Start reading from left to right.
2. When we see a number, we push it onto the stack.
3. When we see an operator,
we pop the required number of operands from the stack, apply the operator,
and push the result back onto the stack.
4. At the end of the argument, the stack should contain exactly one result,
which is the final answer.

Example (short):

argument: "3 4 + 2 * 7 /"
- Push 3 and 4 onto the stack.
- "+" -> Pop 3 and 4, add them (3 + 4 = 7), and push 7.
- Push 2.
- "*" -> Pop 7 and 2, multiply (7 * 2 = 14), and push 14.
- Push 7.
- "/" -> Pop 14 and 7, divide (14 / 7 = 2), and push 2.
Final Result: 2


Example (more precisions):

argument: "3 4 + 2 * 7 /"
- Start with an empty stack.
- Read "3": it's a number, so put it on the stack. Stack: [3]
- Read "4": it's a number, so put it on the stack. Stack: [3, 4]
- Read "+": it's an operator, so take the last two numbers (3 and 4), add them (3 + 4 = 7),
  and put the result back on the stack. Stack: [7]
- Read "2": it's a number, so put it on the stack. Stack: [7, 2]
- Read "*": it's an operator, so take the last two numbers (7 and 2), multiply them (7 2 = 14),
  and put the result back on the stack. Stack: [14]
- Read "7": it's a number, so put it on the stack. Stack: [14, 7]
- Read "/": it's an operator, so take the last two numbers (14 and 7), divide them (14 / 7 = 2),
  and put the result back on the stack. Stack: [2]
- The argument is finished, and the stack has one number left, which is the answer: 2

*/
