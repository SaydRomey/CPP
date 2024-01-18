/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:29:02 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/17 22:07:59 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// calculate the cross product in 2D to find the relative position of points
static Fixed	calculateCrossProduct(Point ref, Point target, Point point)
{
	// calculate the vectors from the reference point to the target and point
	Fixed	vectorToTargetX = target.getX() - ref.getX();
	Fixed	vectorToTargetY = target.getY() - ref.getY();
	Fixed	vectorToPointX = point.getX() - ref.getX();
	Fixed	vectorToPointY = point.getY() - ref.getY();

	// calculate the cross product
	Fixed	crossProduct = \
		vectorToTargetX * vectorToPointY - vectorToTargetY * vectorToPointX;

	return (crossProduct);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	// calculate the cross product for each side of the triangle with the point
	Fixed	crossAB = calculateCrossProduct(a, b, point);
	Fixed	crossBC = calculateCrossProduct(b, c, point);
	Fixed	crossCA = calculateCrossProduct(c, a, point);

	// check if the point is on any of the triangle's edges
	bool	onEdgeAB = crossAB == 0;
	bool	onEdgeBC = crossBC == 0;
	bool	onEdgeCA = crossCA == 0;

	if (onEdgeAB || onEdgeBC || onEdgeCA)
	{
		// the point is on an edge or vertex of the triangle
		return (false);
	}

	// determine if the point is on the same side for all edges of the triangle
	bool	isLeftAB = crossAB > 0;
	bool	isLeftBC = crossBC > 0;
	bool	isLeftCA = crossCA > 0;

	// the point must be on the same side
	// (either all left or all right) of all three edges
	return ((isLeftAB == isLeftBC) && (isLeftBC == isLeftCA));
}
