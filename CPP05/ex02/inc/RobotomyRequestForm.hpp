/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 07:24:48 by cdumais           #+#    #+#             */
/*   Updated: 2024/07/06 13:22:10 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <cstdlib>
# include <string>
# include "AForm.hpp"

# define ROBOTOMY_NAME		"Robotomy Request"
# define ROBOTOMY_SIGN_LVL	72
# define ROBOTOMY_EXEC_LVL	45

class RobotomyRequestForm : public AForm
{
	public:
		// Constructors / Destructors
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		~RobotomyRequestForm(void);

		// Functions / Methods
		void	execute(const Bureaucrat &executor) const;

		// Operators
		RobotomyRequestForm&	operator=(const RobotomyRequestForm &other);
};

#endif // ROBOTOMYREQUESTFORM_HPP
