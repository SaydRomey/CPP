/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 20:47:09 by cdumais           #+#    #+#             */
/*   Updated: 2024/07/07 22:23:47 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/* ************************************************************************** */ // Constructors / Destructors

Intern::Intern(void)
{
	std::cout << GRAYTALIC << "Intern [default constructor]" << RESET << std::endl;
}

Intern::Intern(const Intern &other)
{
	*this = other;
	std::cout << GRAYTALIC << "Intern [copy constructor]" << RESET << std::endl;
}

Intern::~Intern(void)
{
	std::cout << GRAYTALIC << "Intern [default destructor]" << RESET << std::endl;
}

/* ************************************************************************** */ // Functions / Methods

AForm*	Intern::makeForm(const std::string &formName, const std::string &target)
{
	size_t	i = 0;
	while (i < FORM_NUM)
	{
		if (_formNames[i] == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (_formMakers[i](target));
		}
		i++;
	}
	throw FormNotFoundException();
}

AForm*	Intern::_makePresidentialPardonForm(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::_makeRobotomyRequestForm(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::_makeShrubberyCreationForm(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}
/* ************************************************************************** */ // Static Member Initialization

const std::string	Intern::_formNames[] = {
	"presidential pardon",
	"robotomy request",
	"shrubbery creation"
};

const Intern::FormMaker	Intern::_formMakers[] = {
	&Intern::_makePresidentialPardonForm,
	&Intern::_makeRobotomyRequestForm,
	&Intern::_makeShrubberyCreationForm
};

/* ************************************************************************** */ // Operators

Intern&	Intern::operator=(const Intern &other)
{
	// (void)other;
	if (this != &other)
	{
		*this = other;
	}
	return (*this);
}

/* ************************************************************************** */ // Exceptions

const char*	Intern::FormNotFoundException::what() const throw()
{
	return ("Form not found");
}
