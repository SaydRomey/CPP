/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 20:47:09 by cdumais           #+#    #+#             */
/*   Updated: 2024/07/07 20:53:23 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/* ************************************************************************** */ // Constructors / Destructors

Intern::Intern(void)
{
	// std::cout << "Intern default constructor" << std::endl;
}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern::~Intern(void)
{
	std::cout << "Intern default destructor" << std::endl;
}

/* ************************************************************************** */ // Getters / Setters
/* ************************************************************************** */ // Functions / Methods
/* ************************************************************************** */ // Operators

Intern&	Intern::operator=(const Intern &other)
{
	// if (this != &other)
	return (*this);
}

/* ************************************************************************** */ // Exceptions

const char*	Intern::FormNotFoundException::what() const throw()
{
	return ("Form not found")
}