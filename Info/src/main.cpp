/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 10:52:46 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/16 14:27:38 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sample.class.hpp"
#include <iostream>
#include <fstream>

int	main(void)
{
	Sample	sample;

	sample.func('C');
	sample.func(42);
	sample.func(1.01f);
	sample.func(sample);
	
	return (0);
}
