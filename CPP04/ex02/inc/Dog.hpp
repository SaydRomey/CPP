/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:09:20 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/24 13:09:30 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"
# include <iostream>

class Dog : public AAnimal
{
	public:

		Dog(void);
		Dog(const Dog &other);
		Dog&	operator=(const Dog &other);
		virtual ~Dog(void);

		void	makeSound(void) const;

		private:

			Brain*	_brain;
};

#endif // DOG_HPP
