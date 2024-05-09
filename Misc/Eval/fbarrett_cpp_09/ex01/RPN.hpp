#ifndef RPN_HPP
# define RPN_HPP
# include <string>
# include <iostream>
# include <stack>
# include <ctype.h>

class RPN {
	public:
		std::stack<int> nbr_stack;
		std::stack<char> operator_stack;
		
		RPN(void);
		RPN(std::string equation);
		RPN(const RPN& old);
		~RPN(void);
		RPN & operator=(const RPN & rhs);

		int calculate(void);
};

	class InvalidEquation : public std::exception {
		public:
			const char *what(void) const throw();
	};

#endif
