/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/28 20:48:43 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <string>
#include <iostream>

using	std::string;
using	std::cout;
using	std::endl;
using	std::ostream;

/*************   PRIVATE   *************/ 

/*************   PUBLIC   *************/ 

ScavTrap::ScavTrap() :  ClapTrap("ScavTrap")
{
	ClapTrap::_hitPoints = 100;
	ClapTrap::_energyPoints = 50;
	ClapTrap::_attackDamages = 20;
	cout << "ScavTrap::<" << _name
		<< "> default constructor called" << endl;
}

ScavTrap::ScavTrap(string const &name) : ClapTrap(name)
{
	ClapTrap::_hitPoints = 100;
	ClapTrap::_energyPoints = 50;
	ClapTrap::_attackDamages = 20;
	cout << "ScavTrap::<" << _name << "> name constructor called" << endl;
}

ScavTrap::ScavTrap(ScavTrap const &scavtrap) : ClapTrap(scavtrap)
{
	ClapTrap::_hitPoints = 100;
	ClapTrap::_energyPoints = 50;
	ClapTrap::_attackDamages = 20;
	cout << "ScavTrap::<" << _name << "> copy constructor called" << endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &scavtrap)
{
	if (this != &scavtrap)
	{
		ClapTrap::operator=(scavtrap);
	}
	return (*this);
}

void	ScavTrap::attack(string const &target)
{	
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_energyPoints--;
		cout << "ScavTrap::<" << _name << "> attack " << target
			<< ", causing "	<< _attackDamages << " damages!"
			<< endl;
	}
	else if (_energyPoints == 0)
		lowEnergy();
	if (_hitPoints == 0)
		lowLife();
}

void	ScavTrap::guardGate() const
{
	if (_hitPoints > 0)
		cout << "ScavTrap::<" << _name
			<< "> have enterred in Gate keeper mode!" << endl;
	else
		lowLife();
}

/*
   void	ScavTrap::takeDamage(unsigned int amount)
   {
   cout << "ScavTrap::<" << _name << "> take " << amount
   << " damages!" << endl;
   _hitPoints -= amount;
   }

   void	ScavTrap::beRepaired(unsigned int amount)
   {
   cout << "ScavTrap::<" << _name << "> get repaired of " << amount
   << " hitpoints!" <<endl;
   _hitPoints += amount;
   }

   ostream &ScavTrap::display(ostream &os) const
   {
   os << "ScavTrap::<" << _name << "> Hitpoints:" << _hitPoints
   << " Energypoints:" << _energyPoints
   << " AttackDamages:" << _attackDamages << endl;
   return (os);
   }

   ostream &operator<<(ostream &left, ScavTrap const &right)
   {
   right.display(left);
   return (left);
   }
   */

ScavTrap::~ScavTrap()
{
	cout << "ScavTrap::<" << _name << "> destructor called" << endl;
}
