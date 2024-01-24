/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:11:43 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/24 16:58:18 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	public:

		Animal(void);
		Animal(const Animal &other);
		Animal&	operator=(const Animal &other);
		virtual	~Animal(void);

		virtual void	makeSound(void) const;
		std::string		getType(void) const;

	protected:

		std::string	_type;
};

#endif // ANIMAL_HPP
