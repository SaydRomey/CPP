/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 22:00:14 by cdumais           #+#    #+#             */
/*   Updated: 2024/08/09 18:21:53 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

/*
It randomly instanciates A, B or C and returns the instance as a Base pointer.
Feel free to use anything you like for the random choice implementation.
*/
Base*	generate(void)
{
	std::srand(static_cast<unsigned int>(std::time(0)));

	int	randomNum = std::rand() % 3;

	switch (randomNum)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
		default:
			return (NULL);
	}
}

/*
It prints the actual type of the object pointed to by p: "A", "B" or "C".
*/
void	identify(Base *p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
	else
		std::cout << "Error: unknown type" << std::endl;
}

/*
It prints the actual type of the object pointed to by p: "A", "B" or "C".
Using a pointer inside this function is forbidden.
*/
void	identify(Base &p)
{
	identify(&p);
}
