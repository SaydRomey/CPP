/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:06:52 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/24 13:07:04 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal
{
	public:

		AAnimal(void);
		AAnimal(const AAnimal &other);
		AAnimal&	operator=(const AAnimal &other);
		virtual	~AAnimal(void);

		virtual void	makeSound(void) const = 0; // Pure virtual function
		std::string		getType(void) const;

	protected:

		std::string	_type;
};

#endif // AANIMAL_HPP
