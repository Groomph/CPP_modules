/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/18 20:18:42 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

using	std::string;
using	std::cout;
using	std::endl;
using	std::ostream;

/*************   PRIVATE   *************/ 

/*************   PUBLIC   *************/ 

ClapTrap::ClapTrap() :  _name("Claptrap"),
			_hitPoints(10),
			_energyPoints(10),
			_attackDamages(0)
{
	cout << '<' << _name << "> default constructor called" << endl;
}

ClapTrap::ClapTrap(string const &name) : _name(name),
					 _hitPoints(10),
					 _energyPoints(10),
					 _attackDamages(0)
{
	cout << '<' << _name << "> name constructor called" << endl;
}

ClapTrap::ClapTrap(ClapTrap const &claptrap) : _name(claptrap._name),
					 _hitPoints(claptrap._hitPoints),
					 _energyPoints(claptrap._energyPoints),
					 _attackDamages(claptrap._attackDamages)
{
	cout << '<' << _name << "> copy constructor called" << endl;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &claptrap)
{
	if (this != &claptrap)
	{
		_name = claptrap._name;
		_hitPoints = claptrap._hitPoints;
		_energyPoints = claptrap._energyPoints;
		_attackDamages = claptrap._attackDamages;
	}
	return (*this);
}

void	ClapTrap::attack(string const &target) const
{	
	cout << '<' << _name << "> attack " << target << " causing, "
		<< _attackDamages << " damages!" << endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	cout << '<' << _name << "> take " << amount << " damages!" << endl;
	_hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	cout << '<' << _name << "> get repaired of " << amount << " hitpoints!"
		<<endl;
	_hitPoints += amount;
}

ostream &ClapTrap::display(ostream &os) const
{
	os << '<' << _name << "> Hitpoints:" << _hitPoints
		<< " Energypoints:" << _energyPoints
		<< " AttackDamages:" << _attackDamages << endl;
	return (os);
}

ostream &operator<<(ostream &left, ClapTrap const &right)
{
	right.display(left);
	return (left);
}

ClapTrap::~ClapTrap()
{
	cout << '<' << _name << "> destructor called" << endl;
}
