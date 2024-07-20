/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:24:48 by cdumais           #+#    #+#             */
/*   Updated: 2024/07/20 14:25:34 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Usage: " << argv[0] << " <literal>" << std::endl;
		return (1);
	}
	if (!isValidScalarType(argv[1]))
	{
		std::cout << INVALID_TYPE << std::endl;	
		return (1);
	}
	convert(argv[1]);
	
	return (0);
}

