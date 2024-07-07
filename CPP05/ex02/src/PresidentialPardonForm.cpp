/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 07:25:08 by cdumais           #+#    #+#             */
/*   Updated: 2024/07/06 15:30:24 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/*
PresidentialPardonForm: Required grades: sign 25, exec 5
Informs that <target> has been pardoned by Zaphod Beeblebrox.
*/

/* ************************************************************************** */ // Constructors / Destructors

PresidentialPardonForm::PresidentialPardonForm(void) : AForm()
{
	// 
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) \
: AForm(PARDON_NAME, target, PARDON_SIGN_LVL, PARDON_EXEC_LVL)
{
	// 
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other)
{
	// 
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	// 
}


/* ************************************************************************** */ // Functions / Methods

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (!this->getIsSigned())
		throw (FormNotSignedException());
	else if (executor.getGrade() > this->getGradeToExecute())
		throw (GradeTooLowException());
	else
	{
		std::cout << this->getTarget() << " has been pardoned by " << PRESIDENT_NAME << std::endl;
	}
}

/* ************************************************************************** */ // Operators

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	AForm::operator=(other);
	return (*this);
}
