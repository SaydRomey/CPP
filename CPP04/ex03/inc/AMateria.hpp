/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:05:04 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/24 20:04:22 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "Character.hpp"
# include <iostream>

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
