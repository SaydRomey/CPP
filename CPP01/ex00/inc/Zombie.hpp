/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:37:01 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/09 20:41:10 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

# ifndef Z_MSG
#  define Z_MSG	": BraiiiiiiinnnzzzZ..."
# endif

class	Zombie
{
	public:

		Zombie(const std::string name);
		~Zombie(void);

		void	announce(void);

	private:
	
		std::string	_name;
		
};

#endif