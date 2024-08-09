/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:22:39 by cdumais           #+#    #+#             */
/*   Updated: 2024/08/09 12:16:29 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(int id, const std::string &name, double value) \
: id(id), name(name), value(value)
{
	// 
}

void	Data::display(void) const
{
	std::cout << "Data -> " \
	<< "id: " << id << ", "\
	<< "name: " << name << ", "\
	<< "value: " << value << std::endl;
}

uintptr_t	serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
