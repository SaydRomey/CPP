/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:22:32 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/22 23:38:55 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <string>
# include <iostream>

# define FRAGNAME	"FR4G-TP"	// Default Name
# define FRAG_HP	100			// Hit Points
# define FRAG_EP	100			// Energy Points
# define FRAG_AD	30			// Attack Damage
// # define FRAG_MSG

class FragTrap : public ClapTrap
{
	public:

		FragTrap(void);
		FragTrap(const std::string name);
		FragTrap(const FragTrap &src);
		~FragTrap(void);

		FragTrap&	operator=(const FragTrap &rhs);

		void	attack(const std::string &target);
		void	highFivesGuys(void);
};

#endif // FRAGTRAP_HPP
