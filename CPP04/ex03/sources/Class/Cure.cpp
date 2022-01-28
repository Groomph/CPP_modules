/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/27 00:17:13 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Cure.hpp"
#include <string>
#include <iostream>

using	std::string;
using	std::cout;
using	std::endl;
using	std::ostream;

/*************   PRIVATE   *************/ 

/*************   PUBLIC   *************/ 

Cure::Cure() : AMateria("cure")
{
	cout << "<Cure> default constructor called" << endl;
}

Cure::Cure(Cure const &materia)
{
	operator=(materia);
	cout << "<Cure> copy constructor called" << endl;
}

Cure::~Cure()
{
	cout << "<Cure> destructor called" << endl;
}

Cure	&Cure::operator=(Cure const &materia)
{
	if (this != &materia)
	{
		AMateria::operator=(materia);
	}
	return (*this);
}

AMateria	*Cure::clone() const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter const &target) const
{
	cout << "* heals " << target.getName() << "'s wounds *" << endl;
}
