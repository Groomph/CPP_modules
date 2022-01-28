/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/26 19:58:20 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include <string>
#include <iostream>

using	std::string;
using	std::cout;
using	std::endl;
using	std::ostream;

/*************   PRIVATE   *************/ 

/*************   PUBLIC   *************/ 

Ice::Ice() :  AMateria("ice")
{
	cout << "<Ice> default constructor called" << endl;
}

Ice::Ice(Ice const &materia)
{
	operator=(materia);
	cout << "<Ice> copy constructor called" << endl;
}

Ice::~Ice()
{
	cout << "<Ice> destructor called" << endl;
}

Ice	&Ice::operator=(Ice const &materia)
{
	if (this != &materia)
	{
		AMateria::operator=(materia);
	}
	return (*this);
}

AMateria	*Ice::clone() const
{
	return (new Ice(*this));
}

void		Ice::use(ICharacter const &target) const
{
	cout << "* shoots an ice bolt at " << target.getName() << " *" << endl;
}
