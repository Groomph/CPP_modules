/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/18 14:10:55 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

using	std::cout;
using	std::endl;

/*************   PRIVATE   *************/ 

void inline	Fixed::_setPositive()
{
	_rawValue &= 0x7fffffff;
}

void inline	Fixed::_setNegative()
{
	_rawValue |= 0x80000000;
}

bool	Fixed::_isNegative() const
{
	if (_rawValue & 0x80000000)
		return (true);
	return (false);
}

bool	Fixed::_isInteger() const
{
	if (_rawValue & 0xff)
		return (false);
	return (true);
}

void	Fixed::_setFromInt(int nb)
{
	bool	isNeg = false;

	if (nb < 0)
	{
		isNeg = true;
		nb = -nb;
	}
	_rawValue = nb << _fraction_bits;
	if (isNeg)
		_setNegative();
	else
		_setPositive();
}

void	Fixed::_setFromFloat(float nb)
{
	bool	isNeg = false;

	if (nb < 0.0)
	{
		isNeg = true;
		nb = -nb;
	}
	_rawValue = roundf(nb * _coef);
	if (isNeg)
		_setNegative();
	else
		_setPositive();
}

/*************   PUBLIC   *************/ 

Fixed::Fixed() : _rawValue(0)
{
	cout << "Default constructor called" << endl;
}

Fixed::Fixed(int nb)
{
	cout << "Int constructor called" << endl;
	_setFromInt(nb);
}

Fixed::Fixed(float nb)
{
	cout << "Float constructor called" << endl;
	_setFromFloat(nb);
}

Fixed::Fixed(Fixed const &fixed) : _rawValue(fixed._rawValue)
{
	cout << "Copy constructor called" << endl;
}

float	Fixed::toFloat() const
{
	float	ftmp;

	if (_isNegative())
	{
		ftmp = roundf(_rawValue & 0x7fffffff);
		ftmp /= _coef;
		return (-ftmp);
	}
	return (roundf(_rawValue) / _coef);
}

int	Fixed::toInt() const
{
	int	tmp;
	if (_isNegative())
	{
		tmp = _rawValue & 0x7fffffff;
		tmp = tmp >> _fraction_bits;
		return (-tmp);
	}
	return (_rawValue >> _fraction_bits);
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

ostream	&Fixed::display(ostream &os) const
{
	if (_isInteger())
		os << toInt();
	else
		os << toFloat();
	return (os);
}

ostream	&operator<<(ostream &os, Fixed const &fixed)
{
	fixed.display(os);
	return (os);
}
