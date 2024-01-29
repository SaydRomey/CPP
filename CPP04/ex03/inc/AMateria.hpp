/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:05:04 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/29 11:40:17 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "Character.hpp"
# include <iostream>

# define RESET		"\033[0m"
# define GREEN		"\033[32m"
# define CYAN		"\033[96m"
# define GRAYTALIC	"\033[3;90m"

class ICharacter;
class IMateriaSource;

/*
base class for different types of materias
*/
class AMateria
{
	public:

		AMateria(void);
		AMateria(const std::string &type);
		AMateria(const AMateria &other);
		AMateria&	operator=(const AMateria &other);
		virtual		~AMateria(void);

		const std::string&	getType(void) const; // returns the materia type

		virtual AMateria*	clone(void) const = 0; // pure virtual
		virtual void		use(ICharacter &target);

	protected:

		std::string _type;
};

#endif // AMATERIA_HPP
