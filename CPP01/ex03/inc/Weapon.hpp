/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:24:37 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/11 12:37:08 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class	Weapon
{
	public:
		Weapon(void);
		Weapon(const std::string type);
		~Weapon(void);
		
		const std::string	&getType(void) const;
		void				setType(std::string newType);

	private:
		std::string	_type;
};

#endif