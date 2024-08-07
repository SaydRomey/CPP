/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 20:25:27 by cdumais           #+#    #+#             */
/*   Updated: 2024/07/09 13:02:28 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

# define FORM_NUM 3

class Intern
{
	private:

		// Private Static Methods
		static AForm*	_makePresidentialPardonForm(const std::string &target);
		static AForm*	_makeRobotomyRequestForm(const std::string &target);
		static AForm*	_makeShrubberyCreationForm(const std::string &target);

		// Private Static Members
		typedef AForm *(*FormMaker)(const std::string &target);
		static const std::string	_formNames[];
		static const FormMaker		_formMakers[];
		
	public:
	
		// Constructors / Destructors
		Intern(void);
		Intern(const Intern &other);
		~Intern(void);

		// Functions / Methods
		AForm*	makeForm(const std::string &formName, const std::string &target);
		
		// Operators
		Intern&	operator=(const Intern &other);

		// Exceptions
		class FormNotFoundException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif // INTERN_HPP
