/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:33:08 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/23 15:13:32 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

# define DIAMNAME	"D14M0ND-TP"


class DiamondTrap : public FragTrap, public ScavTrap
{
	public:

		DiamondTrap(void);
		DiamondTrap(const std::string name);
		DiamondTrap(const DiamondTrap &src);
		~DiamondTrap(void);

		DiamondTrap&	operator=(const DiamondTrap &rhs);

		void	attack(const std::string &target);
		void	whoAmI(void);

	private:

		std::string	_name;
};

#endif // DIAMONDTRAP_HPP
