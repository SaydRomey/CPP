/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:11:07 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/08 16:56:36 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <string>

class	Contact
{
	public:

		Contact(void);
		~Contact(void);

		void		setFirstName(const std::string &firstname);
		void		setLastName(const std::string &lastname);
		void		setNickname(const std::string &nickname);
		void		setPhoneNumber(const std::string &phoneNumber);
		void		setDarkestSecret(const std::string &darkestSecret);

		std::string getFirstName(void) const;
		std::string getLastName(void) const;
		std::string getNickname(void) const;
		std::string getPhoneNumber(void) const;
		std::string getDarkestSecret(void) const;

	private:
		
		std::string	_firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;

};


#endif