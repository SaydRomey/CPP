/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 07:23:42 by cdumais           #+#    #+#             */
/*   Updated: 2024/07/06 12:28:14 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <cerrno>
# include <cstring>
# include <fstream>
# include <string>

# include "AForm.hpp"

# define SHRUB_NAME		"Shrubbery Creation"
# define SHRUB_EXT		"_shrubbery"
# define SHRUB_SIGN_LVL	145
# define SHRUB_EXEC_LVL	137

# define ASCII_TREES "\
                         a@@@@a\n\
                     a@@@@@@@@@@@@a\n\
                   a@@@@@@@@@@@@@@@@a\n\
       _-_      a@@@@@@@@@@@@@@@@@@@@a\n\
    /~~   ~~\\    @@@@@@@@@@@@@@@@@@@@@@\n\
 /~~         ~~\\  `@@@@@@`\\\\//'@@@@@@'\n\
{               }          ||\n\
 \\  _-     -_  /           ||\n\
  ~~  \\\\ //  ~~            ||\n\
       | |                 ||\n\
       | |                 ||\n\
      // \\\\               /^^\\\n\
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"


class ShrubberyCreationForm : public AForm
{
	public:
		// Constructors / Destructors
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm(void);

		// Functions / Methods
		void	execute(const Bureaucrat &executor) const;

		// Operators
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm &other);
};

#endif // SHRUBBERYCREATIONFORM_HPP
