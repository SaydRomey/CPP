/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:42:28 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/10 17:22:15 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
It creates a zombie, name it,
and return it so you can use it outside of the function scope.
*/
Zombie *newZombie(std::string name)
{
	Zombie	*z = new Zombie(name);
	
	return (z);	
}
