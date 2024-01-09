/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:34:00 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/08 21:03:17 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AwesomePhoneBook.hpp"

void	handleAddCommand(PhoneBook &phoneBook);
void	handleSearchCommand(PhoneBook &phoneBook);

int		main(void)
{
	PhoneBook	phoneBook;
	std::string	command;

	system("clear"); //check to use this when choosing display details
	while (1)
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
		{
			std::cout << "Unknown command." << std::endl;
		}
	}
	return (0);
}

bool	getInput(std::string &input, const std::string &fieldName)
{
	while (true)
	{
		std::cout << "Enter " << fieldName << ": ";
		if (!std::getline(std::cin, input) || std::cin.eof())
		{
			std::cin.clear();
			std::cout << "\nEOF detected. Exiting to main menu." << std::endl; //not on point, exits everything..
			return (false);
		}
		if (!input.empty())
		{
			return (true);
		}
		std::cout << fieldName << " cannot be empty. Please enter again: ";
	}
}

/*
*/
void	handleAddCommand(PhoneBook &phoneBook)
{
	Contact		newContact;
	std::string	input;

	if (!getInput(input, "first name"))
		return;
	newContact.setFirstName(input);

	// std::cout << "Enter first name: ";
	// std::getline(std::cin, input);
	// if (input.empty())
	// {
	// 	std::cout << "Contact must have a name." << std::endl;
	// 	return;
	// }
	// newContact.setFirstName(input);
	// 
	// std::cout << "Enter first name: ";
	// while (std::getline(std::cin, input) && input.empty())
	// {
	// 	if (std::cin.eof())
	// 	{
	// 		std::cin.clear();  // Clear EOF flag
	// 		std::cout << "\nEOF detected. Exiting to main menu." << std::endl;
	// 		return;  // Return to main menu
	// 	}
	// 	std::cout << "First name cannot be empty. Please enter again: ";
	// }
	// newContact.setFirstName(input);
	// 

	//implement the empty field check for the other questions..

	std::cout << "Enter last name: ";
	std::getline(std::cin, input);
	newContact.setLastName(input);

	std::cout << "Enter nickname: ";
	std::getline(std::cin, input);
	newContact.setNickname(input);

	std::cout << "Enter phone number: ";
	std::getline(std::cin, input);
	newContact.setPhoneNumber(input);

	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, input);
	newContact.setDarkestSecret(input);

	phoneBook.addContact(newContact);
}

void	handleSearchCommand(PhoneBook &phoneBook)
{
	phoneBook.displayAllContacts();

	std::string	input;
	std::cout << "Enter the index of the contact to view details: ";
	std::getline(std::cin, input);

	std::istringstream	iss(input);
	int	index;
	
	if (iss >> index)
	{
		if (index >= 0 && index < MAX_CONTACT)
		{
			phoneBook.displayContact(index);
		}
		else
			std::cout << "Invalid index. Please enter a number between 0 and " << MAX_CONTACT - 1 << "." << std::endl;
	}
	else
		std::cout << "Invalid input. Please enter a number." << std::endl;
}
