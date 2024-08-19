#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>

# define RESET		"\033[0m"
# define RED		"\033[91m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define PURPLE		"\033[95m"
# define ORANGE		"\033[38;5;208m"
# define GRAYTALIC	"\033[3;90m"

class RPN
{
	private:
		// Attributes
	
	public:
		// Constructors / Destructors
		RPN(void);
		RPN(const RPN &other);
		~RPN(void);

		// Getters / Setters

		// Functions / Methods

		// Operators
		RPN&	operator=(const RPN &other);

		// Exceptions
};

// std::ostream&	operator<<(std::ostream &out, const RPN &param);

#endif // RPN_HPP
