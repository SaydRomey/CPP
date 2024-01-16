/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:27:23 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/16 16:51:31 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class	Fixed
{
		public:
		
			Fixed(void);
			Fixed(Fixed const & src);
			~Fixed(void);

			int		getRawBits(void) const;
			void	setRawBits(int const raw);

			Fixed &	operator=(Fixed const & rhs);
		
		private:
		
			int					_fixedPointValue;
			static int const	_fractionalBits = 8;
};

#endif
