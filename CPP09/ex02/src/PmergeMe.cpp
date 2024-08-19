/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:56:04 by cdumais           #+#    #+#             */
/*   Updated: 2024/08/18 20:56:05 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* ************************************************************************** */ // Constructors / Destructors

PmergeMe::PmergeMe(void)
{
	std::cout << GRAYTALIC << "PmergeMe [default constructor]" << RESET << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
	std::cout << GRAYTALIC << "PmergeMe [copy constructor]" << RESET << std::endl;
}

PmergeMe::~PmergeMe(void)
{
	std::cout << GRAYTALIC << "PmergeMe [default destructor]" << RESET << std::endl;
}

/* ************************************************************************** */ // Getters / Setters

/* ************************************************************************** */ // Functions / Methods

/* ************************************************************************** */ // Operators

PmergeMe&	PmergeMe::operator=(const PmergeMe &other)
{
	// if (this != &other)
	// {}
	
	return (*this);
}

// std::ostream&	operator<<(std::ostream &out, const PmergeMe &param)

/* ************************************************************************** */ // Exceptions

