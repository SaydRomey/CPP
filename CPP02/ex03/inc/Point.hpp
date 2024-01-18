/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:15:40 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/17 22:01:39 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"


class Point
{
	public:
		Point(void);
		Point(const float xVal, const float yVal);
		Point(const Point &src);
		~Point(void);

		Fixed	getX(void) const;
		Fixed	getY(void) const;

		Point&	operator=(const Point &rhs); //should we put this in private for this class ?

	private:
	
		Fixed const	_x;
		Fixed const	_y;
};

#endif
