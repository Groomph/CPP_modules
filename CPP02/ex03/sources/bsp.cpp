/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:45:26 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/18 18:10:48 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

static Fixed	which_side(Point const &a, Point const &b, Point const &c)
{
	return (a.getX() - c.getX()) * (b.getY() - c.getY())
		- (b.getX() - c.getX()) * (a.getY() - c.getY());
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	d1, d2, d3;
	bool	has_neg, has_pos;

	d1 = which_side(point, a, b);
	d2 = which_side(point, b, c);
	d3 = which_side(point, c, a);
	has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
	return !(has_neg && has_pos);
}
