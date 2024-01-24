/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:38:23 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/24 12:33:42 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

# define MAX_IDEAS 100

class Brain
{
	public:

		Brain(void);
		Brain(const Brain &other);
		Brain&	operator=(const Brain &other);
		virtual ~Brain(void);

	private:

		std::string	ideas[MAX_IDEAS];
};

#endif // BRAIN_HPP
