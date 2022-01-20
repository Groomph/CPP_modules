/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:24:18 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/18 18:09:25 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

using	std::cout;
using	std::endl;

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int	main()
{
	Point	a(0, 18);
	Point	b(-6, 0);
	Point	c(6, 0);
	Point	p(0, 0);

	cout << "a\n" << a << "b\n" << b << "c\n" << c << "p\n" << p << endl;
	if (bsp(a, b, c, p))
		cout << "p is inside the triangle" << endl;
	else
		cout << "p is not inside the triangle" << endl;
	return 0;
}
