/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/17 18:19:42 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>
#include <string>

using	std::cout;
using	std::endl;
using	std::string;

/*************   PRIVATE   *************/ 

/*************   PUBLIC   *************/ 

Weapon::Weapon(string const &type) : _type(type)
{
}

string const	&Weapon::getType() const
{
	return (_type);
}

void	Weapon::setType(string const &name)
{
	_type = name;
}

Weapon::~Weapon()
{
}
