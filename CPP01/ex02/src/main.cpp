/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:06:00 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/16 13:02:31 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << "Memory adress of the string variable:\t" << stringPTR << std::endl;
	std::cout << "Memory adress held by 'stringPTR':\t" << stringPTR << std::endl;
	std::cout << "Memory adress held by 'stringREF':\t" << &stringREF << std::endl;

	std::cout << "Value of the string variable:\t\t" << str << std::endl;
	std::cout << "Value pointed to by 'stringPTR:\t\t" << *stringPTR << std::endl;
	std::cout << "Value pointed to by 'stringREF':\t" << stringREF << std::endl;

	return (0);
}
