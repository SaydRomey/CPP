/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:57:44 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/18 13:13:49 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
		public:
		
			Fixed(void);
			Fixed(const int i);
			Fixed(const float f);
			Fixed(const Fixed &src);
			~Fixed(void);

			int		getRawBits(void) const;
			void	setRawBits(const int raw);
			float	toFloat(void) const;
			int		toInt(void) const;

			Fixed&	operator=(const Fixed &rhs);
		
		private:
		
			int					_fixedPointValue;
			static int const	_fractionalBits = 8;
};

std::ostream&	operator<<(std::ostream &out, const Fixed &rhs);

#endif
