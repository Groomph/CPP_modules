/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/24 19:09:22 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <string>
#include <iostream>

using	std::string;
using	std::cout;
using	std::endl;
using	std::ostream;

/*************   PRIVATE   *************/ 

void	DiamondTrap::display_name() const
{
	cout << "\033[1;33mDiamondTrap::<" << _name << ">\033[0m ";
}

/*************   PUBLIC   *************/ 

DiamondTrap::DiamondTrap() : ClapTrap("Shiny_clap_name"),
				_name("Shiny")
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPointsSave;
	_attackDamages = FragTrap::_attackDamages;
	display_name();
	cout << "default constructor called" << endl;
}

DiamondTrap::DiamondTrap(string const &name) : ClapTrap(name + "_clap_name"),
						_name(name)
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPointsSave;
	_attackDamages = FragTrap::_attackDamages;
	display_name();
	cout << "name constructor called" << endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &diamond)
{
	*this = diamond;
	display_name();
	cout << "copy constructor called" << endl;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &diamond)
{
	if (this != &diamond)
	{
//		ClapTrap::operator=(diamond);
		_name = diamond._name;
		ClapTrap::_name = diamond.ClapTrap::_name;
		_hitPoints = diamond._hitPoints;
		_energyPoints = diamond._energyPointsSave;
		_attackDamages = diamond._attackDamages;
	}
	display(cout);
	return (*this);
}

void	DiamondTrap::attack(string const &target) const
{
	ScavTrap::attack(target);
	//	display_name();
	//	cout << "attack " << target << " causing, " << _attackDamages
	//		<< " damages!" << endl;
}

void	DiamondTrap::whoAmI(void) const
{
	display_name();
	cout << "who am i? :( " << _name << " or " << ClapTrap::_name
		<< "?" << endl;
}

ostream &DiamondTrap::display(ostream &os) const
{
	os << "<<" << ClapTrap::_name << ">>" << '<' << _name
		<< "> Hitpoints:" << _hitPoints
		<< " Energypoints:" << _energyPoints
		<< " AttackDamages:" << _attackDamages << endl;
	return (os);
}

ostream &operator<<(ostream &left, DiamondTrap const &right)
{
	right.display(left);
	return (left);
}

DiamondTrap::~DiamondTrap()
{
	display_name();
	cout << "destructor called" << endl;
}
