/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:14:46 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/18 13:43:31 by cdumais          ###   ########.fr       */
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

			static Fixed&		min(Fixed &lhs, Fixed &rhs);
			static Fixed const&	min(Fixed const &lhs, Fixed const &rhs);
			static Fixed&		max(Fixed &lhs, Fixed &rhs);
			static Fixed const&	max(Fixed const &lhs, Fixed const &rhs);
			
			Fixed&	operator=(Fixed const &rhs);
			bool	operator>(Fixed const &rhs) const;
			bool	operator<(Fixed const &rhs) const;
			bool	operator>=(Fixed const &rhs) const;
			bool	operator<=(Fixed const &rhs) const;
			bool	operator==(Fixed const &rhs) const;
			bool	operator!=(Fixed const &rhs) const;
			Fixed	operator+(Fixed const &rhs) const;
			Fixed	operator-(Fixed const &rhs) const;
			Fixed	operator*(Fixed const &rhs) const;
			Fixed	operator/(Fixed const &rhs) const;
			Fixed&	operator++(void);
			Fixed&	operator--(void);
			Fixed	operator++(int);
			Fixed	operator--(int);
		
		private:
		
			int					_fixedPointValue;
			static int const	_fractionalBits = 8;
};

std::ostream&	operator<<(std::ostream &out, Fixed const &rhs);

#endif
