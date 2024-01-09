/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:11:57 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/09 12:41:39 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "Contact.class.hpp"
# include <string>

# ifndef MAX_CONTACT
#  define MAX_CONTACT	8
# endif

# ifndef COLUMN_WIDTH
#  define COLUMN_WIDTH	10
# endif

class	PhoneBook
{
	public:
	
		PhoneBook(void);
		~PhoneBook(void);

		void		addContact(const Contact &newContact);
		void		displayAllContacts(void) const;
		void		displayContact(int index) const;
	
	private:

		Contact		_contacts[MAX_CONTACT];
		int			_currentContactIndex;

		std::string	truncate(const std::string &str) const;
		std::string	rightAlign(const std::string &str) const;
		std::string center(const std::string &str) const;

};


#endif