/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:40:48 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/16 11:27:30 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

# ifndef Z_MSG
#  define Z_MSG ": BraiiiiiiinnnzzzZ..."
# endif

# ifndef HORDE_SIZE
#  define HORDE_SIZE 10
# endif

# ifndef HORDE_NAME
#  define HORDE_NAME "Walkers"
# endif

# define RESET	"\033[0m"
# define GREEN	"\033[32m"
# define ORANGE	"\033[38;5;208m"

class	Zombie
{
	public:

		Zombie(void);
		Zombie(const std::string name);
		~Zombie(void);
	
		void	announce(void) const;
		void	setName(const std::string name);

	private:

		std::string	_name;

};

Zombie	*zombieHorde(int n, std::string name);

#endif