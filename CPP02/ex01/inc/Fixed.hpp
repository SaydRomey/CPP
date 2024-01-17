/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:57:44 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/16 18:19:45 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
		public:
		
			Fixed(void);
			Fixed(int const i);
			Fixed(float const f);
			Fixed(Fixed const & src);
			~Fixed(void);

			int		getRawBits(void) const;
			void	setRawBits(int const raw);
			float	toFloat(void) const;
			int		toInt(void) const;

			Fixed &	operator=(Fixed const & rhs);
		
		private:
		
			int					_fixedPointValue;
			static int const	_fractionalBits = 8;
};

std::ostream & operator<<(std::ostream &o, Fixed const & rhs);

#endif
