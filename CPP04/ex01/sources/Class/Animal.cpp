/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/24 22:07:36 by rsanchez         ###   ########.fr       */
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

Animal::Animal() :  _type("Animal")
{
	cout << "<Animal> default constructor called" << endl;
}

Animal::Animal(string const &type) : _type(type)
{
	cout << "<Animal> name constructor called" << endl;
}

Animal::Animal(Animal const &animal)
{
	operator=(animal);
	cout << "<Animal> copy constructor called" << endl;
}

Animal	&Animal::operator=(Animal const &animal)
{
	if (this != &animal)
	{
		_type = animal._type;
	}
	return (*this);
}

ostream &Animal::display(ostream &os) const
{
	os << "<Animal> type: " << _type << endl;
	return (os);
}

string const	&Animal::getType() const
{
	return (_type);
}

void	Animal::makeSound() const
{
	cout << "Animal doesn't make sound" << endl;
}

ostream &operator<<(ostream &left, Animal const &right)
{
	return (right.display(left));
}

Animal::~Animal()
{
	cout << "<Animal> destructor called" << endl;
}
