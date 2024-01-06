/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 10:52:46 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/06 18:03:13 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"

int	main(void)
{
	Sample inst1(42);
	Sample inst2(42);

	if (&inst1 == &inst1)
		std::cout << "inst1 and inst1 are phisically equal" << std::endl;
	else
		std::cout << "inst1 and inst1 are not phisically equal" << std::endl;

	if (&inst1 == &inst2)
		std::cout << "inst1 and inst2 are phisically equal" << std::endl;
	else
		std::cout << "inst1 and inst2 are not phisically equal" << std::endl;


	if (inst1.compare(&inst1) == 0)
		std::cout << "inst1 and inst1 are structurally equal" << std::endl;
	else
		std::cout << "inst1 and inst1 are not structurally equal" << std::endl;
	
	if (inst1.compare(&inst2) == 0)
		std::cout << "inst1 and inst2 are structurally equal" << std::endl;
	else
		std::cout << "inst1 and inst2 are not structurally equal" << std::endl;

	return (0);
}
