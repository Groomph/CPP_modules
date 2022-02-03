/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/02/03 21:00:35 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cerrno>
#include <climits>

using	std::string;
using	std::cout;
using	std::endl;
using	std::setprecision;
using	std::fixed;
using	std::ostream;

/*************   PRIVATE   *************/ 

int	Data::_count = 0;

void	Data::display(ostream &os) const
{
	os << "<Data> ID: " << _id << " adress: " << this
		<< "\nCurrent number of different Data: " << _count;
}

/*************   PUBLIC   *************/ 

Data::Data() : _id(_count)
{
	_count++;
}

Data::Data(Data const &data)
{
	operator=(data);
	_count++;
}

Data::~Data()
{
	_count--;
	cout << "<Data> Destructor called for " << this
		<< "! Remaining Data: " << _count << endl;
}

Data	&Data::operator=(Data const &data)
{
	if (&data != this)
	{
		_id = data._id;
	}
	return (*this);
}

ostream		&operator<<(ostream &os, Data const &data)
{
	data.display(os);
	return (os);
}
