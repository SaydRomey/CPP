/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:24:37 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/11 20:29:59 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

# define RESET	"\033[0m"
# define ORANGE	"\033[38;5;208m"
# define CYAN	"\033[96m"

# ifndef WEAPON_A
#  define WEAPON_A	ORANGE "crude spiked club" RESET
# endif

# ifndef WEAPON_B
#  define WEAPON_B	CYAN "some other type of club" RESET
# endif

class	Weapon
{
	public:

		Weapon(const std::string type);
		~Weapon(void);
		
		const std::string	&getType(void) const;
		void				setType(std::string newType);

	private:

		std::string	_type;
};

#endif