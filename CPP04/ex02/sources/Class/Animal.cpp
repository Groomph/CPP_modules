/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/26 13:08:20 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <string>
#include <iostream>

using	std::string;
using	std::cout;
using	std::endl;
using	std::ostream;

/*************   PRIVATE   *************/ 

/*************   PUBLIC   *************/ 

AAnimal::AAnimal() :  _type("AAnimal")
{
	cout << "<AAnimal> default constructor called" << endl;
}

AAnimal::AAnimal(string const &type) : _type(type)
{
	cout << "<AAnimal> name constructor called" << endl;
}

AAnimal::AAnimal(AAnimal const &animal)
{
	operator=(animal);
	cout << "<AAnimal> copy constructor called" << endl;
}

AAnimal	&AAnimal::operator=(AAnimal const &animal)
{
	if (this != &animal)
	{
		_type = animal._type;
	}
	return (*this);
}

ostream &AAnimal::display(ostream &os) const
{
	os << "<AAnimal> type: " << _type << endl;
	return (os);
}

string const	&AAnimal::getType() const
{
	return (_type);
}

void	AAnimal::makeSound() const
{
	cout << "AAnimal doesn't make sound" << endl;
}

ostream &operator<<(ostream &left, AAnimal const &right)
{
	return (right.display(left));
}

AAnimal::~AAnimal()
{
	cout << "<AAnimal> destructor called" << endl;
}
