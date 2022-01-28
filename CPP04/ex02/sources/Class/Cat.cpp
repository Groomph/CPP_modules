/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/26 13:09:50 by rsanchez         ###   ########.fr       */
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

Cat::Cat() :  AAnimal("Cat"), _brain(new Brain)
{
	cout << "<Cat> default constructor called" << endl;
}

Cat::Cat(string const &type) : AAnimal(type), _brain(new Brain)
{
	cout << "<Cat> name constructor called" << endl;
}

Cat::Cat(Cat const &cat) : _brain(new Brain)
{
	cout << "<Cat> copy constructor called" << endl;
	operator=(cat);
}

Cat	&Cat::operator=(Cat const &cat)
{
	if (this != &cat)
	{
		AAnimal::operator=(cat);
		*_brain = *(cat._brain);
	}
	return (*this);
}

ostream &Cat::display(ostream &os) const
{
	os << "<Cat> type: " << _type << endl;
	os << *_brain << endl;
	return (os);
}

void	Cat::makeSound() const
{
	cout << "MIAAAAOUUUU" << endl;
}

void    Cat::setSomeIdeas() const
{
	_brain->setIdea(0, "I want food");
	_brain->setIdea(1, "I want to sleep");
	_brain->setIdea(2, "I want to go out");
	_brain->setIdea(3, "I want to scratch something");
}

ostream &operator<<(ostream &left, Cat const &right)
{
	return (right.display(left));
}

Cat::~Cat()
{
	delete _brain;
	cout << "<Cat> destructor called" << endl;
}
