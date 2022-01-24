/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/24 18:48:11 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <string>
#include <iostream>

using	std::string;
using	std::cout;
using	std::endl;
using	std::ostream;

/*************   PRIVATE   *************/ 

void	FragTrap::display_name() const
{
	cout << "\033[1;32mFragTrap::<BROOOO" << _name << ">\033[0m ";
}

/*************   PUBLIC   *************/ 

FragTrap::FragTrap() :  ClapTrap("FragTrap")
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamages = 30;
	display_name();
	cout << "default constructor called" << endl;
}

FragTrap::FragTrap(string const &name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamages = 30;
	display_name();
	cout << "name constructor called" << endl;
}

FragTrap::FragTrap(FragTrap const &fragtrap) : ClapTrap(fragtrap)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamages = 30;
	display_name();
	cout << "copy constructor called" << endl;
}

FragTrap	&FragTrap::operator=(FragTrap const &fragtrap)
{
	if (this != &fragtrap)
	{
		ClapTrap::operator=(fragtrap);
	}
	return (*this);
}

void	FragTrap::attack(string const &target) const
{	
	display_name();
	cout << "attack " << target << " causing, " << _attackDamages
		<< " damages!" << endl;
}

void	FragTrap::highFivesGuys() const
{
	display_name();
	cout << "is currently requesting a high five!!!" << endl;
}

FragTrap::~FragTrap()
{
	display_name();
	cout << "destructor called" << endl;
}
