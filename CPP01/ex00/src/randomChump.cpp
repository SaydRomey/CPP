/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:17:36 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/10 17:21:52 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
It creates a zombie, name it, and the zombie announces itself.
*/
void	randomChump(std::string name)
{
	Zombie	z(name);
	
	z.announce();
}
