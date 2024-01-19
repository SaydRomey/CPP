/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:51:06 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/18 20:42:26 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

# define RESET	"\033[0m"
# define GREEN	"\033[32m"
# define ORANGE	"\033[38;5;208m"

# define CLAPNAME	"CL4P-TP"
# define CLAP_HP	10	// Hit Points
# define CLAP_EP	10	// Energy Points
# define CLAP_AD	0	// Attack Damage

class ClapTrap
{
	public:
		ClapTrap(void);
		ClapTrap(const std::string name);
		ClapTrap(const ClapTrap &src);
		~ClapTrap(void);

		ClapTrap&	operator=(const ClapTrap &rhs);
	
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		const std::string	&getName(void) const;
		const int			&getHitPoints(void) const;
		const int			&getEnergyPoints(void) const;
		const int			&getAttackDamage(void) const;

		bool	isAble(void);
		void	isNotAble(void);
		void	printStats(void);

	private:
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;

		
};

#endif // CLAPTRAP_HPP
