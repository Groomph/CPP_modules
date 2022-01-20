/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/17 18:07:17 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>

using	std::cout;
using	std::endl;
using	std::string;

/*************   PRIVATE   *************/ 

/*************   PUBLIC   *************/ 

HumanA::HumanA(string const &name, Weapon &weapon) : _name(name),
							_weapon(weapon)
{
}

void	HumanA::attack() const
{
	cout << _name << " attacks with his " << _weapon.getType() << endl;
}

HumanA::~HumanA()
{
}
