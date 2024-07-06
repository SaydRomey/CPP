/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 07:24:36 by cdumais           #+#    #+#             */
/*   Updated: 2024/07/06 09:52:58 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		// Attributes
		const std::string	_name;
		const std::string	_target;
		const unsigned int	_grade_to_sign;
		const unsigned int	_grade_to_execute;
		bool				_is_signed;

	public:
		// Constructors / Destructors
		AForm(void);
		AForm(const std::string name, const std::string target, const unsigned int grade_to_sign, const unsigned int grade_to_execute);
		AForm(const AForm &other);
		virtual ~AForm(void) = 0;

		// Getters / Setters
		const std::string&	getName(void) const;
		const std::string&	getTarget(void) const;
		unsigned int		getGradeToSign(void) const;
		unsigned int		getGradeToExecute(void) const;
		bool				getIsSigned(void) const;
		void				beSigned(const Bureaucrat &bureaucrat);

		// Functions / Methods
		unsigned int		checkGrade(unsigned int grade) const;
		virtual void		execute(const Bureaucrat &executor) const = 0; // Pure virtual function

		// Operators
		AForm&	operator=(const AForm &other);

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
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream &out, const AForm &param);

#endif // AFORM_HPP
