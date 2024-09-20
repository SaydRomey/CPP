/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:36:05 by cdumais           #+#    #+#             */
/*   Updated: 2024/09/20 15:40:20 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

/*
Returns size of array (deduced at compile time)
*/
template <typename T, size_t N>
size_t	arrayLength(T (&)[N])
{
	// std::cout << "Length = " << N << std::endl;
	return (N);
}

void	intArrayTest(void)
{
	int		intArray[] = {1, 2, 3, 4, 5};
	size_t	intArraySize = arrayLength(intArray);
	// size_t	intArraySize = sizeof(intArray) / sizeof(intArray[0]);

	std::cout << "\nPrinting array of [" << intArraySize << "] integers: ";
	iter(intArray, intArraySize, printElement<int>);
	std::cout << std::endl;

	iter(intArray, intArraySize, addFortyTwo<int>);
	std::cout << "Printing array of [" << intArraySize << "] (+42) modified integers: ";
	iter(intArray, intArraySize, printElement<int>);
	std::cout << std::endl;

	iter(intArray, intArraySize, doubleElement<int>);
	std::cout << "Printing array of [" << intArraySize << "] doubled integers: ";
	iter(intArray, intArraySize, printElement<int>);
	std::cout << std::endl;
}

void	doubleArrayTest(void)
{
	double	doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	size_t	doubleArraySize = arrayLength(doubleArray);

	std::cout << "\nPrinting array of [" << doubleArraySize << "] doubles: ";
	iter(doubleArray, doubleArraySize, printElement<double>);
	std::cout << std::endl;

	iter(doubleArray, doubleArraySize, addFortyTwo<double>);
	std::cout << "Printing array of [" << doubleArraySize << "] (+42) modified doubles: ";
	iter(doubleArray, doubleArraySize, printElement<double>);
	std::cout << std::endl;

	iter(doubleArray, doubleArraySize, doubleElement<double>);
	std::cout << "Printing array of [" << doubleArraySize << "] doubled doubles: ";
	iter(doubleArray, doubleArraySize, printElement<double>);
	std::cout << std::endl;	
}

void	stringArrayTest(void)
{
	std::string	stringArray[] = {"one", "two", "three"};
	size_t	stringArraySize = arrayLength(stringArray);

	std::cout << "\nPrinting array of [" << stringArraySize << "] strings: ";
	iter(stringArray, stringArraySize, printElement<std::string>);
	std::cout << std::endl;

	iter(stringArray, stringArraySize, addFortyTwo<std::string>);
	std::cout << "Printing array of [" << stringArraySize << "] (+42) modified strings: ";
	iter(stringArray, stringArraySize, printElement<std::string>);
	std::cout << std::endl;
	
	iter(stringArray, stringArraySize, doubleElement<std::string>);
	std::cout << "Printing array of [" << stringArraySize << "] doubled strings: ";
	iter(stringArray, stringArraySize, printElement<std::string>);
	std::cout << std::endl;
}

int	main(void)
{
	intArrayTest();
	doubleArrayTest();
	stringArrayTest();
	
	return (0);
}
