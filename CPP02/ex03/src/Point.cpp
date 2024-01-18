
#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{
	// Default constructor
}

Point::Point(const float xVal, const float yVal) : _x(xVal), _y(yVal)
{
	// Float constructor
}

Point::Point(const Point &src) : _x(src._x), _y(src._y)
{
	// Copy constructor
	*this = src;
}

Point::~Point(void)
{
	// Destructor
}

Fixed	Point::getX(void) const
{
	return (this->_x);
}

Fixed	Point::getY(void) const
{
	return (this->_y);
}

Point&	Point::operator=(const Point &rhs)
{
    if (this != &rhs)
	{
        const_cast<Fixed&>(this->_x) = rhs._x;
        const_cast<Fixed&>(this->_y) = rhs._y;
    }
    return (*this);
}
