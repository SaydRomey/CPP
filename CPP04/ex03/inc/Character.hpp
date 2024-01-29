/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:06:23 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/29 13:12:57 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include <iostream>

# define RESET		"\033[0m"
# define GRAYTALIC	"\033[3;90m"

class AMateria;

/*
utility structure for linked list
used to manage unequiped ("floor") Materias
shared amongst all 'Character' instances
** first deleted 'Character' will delete this list' *
*/
struct MateriaNode;

/*
interface-like abstract class
defines the interface for character classes
*/
class ICharacter
{
	public:

		virtual	~ICharacter(void) {}

		virtual const std::string&	getName(void) const = 0;

		virtual void	equip(AMateria *m) = 0;
		virtual void	unequip(int idx) = 0;
		virtual void	use(int idx, ICharacter &target) = 0;
};

/*
concrete class
implements the ICharacter interface
manages Materias (equip, unequip, use) and has an inventory
*/
class Character : public ICharacter
{
	public:

		Character(void);
		Character(const std::string &name);
		Character(const Character &other);
		Character&	operator=(const Character &other);
		virtual ~Character(void);

		virtual const std::string&	getName(void) const;
		
		virtual void	equip(AMateria* m);
		virtual void	unequip(int idx);
		virtual void	use(int idx, ICharacter &target);

		static void		clearFloorMaterias(void); // to clear unequiped Materias
	
	private:

		std::string			_name;
		AMateria*			_inventory[4];
		static MateriaNode*	_floorMateriaHead;
};

#endif // CHARACTER_HPP
