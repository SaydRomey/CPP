/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 07:25:11 by cdumais           #+#    #+#             */
/*   Updated: 2024/07/09 12:50:53 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/*
RobotomyRequestForm: Required grades: sign 72, exec 45
Makes some drilling noises.
Then, informs that <target> has been robotomized successfully 50% of the time.
Otherwise, informs that the robotomy failed.
*/

/* ************************************************************************** */ // Static random seeding

bool	RobotomyRequestForm::_is_seeded = RobotomyRequestForm::_seedRandom();

bool	RobotomyRequestForm::_seedRandom(void)
{
	std::srand(std::time(0));
	
	return (true);
}

/* ************************************************************************** */ // Constructors / Destructors

RobotomyRequestForm::RobotomyRequestForm(void) \
: AForm()
{
	// 
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) \
: AForm(ROBOTOMY_NAME, target, ROBOTOMY_SIGN_LVL, ROBOTOMY_EXEC_LVL)
{
	// 
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) \
: AForm(other)
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
	if (!this->getIsSigned())
		throw (FormNotSignedException());
	else if (executor.getGrade() > this->getGradeToExecute())
		throw (GradeTooLowException());
	else
	{
		std::cout << "* Making some drilling noises *" << std::endl;
		if (std::rand() % 2)
			std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
		else
			std::cout << "The robotomy of " << this->getTarget() << " failed." << std::endl;
	}
}

/* ************************************************************************** */ // Operators

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	AForm::operator=(other);
	return (*this);
}
