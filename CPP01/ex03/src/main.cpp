/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:49:04 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/11 20:19:17 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main(void)
{
	std::cout << std::endl;
	{
		Weapon	club = Weapon(WEAPON_A);
		HumanA	bob(NAME_A, club);
		bob.attack();
		club.setType(WEAPON_B);
		bob.attack();
	}
	std::cout << std::endl;
	{
		Weapon	club = Weapon(WEAPON_A);
		HumanB	jim(NAME_B);
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType(WEAPON_B);
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
	}
	return (0);
}
