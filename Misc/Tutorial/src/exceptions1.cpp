/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceptions1.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:20:28 by cdumais           #+#    #+#             */
/*   Updated: 2024/05/09 13:02:46 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	try
	{
		throw 20;
	}
	catch (int e)
	{
		std::cout << "An exception occured. Exception Nbr. " << e << std::endl;
	}
	return (0);
}


/* ************************************************************************** */

// #include "stdexcept"

// void	test1(void)
// {
// 	try
// 	{
// 		// do some stuff here
// 		if (/* there is an error */)
// 		{
// 			throw std::exception();
// 		}
// 		else
// 		{
// 			// do some more stuff
// 		}
// 	}
// 	catch (std::exception e)
// 	{
// 		// handle error here
// 	}
// }

// void	test2(void)
// {
// 	// do some stuff here
// 	try
// 	{
// 		test2();
// 	}
// 	catch (std::exception &e)
// 	{
// 		// handle error
// 	}
// }

// void	test3(void)
// {
// 	try
// 	{
// 		test2();
// 	}
// 	catch (std::exception &e)
// 	{
// 		// handle error
// 	}
// }

// void	test4(void)
// {
// 	class PEBKACException : public std::exception
// 	{
// 		public:
// 			virtual const char *what() const throw()
// 			{
// 				return ("Problem exists between keyboard and chair");
// 			}
// 	};

// 	try
// 	{
// 		test3();
// 	}
// 	catch (PEBKACException &e)
// 	{
// 		// handle the fact that the user is an idiot
// 	}
// 	catch (std::exception &e)
// 	{
// 		// handle other exceptions that are like std::exception
// 	}
// }
