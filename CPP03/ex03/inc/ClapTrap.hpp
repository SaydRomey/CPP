/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:51:06 by cdumais           #+#    #+#             */
/*   Updated: 2024/10/04 18:38:56 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

# define RESET		"\033[0m"
# define BOLD		"\033[1m"
# define ITALIC		"\033[3m"
# define UNDERLINE	"\033[4m"
# define RED		"\033[91m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[93m"
# define ORANGE		"\033[38;5;208m"
# define BLUE		"\033[94m"
# define PURPLE		"\033[95m"
# define CYAN		"\033[96m"
# define GRAY		"\033[90m"

# define CLAPNAME	"CL4P-TP"	// Default Name
# define CLAP_HP	10			// Hit Points
# define CLAP_EP	10			// Energy Points
# define CLAP_AD	0			// Attack Damage


class ClapTrap
{
	public:

		ClapTrap(void);
		ClapTrap(const std::string name);
		ClapTrap(const ClapTrap &src);
		virtual		~ClapTrap(void);

		ClapTrap&	operator=(const ClapTrap &rhs);
	
		void			attack(const std::string &target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
	
		const std::string	&getName(void) const;
		const int			&getHitPoints(void) const;
		const int			&getEnergyPoints(void) const;
		const int			&getAttackDamage(void) const;

	protected:

		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;

		bool		isAble(void) const;
		void		isNotAble(std::string str = " to continue") const;

};

#endif // CLAPTRAP_HPP
