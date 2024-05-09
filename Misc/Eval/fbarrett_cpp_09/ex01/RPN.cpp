#include "RPN.hpp"

using std::cout;
using std::endl;

RPN::RPN(void) {}

RPN::RPN(std::string equation) {
	int i = equation.length() - 1;
	while (i >= 0) {
		if (isdigit(equation[i])) {
			nbr_stack.push(equation[i] - 48);
		}
		else if (equation[i] == '*' || equation[i] == '/' || 
			equation[i] == '-' || equation[i] == '+') {
			operator_stack.push(equation[i]);	
		}
		else if (equation[i] != ' ') {
			throw (InvalidEquation());
		}
		i--;
	}
}

RPN::RPN(const RPN& old) {
	nbr_stack = old.nbr_stack;
	operator_stack = old.operator_stack;
}

RPN::~RPN(void) {}

RPN & RPN::operator=(const RPN & rhs) {
	nbr_stack = rhs.nbr_stack;
	operator_stack = rhs.operator_stack;
	return (*this);
}

const char *InvalidEquation::what(void) const throw() {
	return ("Error: Invalid data in equation.");
}	

int RPN::calculate(void) {
	if (nbr_stack.size() != operator_stack.size() + 1)
		throw (InvalidEquation());
	int result = nbr_stack.top();
	while (nbr_stack.size() != 1) {
		nbr_stack.pop();
		if (operator_stack.top() == '+')
			result += nbr_stack.top();
		else if (operator_stack.top() == '-')
			result -= nbr_stack.top();
		else if (operator_stack.top() == '*')
			result *= nbr_stack.top();
		else if (operator_stack.top() == '/')
			result /= nbr_stack.top();
		operator_stack.pop();
	}
	nbr_stack.pop();
	return (result);
}
