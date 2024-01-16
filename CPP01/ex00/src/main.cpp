/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:38:42 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/16 11:16:28 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie	*z_heap = (newZombie("heap zombie"));
	z_heap->announce();
	delete z_heap;

	randomChump("stack zombie");

	return (0);
}
