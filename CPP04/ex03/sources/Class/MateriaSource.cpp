/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/26 19:16:52 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <string>
#include <iostream>

using	std::string;
using	std::cout;
using	std::endl;
using	std::ostream;

/*************   PRIVATE   *************/ 

/*************   PUBLIC   *************/ 

MateriaSource::MateriaSource() : _inventory()
{
	cout << "<MateriaSource> default constructor called" << endl;
}

MateriaSource::MateriaSource(MateriaSource const &matsource) : _inventory()
{
	operator=(matsource);
	cout << "<MateriaSource> copy constructor called" << endl;
}

MateriaSource::~MateriaSource()
{
	cout << "<MateriaSource> destructor called" << endl;
	for (int i = 0; i < MAX_INVENTORY; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &source)
{
	if (this != &source)
	{
		for (int i = 0; i < MAX_INVENTORY; i++)
		{
			if (_inventory[i])
				delete _inventory[i];
			if (source._inventory[i])
			{
				_inventory[i] = source._inventory[i]->clone();
				if (_inventory[i] == source._inventory[i])
				cout << "WRONG, the copy was not deep" << endl;
			}
			else
				_inventory[i] = NULL;
		}
	}
	return (*this);
}

ostream &MateriaSource::display(ostream &os) const
{
	bool	has_displayed = false;

	os << "<MateriaSource>\n";
	for (int i = 0; i < MAX_INVENTORY; i++)
	{
		if (_inventory[i])
		{
			os << *(_inventory[i]) << endl;
			has_displayed = true;
		}
	}
	if (!has_displayed)
		os << "No materia stored" << endl;
	return (os);
}

void		MateriaSource::learnMateria(AMateria *materia)
{
	for (int i = 0; i < MAX_INVENTORY; i++)
	{
		if (!(_inventory[i]))
		{
			_inventory[i] = materia->clone();
			if (_inventory[i] == materia)
				cout << "WRONG, the copy was not deep" << endl;
			return ;
		}
	}
	cout << "No room available for another materia" << endl;
}

AMateria	*MateriaSource::createMateria(string const &type) const
{
	for (int i = MAX_INVENTORY - 1; i >= 0; i--)
	{
		if (_inventory[i] && type == _inventory[i]->getType())
			return (_inventory[i]->clone());
	}
	cout << "This type don't match any learned materia here" << endl;
	return (NULL);
}

ostream &operator<<(ostream &left, MateriaSource const &right)
{
	return (right.display(left));
}
