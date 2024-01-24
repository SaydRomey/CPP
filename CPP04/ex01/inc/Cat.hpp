/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:09:47 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/24 17:31:57 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>

class Cat : public Animal
{
	public:

		Cat(void);
		Cat(const Cat &other);
		Cat&	operator=(const Cat &other);
		virtual ~Cat(void);

		void				setIdea(std::string idea, int index);
		const std::string&	getIdea(int index) const;

		void	makeSound(void) const;

		private:

			Brain*	_brain;
};

#endif // CAT_HPP
