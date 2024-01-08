/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:11:57 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/08 15:17:31 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include "Contact.class.hpp"
#include <string>

#define MAX_CONTACT	8
#define COLUMN_WIDTH 10

class	PhoneBook
{
	public:
	
		PhoneBook(void);
		~PhoneBook(void);

		void		addContact(const Contact &newContact); //method to add a contact
		void		displayAllContacts(void) const; //method to display all contacts
		void		displayContact(int index) const; //method to display a specific contact
	
	private:

		Contact		_contacts[MAX_CONTACT]; //array of 8 Contact objects
		int			_currentContactIndex; //to keep track of the next index to overwrite

		std::string	truncate(const std::string &str) const;
		std::string	rightAlign(const std::string &str) const;
		std::string center(const std::string &str) const;

};


#endif