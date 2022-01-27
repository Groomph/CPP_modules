/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/24 22:20:03 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <string>
#include <iostream>

using	std::string;
using	std::cout;
using	std::endl;
using	std::ostream;

/*************   PRIVATE   *************/ 

/*************   PUBLIC   *************/ 

WrongAnimal::WrongAnimal() :  _type("WrongAnimal")
{
	cout << "<WrongAnimal> default constructor called" << endl;
}

WrongAnimal::WrongAnimal(string const &type) : _type(type)
{
	cout << "<WrongAnimal> name constructor called" << endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &wrong)
{
	operator=(wrong);
	cout << "<WrongAnimal> copy constructor called" << endl;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &wrong)
{
	if (this != &wrong)
	{
		_type = wrong._type;
	}
	return (*this);
}

ostream &WrongAnimal::display(ostream &os) const
{
	os << "<WrongAnimal> type: " << _type << endl;
	return (os);
}

string const	&WrongAnimal::getType() const
{
	return (_type);
}

void	WrongAnimal::makeSound() const
{
	cout << "WrongAnimal doesn't make sound" << endl;
}

ostream &operator<<(ostream &left, WrongAnimal const &right)
{
	return (right.display(left));
}

WrongAnimal::~WrongAnimal()
{
	cout << "<WrongAnimal> destructor called" << endl;
}
