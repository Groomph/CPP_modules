/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/16 21:54:39 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

using	std::cout;
using	std::endl;
using	std::string;

/*************   PRIVATE   *************/ 

/*************   PUBLIC   *************/ 

Zombie::Zombie(string const &name) : _name(name)
{
}

void	Zombie::setName(string const &name)
{
	_name = name;
}

void	Zombie::announce() const
{
	cout << '<' << _name << "> BraiiiiiiinnnzzzZ..." << endl;
}

Zombie::~Zombie()
{
	cout << '<' << _name << "> is back in his grave" << endl;
}
