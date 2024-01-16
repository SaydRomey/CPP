/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Integer.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:34:29 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/16 14:39:33 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTEGER_CLASS_HPP
# define INTEGER_CLASS_HPP

#include <iostream>

class	Integer
{
	public:
		Integer(int const n);
		~Integer(void);

		int	getValue(void) const;

		Integer &	operator=(Integer const & rhs);
		Integer		operator+(Integer const & rhs) const;
	
	private:
		int	_n;
};

std::ostream & operator<<(std::ostream & o, Integer const & rhs);

#endif