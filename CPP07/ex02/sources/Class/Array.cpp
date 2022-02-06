/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/02/04 17:10:06 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

using	std::cout;
using	std::endl;

/*************   PRIVATE   *************/ 

ostream	&Array::display(ostream &os) const
{
	for (int i = 0; i < _size; i++)
	{
		os << _array[i] << '\n';
	}
	return (os);
}

/*************   PUBLIC   *************/ 

Array::Array() : _size(0), array(NULL)
{
}

Array::Array(unsigned int nb) : _size(nb)
{
	_array = new[] T(nb);
}

Array::Array(Array const &array)
{
	operator=(array);
}

Array::~Array()
{
	delete[] _array;
}

Array	&Array::operator=(Array const &array)
{
	if (this != &array)
	{
		_size = array._size;
		if (_array)
			delete[] _array;
		_array = new[] T(_size);
		for (int i = 0; i < _size; i++)
		{
			_array[i] = array._array[i];
		}
	}
	return (*this);
}

friend ostream	&operator<<(ostream &os, Array const &fixed)
{
	fixed.display(os);
	return (os);
}

T	&Array::operator[](unsigned int index) const
{
	if (index >= _size)
	{
		throw (IndexTooHighException())
	}
	else
	{
		return (_array[index]);
	}
}

unsigned int	size(void) const
{
	return (_size);
}
