/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:40:02 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/24 12:36:26 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	// initialize ideas ?
	std::cout << "Brain default constructor" << std::endl;
}

Brain::Brain(const Brain &other)
{
	*this = other;
	std::cout << "Brain copy constructor" << std::endl;
}

Brain&	Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		// std::memcpy(ideas, other.ideas, 100 * sizeof(std::string)); //?
		int	i = 0;
		while (i < MAX_IDEAS)
		{
			this->ideas[i] = other.ideas[i];
			i++;
		}
		std::cout << "Brain copied content from " \
		<< &other << " to " << this << std::endl;
	}
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor" << std::endl;
}
