/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:39:06 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/22 17:38:10 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

// Forward declaration of bsp function
bool	bsp(Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	// Create triangle vertices
	Point	vertexA(0, 0);
	Point	vertexB(0, 3);
	Point	vertexC(4, 0);
	
	// Create test points
	Point	insidePoint(1, 1);   // Should be inside the triangle
	Point	outsidePoint(5, 5);  // Should be outside the triangle
	Point	edgePoint(0, 1);     // On the edge of the triangle
	Point	vertexPoint(0, 0);   // At a vertex of the triangle

	// Test the bsp function
	std::cout << "Inside Point: " << (bsp(vertexA, vertexB, vertexC, insidePoint) ? "Inside" : "Outside") << std::endl;
	std::cout << "Outside Point: " << (bsp(vertexA, vertexB, vertexC, outsidePoint) ? "Inside" : "Outside") << std::endl;
	std::cout << "Edge Point: " << (bsp(vertexA, vertexB, vertexC, edgePoint) ? "Inside" : "Outside") << std::endl;
	std::cout << "Vertex Point: " << (bsp(vertexA, vertexB, vertexC, vertexPoint) ? "Inside" : "Outside") << std::endl;

	return (0);
}
