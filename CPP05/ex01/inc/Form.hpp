#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

# define GRADE_MIN	150
# define GRADE_MAX	1
# define GRADE_DFLT	42

# define RESET		"\033[0m"
# define RED		"\033[91m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define PURPLE		"\033[95m"
# define ORANGE		"\033[38;5;208m"
# define GRAYTALIC	"\033[3;90m"

class Form
{
	private:
		// Attributes
		const std::string	_name;
		bool				_is_signed;
		const unsigned int	_grade_to_sign;
		const unsigned int	_grade_to_execute;

	public:
		// Constructors / Destructors
		Form(void);
		Form(const std::string name, const unsigned int grade_to_sign, const unsigned int grade_to_execute);
		Form(const Form &other);
		~Form(void);

		// Getters / Setters
		const std::string&	getName(void) const;
		bool				getIsSigned(void) const;
		unsigned int		getGradeToSign(void) const;
		unsigned int		getGradeToExecute(void) const;

		// Functions / Methods
		unsigned int	checkGrade(unsigned int grade) const;
		void			beSigned(const Bureaucrat &bureaucrat);

		// Operators
		Form&	operator=(const Form &other);

		// Exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream &out, const Form &other);

#endif // FORM_HPP
