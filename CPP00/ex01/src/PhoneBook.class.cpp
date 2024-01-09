/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:49:42 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/08 17:57:56 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"
#include <iostream>
#include <iomanip> //for std::setw and std::right //?
#include <string>
#include <sstream>

PhoneBook::PhoneBook(void) : _currentContactIndex(0)
{
	// std::cout << "PhoneBook constructor called" << std::endl;
	return;
}

PhoneBook::~PhoneBook(void)
{
	// std::cout << "PhoneBook destructor called" << std::endl;
	return;
}

void	PhoneBook::addContact(const Contact &newContact)
{
	_contacts[_currentContactIndex] = newContact;
	_currentContactIndex = (_currentContactIndex + 1) % MAX_CONTACT;
}

/*
displays column headers centered
then formats and displays contact details
*/
void	PhoneBook::displayAllContacts(void) const
{
	std::cout << center("Index") << "|";
	std::cout << center("First name") << "|";
	std::cout << center("Last name") << "|";
	std::cout << center("Nickname") << "|" << std::endl; //do we want the last "|" ?

	int	i = 0;
	while (i < MAX_CONTACT)
	{
		std::ostringstream	oss;
		oss << i;
		std::string	indexStr = oss.str();
		
		std::cout << rightAlign(indexStr) << "|";
		std::cout << truncate(_contacts[i].getFirstName()) << "|";
		std::cout << truncate(_contacts[i].getLastName()) << "|";
		std::cout << truncate(_contacts[i].getNickname()) << "|" << std::endl;
		++i;
	}
}

void	PhoneBook::displayContact(int index) const
{
	if (index < 0 || index >= MAX_CONTACT)
	{
		std::cout << "Invalid index" << std::endl;
		return;
	}
	const Contact	&contact = _contacts[index];
	std::cout << "First Name: " << contact.getFirstName() << std::endl;
	std::cout << "Last Name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickname() << std::endl;
	std::cout << "Phone Number: " <<contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " <<contact.getDarkestSecret() <<std::endl;
}

/*
truncates 'str' to replace section exceding defined width with a dot
*/
std::string	PhoneBook::truncate(const std::string &str) const
{
	const size_t	maxLength = COLUMN_WIDTH;
	std::string		truncatedStr = str;
	
	if (truncatedStr.length() > maxLength)
		truncatedStr = truncatedStr.substr(0, maxLength - 1) + ".";
	return (rightAlign(truncatedStr));
}
// {
// 	const size_t	maxLength = COLUMN_WIDTH;

// 	if (str.length() > maxLength)
// 		return (str.substr(0, maxLength - 1) + ".");
// 	return (str + std::string(maxLength - str.length(), ' '));
// }

/*
adds a string of ' ' before 'str' to right align 'str

** need to check if using std::setw and std::right does the trick... *
*/
std::string	PhoneBook::rightAlign(const std::string &str) const
{
	const size_t	width = COLUMN_WIDTH;
	size_t			strLength = str.length();

	if (strLength >= width)
		return (str.substr(0, width));

	size_t	paddingLength = width - strLength;
	std::string		paddingStr(paddingLength, ' ');
	return (paddingStr + str);
}

/*
centers 'str' within a specified 'width' (could be param, but is now a variable instead)
*/
std::string PhoneBook::center(const std::string &str) const
{
	const int	width = COLUMN_WIDTH;
	size_t		strLength = str.length();

	if (strLength >= width)
		return (str.substr(0, width));

	size_t		totalPadding = width - strLength;
	size_t		padding = totalPadding / 2;
	size_t		paddingExtra = totalPadding - padding;

	std::string	paddingStr(padding, ' ');
	std::string	paddingExtraStr(paddingExtra, ' ');

	return (paddingStr + str + paddingExtraStr);
}


//

/*
handles truncation of strings with more than 'width' characters
then right-aligns 'str' by adding a padding string before 'str'
*/
// std::string	PhoneBook::formatField(const std::string &str, int width) const
// {
// 	std::string	truncated;

// 	if (str.length() > width)
// 		truncated = str.substr(0, width - 1) + ".";
// 	else
// 		truncated = str;
	
// 	int	paddingLength = std::max(0, width - static_cast<int>(truncated.length()));
// 	std::string	padding(paddingLength, ' ');
// 	return (padding + truncated);
// }

