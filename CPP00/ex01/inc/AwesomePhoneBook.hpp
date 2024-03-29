/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AwesomePhoneBook.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:38:58 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/09 17:45:54 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWESOMEPHONEBOOK_HPP
# define AWESOMEPHONEBOOK_HPP

# include "PhoneBook.class.hpp"
# include "Contact.class.hpp"
# include <iostream>
# include <string>
# include <sstream>
# include <cstdlib>

# ifndef MAX_CONTACT
#  define MAX_CONTACT	8
# endif

# ifndef COLUMN_WIDTH
#  define COLUMN_WIDTH	10
# endif

# define RESET	"\033[0m"
# define GREEN	"\033[32m"
# define ORANGE	"\033[38;5;208m"

#endif