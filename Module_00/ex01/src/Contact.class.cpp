/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:28:52 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/08 17:55:26 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"
#include <iostream> //tmp for the cout in constructor and destructor

Contact::Contact(void)
{
	// std::cout << "Contact constructor called" << std::endl;
	return ;
}

Contact::~Contact(void)
{
	// std::cout << "Contact destructor called" << std::endl;
	return ;
}

void Contact::setFirstName(const std::string &firstname)
{
	_firstName = firstname;
}

void Contact::setLastName(const std::string &lastname)
{
	_lastName = lastname;
}

void Contact::setNickname(const std::string &nickname)
{
	_nickname = nickname;
}

void Contact::setPhoneNumber(const std::string &phoneNumber)
{
	_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string &darkestSecret)
{
	_darkestSecret = darkestSecret;
}

std::string Contact::getFirstName(void) const
{
	return (_firstName);
}

std::string Contact::getLastName(void) const
{
	return (_lastName);
}

std::string Contact::getNickname(void) const
{
	return (_nickname);
}

std::string Contact::getPhoneNumber(void) const
{
	return (_phoneNumber);
}

std::string Contact::getDarkestSecret(void) const
{
	return (_darkestSecret);
}
