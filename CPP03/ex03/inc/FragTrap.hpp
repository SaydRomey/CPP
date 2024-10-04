/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:22:32 by cdumais           #+#    #+#             */
/*   Updated: 2024/10/04 17:55:15 by cdumais          ###   ########.fr       */
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
# define FRAG_MSG	"High Five! Up Top!! \n\
* recieves a high five *\n\
WE'RE BEST FRIENDS !!!"


class FragTrap : virtual public ClapTrap
{
	public:

		FragTrap(void);
		FragTrap(const std::string name);
		FragTrap(const FragTrap &src);
		~FragTrap(void);

		FragTrap&	operator=(const FragTrap &rhs);

		void	attack(const std::string &target);
		void	highFivesGuys(void);

	protected:

		static int	_fragHP;
		static int	_fragAD;
};

#endif // FRAGTRAP_HPP
