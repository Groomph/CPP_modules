/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/26 12:47:46 by rsanchez         ###   ########.fr       */
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

Dog::Dog() :  Animal("Dog"), _brain(new Brain)
{
	cout << "<Dog> default constructor called" << endl;
}

Dog::Dog(string const &type) : Animal(type), _brain(new Brain)
{
	cout << "<Dog> name constructor called" << endl;
}

Dog::Dog(Dog const &dog) : _brain(new Brain)
{
	cout << "<Dog> copy constructor called" << endl;
	operator=(dog);
}

Dog	&Dog::operator=(Dog const &dog)
{
	if (this != &dog)
	{
		Animal::operator=(dog);
		*_brain = *(dog._brain);
	}
	return (*this);
}

ostream &Dog::display(ostream &os) const
{
	os << "<Dog> type: " << _type << endl;
	os << *_brain << endl;
	return (os);
}

void	Dog::makeSound() const
{
	cout << "WOUUUAAAAF" << endl;
}

void	Dog::setSomeIdeas() const
{
	_brain->setIdea(0, "I want hugs");
        _brain->setIdea(1, "I want to bark");
        _brain->setIdea(2, "I want to play");
        _brain->setIdea(3, "I want to bite something");
}

ostream &operator<<(ostream &left, Dog const &right)
{
	return (right.display(left));
}

Dog::~Dog()
{
	delete _brain;
	cout << "<Dog> destructor called" << endl;
}
