/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:45:30 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/11 12:47:44 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <string>

class	HumanB
{
	public:
		HumanB(void);
		HumanB(const std::string name);
		~HumanB(void);

		void	attack(void) const;
		void	setWeapon(Weapon& weapon);

	private:
		std::string	_name;
		Weapon*		_weapon;
};
