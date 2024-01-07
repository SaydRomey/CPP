/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 10:52:46 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/07 16:28:11 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"

void	f0(void)
{
	Sample	instance;

	std::cout << "Number of instances: " << Sample::getNbInst() << std::endl;

	return;
}

void	f1(void)
{
	Sample	instance;

	std::cout << "Number of instances: " << Sample::getNbInst() << std::endl;
	f0();

	return;
}

int	main(void)
{
	std::cout << "Number of instances: " << Sample::getNbInst() << std::endl;
	f1();
	std::cout << "Number of instances: " << Sample::getNbInst() << std::endl;

	return (0);
}
