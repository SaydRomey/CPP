/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 07:25:11 by cdumais           #+#    #+#             */
/*   Updated: 2024/07/06 13:27:19 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/*
RobotomyRequestForm: Required grades: sign 72, exec 45
Makes some drilling noises.
Then, informs that <target> has been robotomized successfully 50% of the time.
Otherwise, informs that the robotomy failed.
*/

/* ************************************************************************** */ // Constructors / Destructors

RobotomyRequestForm::RobotomyRequestForm(void) : AForm()
{
	// 
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) \
: AForm(ROBOTOMY_NAME, target, ROBOTOMY_SIGN_LVL, ROBOTOMY_EXEC_LVL)
{
	// 
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
	// 
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	// 
}

/* ************************************************************************** */ // Functions / Methods

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	// [...]
	(void)executor; //tmp
}

/* ************************************************************************** */ // Operators

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	AForm::operator=(other);
	return (*this);
}
