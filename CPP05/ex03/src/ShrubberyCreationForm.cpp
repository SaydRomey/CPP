/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 07:25:15 by cdumais           #+#    #+#             */
/*   Updated: 2024/07/06 12:39:41 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/*
ShrubberyCreationForm: Required grades: sign 145, exec 137
Create a file <target>_shrubbery in the working directory,
and writes ASCII trees inside it.
*/

/* ************************************************************************** */ // Constructors / Destructors

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm()
{
	// 
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) \
: AForm(SHRUB_NAME, target, SHRUB_SIGN_LVL, SHRUB_EXEC_LVL)
{
	// 
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
	// 
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	// 
}
/* ************************************************************************** */ // Functions / Methods

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (!this->getIsSigned())
		throw (FormNotSignedException());
	else if (executor.getGrade() > this->getGradeToExecute())
		throw (GradeTooLowException());
	else
	{
		std::string		shrubpath = this->getTarget() + SHRUB_EXT;
		std::ofstream	shrubfile;

		shrubfile.exceptions(std::ofstream::failbit | std::ofstream::badbit); // set exceptions to be thrown on failure
		
		try
		{
			shrubfile.open(shrubpath.c_str(), std::ios::trunc);
			shrubfile << ASCII_TREES << std::endl;
			shrubfile.close();
		}
		catch (const std::ios_base::failure &e)
		{			
			throw (std::ios_base::failure(std::string("Failed to open the output file: ") + strerror(errno)));
		}
	}
}

/* ************************************************************************** */ // Operators

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	AForm::operator=(other);
	return (*this);
}
