/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:06:23 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/24 15:16:40 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>

class Character
{
	public:

		Character(void);
		Character(const Character &other);
		Character&	operator=(const Character &other);
		~Character(void);
};

#endif // CHARACTER_HPP

/*
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {
    // ... details ...
};

#endif
*/
/*
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {
private:
    std::string name;
    AMateria* inventory[4];

public:
    Character(const std::string &name);
    Character(const Character &src);
    Character& operator=(const Character &rhs);
    virtual ~Character();

    virtual std::string const & getName() const;
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);
};

#endif
*/

/*	using fixed size array for floorMateria.. (probably will not use this)

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {
private:
    std::string name;
    AMateria* inventory[4];
    static const int maxFloorMaterias = 10; // Arbitrary limit
    static AMateria* floorMaterias[maxFloorMaterias];
    static int floorMateriaCount;

public:
    Character(const std::string &name);
    Character(const Character &src);
    Character& operator=(const Character &rhs);
    virtual ~Character();

    virtual std::string const & getName() const;
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);

    static void clearFloorMaterias(); // Clear "floor" Materias
};

#endif
*/

/*	Using a linked list for floorMateria

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

struct MateriaNode; // Forward declaration

class Character : public ICharacter {
private:
    std::string name;
    AMateria* inventory[4];
    static MateriaNode* floorMateriaHead;

public:
    Character(const std::string &name);
    Character(const Character &src);
    Character& operator=(const Character &rhs);
    virtual ~Character();

    virtual std::string const & getName() const;
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);

    static void clearFloorMaterias(); // Clear "floor" Materias
};

#endif
*/

/* Updated version

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {
private:
    std::string name;
    AMateria* inventory[4];
    static MateriaNode* floorMateriaHead;

public:
    Character(const std::string &name);
    Character(const Character &src);
    Character& operator=(const Character &rhs);
    virtual ~Character();

    virtual std::string const & getName() const;
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);

    static void clearFloorMaterias(); // Method to clear "floor" Materias
};

#endif
*/