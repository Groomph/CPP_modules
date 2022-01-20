/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/18 11:04:51 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

using	std::cout;
using	std::endl;
using	std::string;

/*************   PRIVATE   *************/ 

/*************   PUBLIC   *************/ 

Fixed::Fixed() : _rawValue(0)
{
	cout << "Default constructor called" << endl;
}

Fixed::Fixed(int nb) : _rawValue(nb)
{
}

Fixed::Fixed(double nb) : _rawValue(nb)
{
}

Fixed::Fixed(Fixed const &fixed) : _rawValue(fixed._rawValue)
{
	cout << "Copy constructor called" << endl;
}

int	Fixed::getRawBits() const
{
	cout << "getRawBits member function called" << endl;
	return (_rawValue);
}

void	Fixed::setRawBits(int const raw)
{
	_rawValue = raw;
}

Fixed::~Fixed()
{
	cout << "Destructor called" << endl;
}

Fixed	&Fixed::operator=(Fixed const &fixed)
{
	cout << "Assignation operator called" << endl;
	if (this != &fixed)
		_rawValue = fixed._rawValue;
	return (*this);
}
