/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/24 22:11:53 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <string>
#include <iostream>

using	std::string;
using	std::cout;
using	std::endl;
using	std::ostream;

/*************   PRIVATE   *************/ 

/*************   PUBLIC   *************/ 

Dog::Dog() :  Animal("Dog")
{
	cout << "<Dog> default constructor called" << endl;
}

Dog::Dog(string const &type) : Animal(type)
{
	cout << "<Dog> name constructor called" << endl;
}

Dog::Dog(Dog const &dog)
{
	operator=(dog);
	cout << "<Dog> copy constructor called" << endl;
}

Dog	&Dog::operator=(Dog const &dog)
{
	if (this != &dog)
	{
		Animal::operator=(dog);
	}
	return (*this);
}

ostream &Dog::display(ostream &os) const
{
	os << "<Dog> type: " << _type << endl;
	return (os);
}

void	Dog::makeSound() const
{
	cout << "WOUUUAAAAF" << endl;
}

ostream &operator<<(ostream &left, Dog const &right)
{
	return (right.display(left));
}

Dog::~Dog()
{
	cout << "<Dog> destructor called" << endl;
}
