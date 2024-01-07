/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 10:52:46 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/07 17:05:02 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"

int	main(void)
{
	Sample		instance;
	Sample *	instanceptr = &instance;

	int			Sample::*p = NULL; //pointer on an int, which is a member of the class 'Sample'
	void		(Sample::*f)(void) const;
	
	p = &Sample::value;

	std::cout << "Value of member 'value': " << instance.value << std::endl;
	instance.*p = 21;
	std::cout << "Value of member 'value': " << instance.value << std::endl;
	instanceptr->*p = 42;
	std::cout << "Value of member 'value': " << instance.value << std::endl;

	f = &Sample::func;

	(instance.*f)();
	(instanceptr->*f)();
	
	return (0);
}
