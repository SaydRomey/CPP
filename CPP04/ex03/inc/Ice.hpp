/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:05:33 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/24 19:46:22 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "MateriaSource.hpp"
# include "Character.hpp"
# include <iostream>

class Ice : public AMateria
{
	public:

		Ice(void);
		Ice(const Ice &other);
		Ice&	operator=(const Ice &other);
		~Ice(void);

		AMateria*	clone(void) const;
		void		use(ICharacter &target);
};

#endif // ICE_HPP
