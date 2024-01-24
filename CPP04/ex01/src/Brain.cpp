/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:40:02 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/24 17:48:41 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
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

/* ************************************************************************** */

void	Brain::setIdea(std::string idea, int index)
{
	// check if already an idea?
	this->ideas[index] = idea;
	std::cout << "Idea number " << index << " set" << std::endl;
}

const std::string&	Brain::getIdea(int index) const
{
	return (this->ideas[index]);
}
