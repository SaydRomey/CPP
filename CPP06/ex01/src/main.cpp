/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:18:59 by cdumais           #+#    #+#             */
/*   Updated: 2024/07/20 14:24:17 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int	main(void)
{
	// creating a 'Data' object
	Data	originalData(1, "Test", 42.042);
	originalData.display();
	
	// serializing the pointer to 'Data'
	uintptr_t	serialized = serialize(&originalData);
	
	// deserializing and obtaining the pointer to 'Data'
	Data*	deserializedData = deserialize(serialized);

	// displaying the deserialized 'Data'
	deserializedData->display();

	// comparing the original and deserialized pointers
	if (&originalData == deserializedData)
		std::cout << "Same!" << std::endl;
	else
		std::cout << "Different!" << std::endl;

	return (0);
}
