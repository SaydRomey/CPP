/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:15:26 by cdumais           #+#    #+#             */
/*   Updated: 2024/05/13 16:36:44 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include <string>

# define GRADE_MIN	150
# define GRADE_MAX	1
# define NAME_DFLT	"Artur Beca"
# define GRADE_DFLT	42

# define RESET		"\033[0m"
# define RED		"\033[91m"
# define GREEN		"\033[32m"
# define PURPLE		"\033[95m"
# define ORANGE		"\033[38;5;208m"
# define GRAYTALIC	"\033[3;90m"

class Bureaucrat
{
	private:
		// Attributes
		const std::string	_name;
		unsigned int		_grade;

	public:
		// Constructors / Destructors
		Bureaucrat(void);
		Bureaucrat(const std::string &name, unsigned int grade);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat(void);
		
		// Getters / Setters
		const std::string&	getName(void) const;
		unsigned int		getGrade(void) const;

		// Functions / Methods
		void	incrementGrade(void);
		void	decrementGrade(void);

		// Operators
		Bureaucrat&	operator=(const Bureaucrat &other);
		
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

std::ostream&	operator<<(std::ostream &out, const Bureaucrat &other);

#endif // BUREAUCRAT_HPP
