/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/02/06 13:42:48 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>

using	std::cout;
using	std::endl;
using	std::vector;
using	std::exception;

/*************   PRIVATE   *************/

ostream	&Span::display(ostream &os) const
{
	for (int i = 0, size = _array.size() ; i < size; i++)
	{
		os << _array[i];
		if (i + 1 < size)
			os << ' ';
	}
	return (os);
}

int	Span::abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

/*************   PUBLIC   *************/

Span::Span() : _capacity(DEFAULT_SIZE),  _array(0)
{
}

Span::Span(unsigned int cap) : _capacity(cap), _array(0)
{
}

Span::Span(Span const &span)
{
	operator=(span);
}

Span::~Span()
{
}

Span	&Span::operator=(Span const &span)
{
	if (this != &span)
	{
		_capacity = span._capacity;
		_array = span._array;
	}
	return (*this);
}

ostream	&operator<<(ostream &os, Span const &span)
{
	span.display(os);
	return (os);
}

void	Span::addNumber(int nb)
{
	if (_array.size() < _capacity)
	{
		_array.push_back(nb);
	}
	else
	{
		throw (CapacityReachedException());
	}
}

void	Span::addNumber(t_iterator begin, t_iterator end)
{
	while (begin != end)
	{
		addNumber(*begin);
		begin++;
	}
}

int	Span::shortestSpan() const
{
	if (_array.size() < 2)
		throw (NotEnoughIndexException());

	vector<int>	copy(_array);
	int		dist(INT_MAX);

	sort(copy.begin(), copy.end());
	for (t_iterator it = copy.begin(), itend = copy.end() - 1; it != itend; it++)
	{
		if (abs(*it - *(it + 1)) < dist)
			dist = abs(*it - *(it + 1));
		if (dist == 0)
			break;
	}
	return (dist);
}

int	Span::longestSpan() const
{
	if (_array.size() < 2)
		throw (NotEnoughIndexException());

	vector<int>	copy(_array);

	sort(copy.begin(), copy.end());
	return (copy.back() - copy.front());
}

char const	*Span::NotEnoughIndexException::what() const throw()
{
	return ("NotEnoughIndexException");
}

char const	*Span::CapacityReachedException::what() const throw()
{
	return ("CapacityReachedException");
}
