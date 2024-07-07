/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:15:28 by cdumais           #+#    #+#             */
/*   Updated: 2024/07/07 19:06:34 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* ************************************************************************** */ // Constructors / Destructors

Bureaucrat::Bureaucrat(void) : _name(NAME_DFLT), _grade(GRADE_DFLT)
{
	std::cout \
		<< GRAYTALIC << "Bureaucrat '" << _name \
		<< "' [default constructor]" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std:: string &name, unsigned int grade) \
: _name(name), _grade(grade)
{
	if (grade > GRADE_MIN)
		throw GradeTooLowException();
	if (grade < GRADE_MAX)
		throw GradeTooHighException();
	std::cout \
		<< GRAYTALIC << "Bureaucrat '" << _name \
		<< "', grade '" << _grade \
		<< "' [parametrized constructor]" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name)
{
	*this = other;
	std::cout \
		<< GRAYTALIC << "Bureaucrat '" << _name \
		<< "' [copy constructor]" << RESET << std::endl;	
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout \
		<< GRAYTALIC << "Bureaucrat '" << _name \
		<< "' [default destructor]" << RESET << std::endl;	
}

/* ************************************************************************** */ // Getters / Setters

const std::string&	Bureaucrat::getName(void) const
{
	return (_name);
}

unsigned int	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

/* ************************************************************************** */ // Functions / Methods

void	Bureaucrat::incrementGrade(void)
{
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed '" << form.getName() << "'" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->_name << " couldn't sign '" << form.getName() \
		<< "' because: " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executed '" << form.getName()  << "'" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->_name << " couldn't execute '" << form.getName() \
		<< "' because: " << e.what() << std::endl;
	}
}

/* ************************************************************************** */ // Operators

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other && this->_grade != other._grade)
	{
		this->_grade = other._grade;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream &out, const Bureaucrat &param)
{
	out \
		<< "Bureaucrat name:\t" \
		<< param.getName() << "\n" \
		<< "Bureaucrat grade:\t" \
		<< param.getGrade();
	return (out);
}

/* ************************************************************************** */ // Exceptions

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}
