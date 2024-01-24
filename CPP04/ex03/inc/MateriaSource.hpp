/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:07:14 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/24 15:22:41 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>

class MateriaSource
{
	public:

		MateriaSource(void);
		MateriaSource(const MateriaSource &other);
		MateriaSource&	operator=(const MateriaSource &other);
		~MateriaSource(void);
};

#endif // MATERIASOURCE_HPP

/*
#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
    // ... details ...
};

#endif
*/
/*
#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private:
    AMateria* templates[4];

public:
    MateriaSource();
    MateriaSource(const MateriaSource &src);
    MateriaSource& operator=(const MateriaSource &rhs);
    virtual ~MateriaSource();

    virtual void learnMateria(AMateria*);
    virtual AMateria* createMateria(std::string const & type);
};

#endif
*/
/*
#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private:
    AMateria* learnedMaterias[4];

public:
    MateriaSource();
    MateriaSource(const MateriaSource &source);
    MateriaSource &operator=(const MateriaSource &source);
    virtual ~MateriaSource();

    virtual void learnMateria(AMateria*);
    virtual AMateria* createMateria(std::string const & type);
};

#endif
*/