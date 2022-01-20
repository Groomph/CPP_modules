/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/17 18:26:09 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>
#include <string>

using	std::cout;
using	std::endl;
using	std::string;

/*************   PRIVATE   *************/ 

/*************   PUBLIC   *************/ 

HumanB::HumanB(string const &name) : _name(name), _weapon(NULL)
{
}

void	HumanB::attack() const
{
	if (_weapon)
	{
		cout << _name << " attacks with his " << _weapon->getType()
								<< endl;
	}
	else
		cout << _name << " doesn't have a weapon!" << endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}

HumanB::~HumanB()
{
}
