/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:42:20 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/03 16:47:40 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Exercise : 00
Megaphone
Turn-in directory : ex00/
Files to turn in : Makefile, megaphone.cpp
Forbidden functions : None

Just to make sure that everybody is awake,
	write a program that behaves as follows:

$>./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
$>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
$>./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
$>

Solve the exercises in a C++ manner.
*/

#include <iostream>

int	empty_arg(int ret_value)
{
	std::string	empty_arg = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << empty_arg << std::endl;
	return (ret_value);
}

void	capitalize(std::string &str)
{
	int	i = 0;
	int	length = str.length();

	while (i < length)
	{
		str[i] = toupper(str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int			i;
	std::string	arg;

	if (argc != 1)
	{
		i = 1;
		while (i < argc)
		{
			arg = argv[i];
			if (arg.empty())
				return (arg.clear(), 0);
			capitalize(arg);
			std::cout << arg;
			arg.clear();
			i++;
		}
		std::cout << std::endl;
		return (0);	
	}
	return (empty_arg(0));
}
