/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:24:18 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/18 17:09:33 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

using	std::cout;
using	std::endl;

int	main()
{
	Fixed a;
	Fixed const b( -10 );
	Fixed const c( -42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	cout << "\n\n Comparaison boolean\n";
	std::cout << "c is " << c << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "(c < b)" << endl;
	std::cout << (c < b) << endl;
	std::cout << "(c == b)" << endl;
	std::cout << (c == b) << endl;
	std::cout << "(c != b)" << endl;
	std::cout << (c != b) << endl;
	Fixed	f( -100.0099f );
	Fixed	g( -100.0098f );
	std::cout << "f is " << f << std::endl;
	std::cout << "g is " << g << std::endl;
	std::cout << "(f >= g)" << endl;
	std::cout << (f >= g) << endl;
	std::cout << "(f == g)" << endl;
	std::cout << (f == g) << endl;
	a = 0;
	cout << "\n\n Incrementation\n";
	std::cout << "a is " << a << std::endl;
	std::cout << "++a is " << ++a << std::endl;
	std::cout << "a++ is " << a++ << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "--a is " << --a << std::endl;
	std::cout << "a-- is " << a-- << std::endl;
	std::cout << "a is " << a << std::endl;
	a = 15;
	cout << "\n\n Min max\n";
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "max is " << Fixed::max( a, b ) << std::endl;
	std::cout << "min is " << Fixed::min( b, a ) << std::endl;
	cout << "\n\n Operation\n";
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "b + c = " << b + c << std::endl;
	std::cout << "c - b = " << c - b<< std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "g is " << g << std::endl;
	std::cout << "a * g = " << a * g << std::endl;
	std::cout << "a / g = " << a / g<< std::endl;
	return 0;
}
