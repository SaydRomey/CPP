#include "Form.hpp"

/* ************************************************************************** */ // Constructors / Destructors

Form::Form(void) : _name("Default Form"), \
_grade_to_sign(GRADE_MIN), \
_grade_to_execute(GRADE_MIN)
{
	_is_signed = false;
	std::cout \
		<< GRAYTALIC << "Form '" << _name \
		<< "' [default constructor]" << RESET << std::endl;
}

Form::Form(const std::string name, \
const unsigned int grade_to_sign, \
const unsigned int grade_to_execute) \
: _name(name), \
_grade_to_sign(this->checkGrade(grade_to_sign)), \
_grade_to_execute(this->checkGrade(grade_to_execute))
{
	_is_signed = false;
	std::cout \
		<< GRAYTALIC << "Form '" << _name \
		<< "' [parametrized constructor]" << RESET << std::endl;
}

Form::Form(const Form &other) : _name(other._name), \
_grade_to_sign(other._grade_to_sign), \
_grade_to_execute(other._grade_to_execute)
{
	*this = other;
	std::cout \
		<< GRAYTALIC << "Form '" << _name \
		<< "' [copy constructor]" << RESET << std::endl;
}

Form::~Form(void)
{
	std::cout \
		<< GRAYTALIC << "Form '" << _name \
		<< "' [default destructor]" << RESET << std::endl;
}

/* ************************************************************************** */ // Getters / Setters

const std::string&	Form::getName(void) const
{
	return (_name);
}

bool	Form::getIsSigned(void) const
{
	return (_is_signed);
}

unsigned int	Form::getGradeToSign(void) const
{
	return (_grade_to_sign);
}

unsigned int	Form::getGradeToExecute(void) const
{
	return (_grade_to_execute);
}

/* ************************************************************************** */ // Functions / Methods

unsigned int	Form::checkGrade(unsigned int grade) const
{
	if (grade > GRADE_MIN)
		throw GradeTooLowException();
	if (grade < GRADE_MAX)
		throw GradeTooHighException();
	return (grade);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_grade_to_sign)
	{
		this->_is_signed = true;
	}
	else
		throw GradeTooLowException();
}

/* ************************************************************************** */ // Operators

Form&	Form::operator=(const Form &other)
{
	if (this != &other && this->_is_signed != other._is_signed)
	{
		this->_is_signed = other._is_signed;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream &out, const Form &other)
{
	out \
		<< "Form name:\t\t" << other.getName() << "\n" \
		<< "Grade to sign:\t\t" << other.getGradeToSign() << "\n" \
		<< "Grade to execute:\t" << other.getGradeToExecute() << "\n" \
		<< "Form Status:\t\t";
	if (other.getIsSigned())
		out << "Signed.";
	else
		out << "Not signed.";
	return (out);
}

/* ************************************************************************** */ // Exceptions

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}
