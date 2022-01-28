/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/27 00:04:04 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"
#include <string>
#include <iostream>

using	std::string;
using	std::cout;
using	std::endl;
using	std::ostream;

/*************   PRIVATE   *************/ 

/*************   PUBLIC   *************/ 

Character::Character() : _inventory(), _ground(NULL), _name("Bobby")
{
	cout << "<Character> default constructor called" << endl;
}

Character::Character(string const &name) : _inventory(), _ground(0), _name(name)
{
	cout << "<Character> name constructor called" << endl;
}

Character::Character(Character const &character) : _inventory(), _ground(NULL)
{
	operator=(character);
	cout << "<Character> copy constructor called" << endl;
}

Character::~Character()
{
	cout << "<Character> destructor called" << endl;
	for (int i = 0; i < MAX_INVENTORY; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
	if (_ground)
		delete _ground;
}

Character	&Character::operator=(Character const &chara)
{
	if (this != &chara)
	{
		for (int i = 0; i < MAX_INVENTORY; i++)
		{
			if (_inventory[i])
				delete _inventory[i];
			if (chara._inventory[i])
			{
				_inventory[i] = chara._inventory[i]->clone();
				if (_inventory[i] == chara._inventory[i])
				cout << "WRONG, the copy was not deep" << endl;
			}
			else
				_inventory[i] = NULL;
		}
		if (_ground)
			delete _ground;
		_ground = chara._ground;
		_name = chara._name;
	}
	return (*this);
}

ostream &Character::display(ostream &os) const
{
	bool	has_displayed = false;

	os << "<Character>\n" << _name << "\n";
	if (_ground)
		os << "have on the ground:" << *_ground;
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

string const	&Character::getName() const
{
	return (_name);
}

void		Character::equip(AMateria *materia)
{
	for (int i = 0; i < MAX_INVENTORY; i++)
	{
		if (!(_inventory[i]))
		{
			_inventory[i] = materia;
			return ;
		}
	}
	cout << "No room available for another materia\nLeft it on the ground"
		<< endl;
	if (_ground)
		delete _ground;
	_ground = materia;
}

void		Character::unequip(int index)
{
	if (index >= MAX_INVENTORY || index < 0)
	{
		cout << "Wrong index to unequip" << endl;
		return ;
	}
	if (!(_inventory[index]))
	{
		cout << "No materia at this index" << endl;
		return ;
	}
	if (_ground)
		delete _ground;
	_ground = _inventory[index];
	_inventory[index] = NULL;
	cout << "Left on the ground: " << *_ground << std::flush;
}

void		Character::use(int index, ICharacter const &target)
{
	if (index >= MAX_INVENTORY || index < 0)
	{
		cout << "Wrong index to use" << endl;
		return ;
	}
	if (!(_inventory[index]))
	{
		cout << "No materia at this index" << endl;
		return ;
	}
	_inventory[index]->use(target);
	delete _inventory[index];
	_inventory[index] = NULL;
}

ostream &operator<<(ostream &left, ICharacter const &right)
{
	return (right.display(left));
}
