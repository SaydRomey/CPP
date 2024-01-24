/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:03:17 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/23 19:05:06 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	public:

		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal&	operator=(const WrongAnimal &other);
		virtual ~WrongAnimal(void);

		virtual void	makeSound(void) const;
		std::string		getType(void) const;
	
	protected:

		std::string	_type;
};

#endif // WRONGANIMAL_HPP
