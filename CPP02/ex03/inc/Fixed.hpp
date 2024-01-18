/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:14:46 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/17 21:14:50 by cdumais          ###   ########.fr       */
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
			void	setRawBits(int const raw);
			float	toFloat(void) const;
			int		toInt(void) const;

			static Fixed&		min(Fixed &lhs, Fixed &rhs);
			static const Fixed&	min(const Fixed &lhs, const Fixed &rhs);
			static Fixed&		max(Fixed &lhs, Fixed &rhs);
			static const Fixed&	max(const Fixed &lhs, const Fixed &rhs);
			
			Fixed&	operator=(const Fixed &rhs);
			bool	operator>(const Fixed &rhs) const;
			bool	operator<(const Fixed &rhs) const;
			bool	operator>=(const Fixed &rhs) const;
			bool	operator<=(const Fixed &rhs) const;
			bool	operator==(const Fixed &rhs) const;
			bool	operator!=(const Fixed &rhs) const;
			Fixed	operator+(const Fixed &rhs) const;
			Fixed	operator-(const Fixed &rhs) const;
			Fixed	operator*(const Fixed &rhs) const;
			Fixed	operator/(const Fixed &rhs) const;
			Fixed&	operator++(void);
			Fixed&	operator--(void);
			Fixed	operator++(int);
			Fixed	operator--(int);
		
		private:
		
			int					_fixedPointValue;
			static int const	_fractionalBits = 8;
};

std::ostream & operator<<(std::ostream &out, const Fixed &rhs);

#endif
