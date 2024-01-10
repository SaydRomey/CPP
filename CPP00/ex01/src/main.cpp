/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:34:00 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/10 16:17:23 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AwesomePhoneBook.hpp"

void	clearAndStr(std::string str);
void	getInput(std::string &input, const std::string &fieldName);
void	handleAddCommand(PhoneBook &phoneBook);
void	handleSearchCommand(PhoneBook &phoneBook);

int		main(void)
{
	PhoneBook	phoneBook;
	std::string	command;

	clearAndStr("MY AWESOME PHONEBOOK\n");
	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);

		if (command == "EXIT" || std::cin.eof())
			break;
		else if (command == "ADD")
		{
			handleAddCommand(phoneBook);
		}
		else if (command == "SEARCH")
		{
			handleSearchCommand(phoneBook);
		}
		else
			clearAndStr("MY AWESOME PHONEBOOK\n");
	}
	clearAndStr("Exiting");
	return (0);
}

void	getInput(std::string &input, const std::string &fieldName)
{
	clearAndStr("NEW CONTACT\n");
	while (true)
	{
		std::cout << "Enter " << fieldName << ": ";
		if (!std::getline(std::cin, input) || std::cin.eof())
		{
			clearAndStr("Exiting");
			exit(0);
		}
		if (!input.empty())
			return;
		clearAndStr("NEW CONTACT");
		std::cout << ORANGE << "Contact's " << fieldName;
		std::cout << " cannot be empty." << RESET << std::endl;
	}
}

void	handleAddCommand(PhoneBook &phoneBook)
{
	Contact		newContact;
	std::string	input;

	getInput(input, "first name");
	newContact.setFirstName(input);

	getInput(input, "last name");
	newContact.setLastName(input);

	getInput(input, "nickname");
	newContact.setNickname(input);

	getInput(input, "phone number");
	newContact.setPhoneNumber(input);

	getInput(input, "darkest secret");
	newContact.setDarkestSecret(input);

	phoneBook.addContact(newContact);
	clearAndStr("MY AWESOME PHONEBOOK");
	std::cout << GREEN << "Contact saved";
	std::cout << RESET << std::endl;
}

void	handleSearchCommand(PhoneBook &phoneBook)
{
	clearAndStr("CONTACT LIST\n");
	phoneBook.displayAllContacts();

	std::string	input;
	std::cout << "Enter the index of the contact to view details: ";
	std::getline(std::cin, input);

	std::istringstream	indexInput(input);
	int	index;
	
	if (indexInput >> index)
	{
		if (index >= 0 && index < MAX_CONTACT)
		{
			clearAndStr("CONTACT INFO\n");
			phoneBook.displayContact(index);
		}
		else
		{
			clearAndStr("MY AWESOME PHONEBOOK");
			std::cout << ORANGE << "Invalid index. ";
			std::cout << "Please enter a number between ";
			std::cout << "0 and " << MAX_CONTACT - 1 << RESET << std::endl;
		}
	}
	else
	{
		clearAndStr("MY AWESOME PHONEBOOK");
		std::cout << ORANGE << "Invalid input";
		std::cout << RESET << std::endl;
	}
}

void	clearAndStr(std::string str)
{
	system("clear");
	std::cout << str << std::endl;
	return;
}
