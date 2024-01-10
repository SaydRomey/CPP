/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:42:20 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/09 13:40:17 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			// if (arg.empty())
			// 	return (arg.clear(), 0);
			capitalize(arg);
			std::cout << arg;
			// arg.clear();
			i++;
		}
		std::cout << std::endl;
		return (0);	
	}
	return (empty_arg(0));
}
