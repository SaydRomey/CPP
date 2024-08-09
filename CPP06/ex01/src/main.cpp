/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:18:59 by cdumais           #+#    #+#             */
/*   Updated: 2024/08/09 17:51:41 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

void	print(const std::string str, std::string color=GRAYTALIC)
{
	std::cout << color << "\n" << str << RESET << std::endl;
}

/*
You must create a non-empty (it means it has data members) Data structure.
Use serialize() on the address of the Data object
and pass its return value to deserialize().
Then, ensure the return value of deserialize() compares equal to the original pointer.
*/
int	main(void)
{
	print("Creating a non-empty 'Data' structure.");
	Data	originalData(1, "Original", 42.042);

	print("Displaying data member of the 'Data' structure.");
	originalData.display();

	print("Using 'serialize()' on the adress of 'Data' object.");
	uintptr_t	serialized = serialize(&originalData);
	
	print("Passing the return value of 'serialize()' to 'deserialize()'.");
	Data*	deserializedData = deserialize(serialized);

	print("Displaying the deserialized 'Data' structure.");
	deserializedData->display();

	print("Comparing the original 'Data' pointer with the deserialized 'Data' pointer.");
	if (&originalData == deserializedData)
		std::cout << GREEN << "Same!" << RESET << std::endl;
	else
		std::cout << RED << "Different!" << RESET << std::endl;

	return (0);
}
