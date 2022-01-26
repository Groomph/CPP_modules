/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/24 22:20:47 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <string>
#include <iostream>

using	std::string;
using	std::cout;
using	std::endl;
using	std::ostream;

/*************   PRIVATE   *************/ 

/*************   PUBLIC   *************/ 

WrongCat::WrongCat() :  WrongAnimal("WrongCat")
{
	cout << "<WrongCat> default constructor called" << endl;
}

WrongCat::WrongCat(string const &type) : WrongAnimal(type)
{
	cout << "<WrongCat> name constructor called" << endl;
}

WrongCat::WrongCat(WrongCat const &wrong)
{
	operator=(wrong);
	cout << "<WrongCat> copy constructor called" << endl;
}

WrongCat	&WrongCat::operator=(WrongCat const &wrong)
{
	if (this != &wrong)
	{
		WrongAnimal::operator=(wrong);
	}
	return (*this);
}

ostream &WrongCat::display(ostream &os) const
{
	os << "<WrongCat> type: " << _type << endl;
	return (os);
}

void	WrongCat::makeSound() const
{
	cout << "MIAAAAOUUUU" << endl;
}

ostream &operator<<(ostream &left, WrongCat const &right)
{
	return (right.display(left));
}

WrongCat::~WrongCat()
{
	cout << "<WrongCat> destructor called" << endl;
}
