/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:38:23 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/24 17:34:08 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

# define MAX_IDEAS 100

class Brain
{
	public:

		Brain(void);
		Brain(const Brain &other);
		Brain&	operator=(const Brain &other);
		virtual ~Brain(void);
		
		void				setIdea(std::string idea, int index);
		const std::string&	getIdea(int index) const;

	private:

		std::string	ideas[MAX_IDEAS];
};

#endif // BRAIN_HPP
