/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:07:14 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/24 20:06:39 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include <iostream>

/*
interface-like abstract class
defines the interface for Materia sources
only contains pure virtual functions
*/
class IMateriaSource
{
	public:

		virtual	~IMateriaSource(void) {}
		virtual void	learnMateria(AMateria*) = 0;
		virtual AMateria*	createMateria(const std::string &type) = 0;
};

/*
concrete class
implements the IMateriaSource interface
manages learning and creating Materias
*/
class MateriaSource : public IMateriaSource
{
	public:

		MateriaSource(void);
		MateriaSource(const MateriaSource &other);
		MateriaSource&	operator=(const MateriaSource &other);
		virtual	~MateriaSource(void);

		virtual void		learnMateria(AMateria*);
		virtual AMateria*	createMateria(const std::string &type);
	
	private:

		AMateria*	_learnedMaterias[4];
};

#endif // MATERIASOURCE_HPP
