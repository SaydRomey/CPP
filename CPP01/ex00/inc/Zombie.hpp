/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:37:01 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/10 17:31:14 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

# ifndef Z_MSG
#  define Z_MSG	": BraiiiiiiinnnzzzZ..."
# endif

# define RESET	"\033[0m"
# define GREEN	"\033[32m"
# define ORANGE	"\033[38;5;208m"

class	Zombie
{
	public:

		Zombie(const std::string name);
		~Zombie(void);

		void	announce(void);

	private:
	
		std::string	_name;
		
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
