/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/18 17:33:03 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __POINT_HPP__
#define __POINT_HPP__

#include "Fixed.hpp"

// ************************************************************************** //
//                               Point Class                                 //
// ************************************************************************** //

class Point {
	private:
		Fixed const		_x;
		Fixed const		_y;

	public:

		Point();
		Point(Point const &fixed);
		Point(float x, float y);

		Fixed	&getX() const;
		Fixed	&getY() const;
		Point	&operator=(Point const &fixed);
		ostream	&display(ostream &os) const;

		~Point(void);
};

ostream	&operator<<(ostream &os, Point const &point);

#endif /* __POINT_HPP__ */
