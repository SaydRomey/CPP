/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 07:24:54 by cdumais           #+#    #+#             */
/*   Updated: 2024/07/06 13:04:47 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/* ************************************************************************** */ // Constructors / Destructors

AForm::AForm(void) : _name("default Form"), _target("n\\a"), \
_grade_to_sign(GRADE_MIN), \
_grade_to_execute(GRADE_MIN)
{
	_is_signed = false;
	std::cout \
		<< GRAYTALIC << "Form '" << _name \
		<< "' [default constructor]" << RESET << std::endl;
}

AForm::AForm(const std::string name, const std::string target, \
const unsigned int grade_to_sign, \
const unsigned int grade_to_execute) \
: _name(name), _target(target), \
_grade_to_sign(this->checkGrade(grade_to_sign)), \
_grade_to_execute(this->checkGrade(grade_to_execute))
{
	_is_signed = false;
	std::cout \
		<< GRAYTALIC << "Form '" << _name \
		<< "' [parametrized constructor]" << RESET << std::endl;
}

AForm::AForm(const AForm &other) : _name(other._name), _target(other._target), \
_grade_to_sign(other._grade_to_sign), \
_grade_to_execute(other._grade_to_execute)
{
	*this = other;
	std::cout \
		<< GRAYTALIC << "Form '" << _name \
		<< "' [copy constructor]" << RESET << std::endl;
}

AForm::~AForm(void)
{
	std::cout \
		<< GRAYTALIC << "Form '" << _name \
		<< "' [default destructor]" << RESET << std::endl;
}

/* ************************************************************************** */ // Getters / Setters

const std::string&	AForm::getName(void) const
{
	return (_name);
}

const std::string& AForm::getTarget(void) const
{
	return (_target);
}

unsigned int	AForm::getGradeToSign(void) const
{
	return (_grade_to_sign);
}

unsigned int	AForm::getGradeToExecute(void) const
{
	return (_grade_to_execute);
}

bool	AForm::getIsSigned(void) const
{
	return (_is_signed);
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_grade_to_sign)
	{
		this->_is_signed = true;
	}
	else
		throw GradeTooLowException();
}

/* ************************************************************************** */ // Functions / Methods

unsigned int	AForm::checkGrade(unsigned int grade) const
{
	if (grade > GRADE_MIN)
		throw GradeTooLowException();
	if (grade < GRADE_MAX)
		throw GradeTooHighException();
	return (grade);
}

/* ************************************************************************** */ // Operators

AForm&	AForm::operator=(const AForm &other)
{
	if (this != &other && this->_is_signed != other._is_signed)
	{
		this->_is_signed = other._is_signed;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream &out, const AForm &param)
{
	out \
		<< "\nForm name:\t\t" << param.getName() << "\n" \
		<< "Target:\t\t\t" << param.getTarget() << "\n" \
		<< "Grade to sign:\t\t" << param.getGradeToSign() << "\n" \
		<< "Grade to execute:\t" << param.getGradeToExecute() << "\n" \
		<< "Form Status:\t\t";
	if (param.getIsSigned())
		out << "Signed";
	else
		out << "Not signed";
	return (out);
}

/* ************************************************************************** */ // Exceptions

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

const char*	AForm::FormNotSignedException::what() const throw()
{
	return ("Form not signed!");
}
