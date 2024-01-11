/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:38:08 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/11 12:48:23 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <string>

class	HumanA
{
	public:
		HumanA(void);
		HumanA(const std::string name, Weapon& weapon);
		~HumanA(void);

		void	attack(void) const;

	private:
		std::string	_name;
		Weapon&		_weapon;
};
