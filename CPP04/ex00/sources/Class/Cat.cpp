/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/24 22:12:10 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <string>
#include <iostream>

using	std::string;
using	std::cout;
using	std::endl;
using	std::ostream;

/*************   PRIVATE   *************/ 

/*************   PUBLIC   *************/ 

Cat::Cat() :  Animal("Cat")
{
	cout << "<Cat> default constructor called" << endl;
}

Cat::Cat(string const &type) : Animal(type)
{
	cout << "<Cat> name constructor called" << endl;
}

Cat::Cat(Cat const &cat)
{
	operator=(cat);
	cout << "<Cat> copy constructor called" << endl;
}

Cat	&Cat::operator=(Cat const &cat)
{
	if (this != &cat)
	{
		Animal::operator=(cat);
	}
	return (*this);
}

ostream &Cat::display(ostream &os) const
{
	os << "<Cat> type: " << _type << endl;
	return (os);
}

void	Cat::makeSound() const
{
	cout << "MIAAAAOUUUU" << endl;
}

ostream &operator<<(ostream &left, Cat const &right)
{
	return (right.display(left));
}

Cat::~Cat()
{
	cout << "<Cat> destructor called" << endl;
}
