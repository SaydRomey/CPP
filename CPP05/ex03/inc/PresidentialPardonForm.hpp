/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 07:24:45 by cdumais           #+#    #+#             */
/*   Updated: 2024/07/06 12:37:23 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>
# include "AForm.hpp"

# define PARDON_NAME		"Presidential Pardon"
# define PRESIDENT_NAME		"Zaphod Beeblebrox"
# define PARDON_SIGN_LVL	25
# define PARDON_EXEC_LVL	5

class PresidentialPardonForm : public AForm
{
	public:
		// Constructors / Destructors
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		~PresidentialPardonForm(void);

		// Functions / Methods
		void	execute(const Bureaucrat &executor) const;

		// Operators
		PresidentialPardonForm&	operator=(const PresidentialPardonForm &other);
};

#endif // PRESIDENTIALPARDONFORM_HPP
