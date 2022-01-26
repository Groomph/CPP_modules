/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/24 22:21:58 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"
#include <string>
#include <iostream>

using	std::string;
using	std::cout;
using	std::endl;
using	std::ostream;

/*************   PRIVATE   *************/ 

/*************   PUBLIC   *************/ 

WrongDog::WrongDog() :  WrongAnimal("WrongDog")
{
	cout << "<WrongDog> default constructor called" << endl;
}

WrongDog::WrongDog(string const &type) : WrongAnimal(type)
{
	cout << "<WrongDog> name constructor called" << endl;
}

WrongDog::WrongDog(WrongDog const &wrong)
{
	operator=(wrong);
	cout << "<WrongDog> copy constructor called" << endl;
}

WrongDog	&WrongDog::operator=(WrongDog const &wrong)
{
	if (this != &wrong)
	{
		WrongAnimal::operator=(wrong);
	}
	return (*this);
}

ostream &WrongDog::display(ostream &os) const
{
	os << "<WrongDog> type: " << _type << endl;
	return (os);
}

void	WrongDog::makeSound() const
{
	cout << "WOUUUAAAAF" << endl;
}

ostream &operator<<(ostream &left, WrongDog const &right)
{
	return (right.display(left));
}

WrongDog::~WrongDog()
{
	cout << "<WrongDog> destructor called" << endl;
}
