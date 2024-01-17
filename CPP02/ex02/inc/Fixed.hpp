/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:05:13 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/16 19:57:16 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>


class	Fixed
{
		public:
// constructors/destructors
			Fixed(void); //
			Fixed(int const i);
			Fixed(float const f);
			Fixed(Fixed const & src); //
			~Fixed(void); //
			
// setters/getters
			int		getRawBits(void) const;
			void	setRawBits(int const raw);
			
// member functions (methods ?)
			float	toFloat(void) const;
			int		toInt(void) const;

			static Fixed	min(Fixed & lhs, Fixed & rhs);
			static Fixed	min(Fixed const & lhs, Fixed const & rhs);
			static Fixed	max(Fixed & lhs, Fixed & rhs);
			static Fixed	max(Fixed const & lhs, Fixed const & rhs);
			
// operators
			Fixed &	operator=(Fixed const & rhs); //
// comparison
			bool	operator>(Fixed const & rhs) const;
			bool	operator<(Fixed const & rhs) const;
			bool	operator>=(Fixed const & rhs) const;
			bool	operator<=(Fixed const & rhs) const;
			bool	operator==(Fixed const & rhs) const;
			bool	operator!=(Fixed const & rhs) const;
// arithmetic
			Fixed	operator+(Fixed const & rhs) const;
			Fixed	operator-(Fixed const & rhs) const;
			Fixed	operator/(Fixed const & rhs) const;
			Fixed	operator*(Fixed const & rhs) const;
// pre
			Fixed	operator++(void);
			Fixed	operator--(void);
// post
			Fixed	operator++(int n);
			Fixed	operator--(int n);
		
		private:
// attributes
			int					_fixedPointValue;
			static int const	_fractionalBits = 8;
};

std::ostream & operator<<(std::ostream &o, Fixed const & rhs);

#endif
