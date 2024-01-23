/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:09:56 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/23 15:06:52 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <string>
# include <iostream>

# define SCAVNAME	"SC4V-TP"	// Default Name
# define SCAV_HP	100			// Hit Points
# define SCAV_EP	50			// Energy Points
# define SCAV_AD	20			// Attack Damage
# define SCAV_MSG	"Halt, moon citizen!\n\
I've been chosen to stand out here - far, far away from everyone else -\n\
to guard the main gate to the old communications facility.\n\
It's a VERY important duty,as I'm not to let ANYONE in through here!\n\
Unless, of course, you're here as fresh meat for the recruitment grinder!"


class ScavTrap : public ClapTrap
{
	public:

		ScavTrap(void);
		ScavTrap(const std::string name);
		ScavTrap(const ScavTrap &rhs);
		~ScavTrap(void);

		ScavTrap&	operator=(const ScavTrap &rhs);
	
		void	attack(const std::string &target);
		void	guardGate(void);
};

#endif // SCAVTRAP_HPP
