/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/26 23:50:09 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <string>
#include <iostream>

using	std::string;
using	std::cout;
using	std::endl;
using	std::ostream;

/*************   PRIVATE   *************/ 

/*************   PUBLIC   *************/ 

AMateria::AMateria() :  _type("Unknown")
{
	cout << "<AMateria> default constructor called" << endl;
}

AMateria::AMateria(string const &type) : _type(type)
{
	cout << "<AMateria> name constructor called" << endl;
}

AMateria::AMateria(AMateria const &materia)
{
	operator=(materia);
	cout << "<AMateria> copy constructor called" << endl;
}

AMateria::~AMateria()
{
	cout << "<AMateria> destructor called" << endl;
}

AMateria	&AMateria::operator=(AMateria const &materia)
{
	if (this != &materia)
	{
		_type = materia._type;
	}
	return (*this);
}

ostream &AMateria::display(ostream &os) const
{
	os << "<AMateria> type: " << _type << endl;
	return (os);
}

string const	&AMateria::getType() const
{
	return (_type);
}

void	AMateria::use(ICharacter const &target) const
{
	cout << "can't happen, " << target.getName() << " is safe" << endl;
}

ostream &operator<<(ostream &left, AMateria const &right)
{
	return (right.display(left));
}
