/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:27:23 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/18 12:57:48 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class	Fixed
{
		public:
		
			Fixed(void);
			Fixed(const Fixed &src);
			~Fixed(void);

			int		getRawBits(void) const;
			void	setRawBits(const int raw);

			Fixed&	operator=(const Fixed &rhs);
		
		private:
		
			int					_fixedPointValue;
			static int const	_fractionalBits = 8;
};

#endif
