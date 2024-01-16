/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 23:31:52 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/16 12:02:43 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main(int argc, char *argv[])
{
	Harl	harl;

	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <LEVEL>" << std::endl;
		std::cerr << "Level choice ->" << " DEBUG" << " INFO" << " WARNING" << " ERROR" << std::endl;
		return (1);
	}
	
	harl.complain(argv[1]);
	
	return (0);
}
