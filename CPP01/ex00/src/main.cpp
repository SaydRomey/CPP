/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:38:42 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/10 17:33:49 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
You have to determine in what case it’s better
to allocate the zombies on the stack or heap
*/
int main(void)
{
	Zombie	*z_heap = (newZombie("heap zombie"));
	z_heap->announce();
	delete z_heap;

	randomChump("stack zombie");

	return (0);
}
