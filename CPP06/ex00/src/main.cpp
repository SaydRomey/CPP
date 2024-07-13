/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:25:14 by cdumais           #+#    #+#             */
/*   Updated: 2024/07/12 19:59:25 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

using std::cout;
using std::endl;
using std::string;

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		cout << "Usage: " << argv[0] << " <literal>" << endl;
		return (1);
	}

	Converter scalar(argv[1]);
	scalar.convert();

	return (0);
}
