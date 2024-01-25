/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:09:52 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/24 19:45:15 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "MateriaSource.hpp"
# include "Character.hpp"
# include <iostream>

class Cure : public AMateria
{
	public:

		Cure(void);
		Cure(const Cure &other);
		Cure&	operator=(const Cure &other);
		~Cure(void);

		AMateria*	clone(void) const;
		void		use(ICharacter &target);
};

#endif // CURE_HPP
