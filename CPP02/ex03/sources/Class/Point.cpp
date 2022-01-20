/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/18 17:41:19 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"
#include <iostream>

using	std::cout;
using	std::endl;

/*************   PRIVATE   *************/ 

/*************   PUBLIC   *************/ 

Point::Point() : _x(0), _y(0)
{
}

Point::Point(float x, float y) : _x(x), _y(y)
{
}

Point::Point(Point const &point) : _x(point._x), _y(point._y)
{
}

Fixed	&Point::getX() const
{
	Fixed	*ptrx((Fixed *)&_x);
	return (*ptrx);
}

Fixed	&Point::getY() const
{
	Fixed	*ptry((Fixed *)&_y);
	return (*ptry);
}

Point	&Point::operator=(Point const &point)
{
	if (this != &point)
	{
		Fixed	*ptrx((Fixed *)&_x);
		Fixed	*ptry((Fixed *)&_y);

		*ptrx = point._x;
		*ptry = point._y;
	}
	return (*this);
}

std::ostream &Point::display(std::ostream &os) const
{
	cout << "x is " << _x << "\ny is " << _y << endl;
	return (os);
}

std::ostream &operator<<(std::ostream &left, Point const &right)
{
	right.display(left);
	return (left);
}

Point::~Point()
{
}
