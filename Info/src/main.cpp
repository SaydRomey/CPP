/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 10:52:46 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/11 11:27:33 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	byPtr(std::string* str)
{
	*str += " there";
}

void	byConstPtr(std::string const *str)
{
	std::cout << *str << std::endl;
}

void	byRef(std::string& str)
{
	str += " there";
}

void	byConstRef(std::string const &str)
{
	std::cout << str << std::endl;
}

int	main(void)
{
	std::string	str = "Hello";

	std::cout << str << std::endl;
	byPtr(&str);
	byConstPtr(&str);

	str = "Are you";
	
	std::cout << str << std::endl;
	byRef(str);
	byConstRef(str);

	return (0);
}
