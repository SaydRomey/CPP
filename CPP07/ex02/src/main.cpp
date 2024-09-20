/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:38:21 by cdumais           #+#    #+#             */
/*   Updated: 2024/09/20 17:22:47 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#define RESET		"\033[0m"
#define RED			"\033[91m"
#define GREEN		"\033[32m"
#define YELLOW		"\033[33m"
#define PURPLE		"\033[95m"
#define ORANGE		"\033[38;5;208m"
#define GRAYTALIC	"\033[3;90m"

void	print(std::string str, std::string color = GRAYTALIC)
{
	std::cout << color << str << RESET << std::endl;
}

template <typename T>
void	printArray(const Array<T> &data, const std::string str)
{
	unsigned int	i = 0;

	std::cout << str << "[ ";
	while (i < data.size())
	{
		std::cout << data[i];
		if (i + 1 != data.size())
			std::cout << ", ";
		i++;
	}
	std::cout << " ]" << std::endl;
}

/*
"Tip: Try to compile int * a = new int(); then display *a."
*/
void	pdfTest(void)
{
	int	*a = new int();

	std::cout << "Default value when using 'new': " << *a << std::endl;
	
	delete a;
}

int	main(void)
{
	pdfTest();
	
	print("\nTesting default constructor");
	Array<int>	intArrayDefault;
	std::cout << "Default Array size: " << intArrayDefault.size() << std::endl;
	printArray(intArrayDefault, "Default Array values: ");

	print("\nTesting parametrized constructor");
	Array<double>	doubleArray(5);
	printArray(doubleArray, "Double Array default values: ");

	print("\nFilling double Array");
	unsigned int	i = 0;
	while (i < doubleArray.size())
	{
		doubleArray[i] = i * 1.5;
		i++;
	}
	printArray(doubleArray, "Double Array elements: ");

	print("\nTesting copy constructor and assignment operator");
	Array<double>	doubleArrayCopy(doubleArray);
	printArray(doubleArrayCopy, "Copy of double Array elements: ");

	print("\nModifying original Array and checking copy");
	doubleArray[0] = 99.9;
	printArray(doubleArray, "Double Array after modification: ");
	printArray(doubleArrayCopy, "Copy of double Array after modification: ");

	print("\nException handling - Index out of bounds");
	try
	{
		print("Accessing out of bounds index: ", YELLOW);
		std::cout << doubleArray[doubleArray.size() + 42] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	return (0);
}
