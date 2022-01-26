/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:24:18 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/18 20:21:30 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <string>
#include <iostream>

using	std::string;
using	std::cout;
using	std::endl;

int	main()
{
	/*
	ClapTrap	a("Bobby");
	ClapTrap	b;
	ClapTrap	c(a);

	a.attack("a tree");
	b.takeDamage(2);
	c.beRepaired(3);

	cout << a << b << c;
*/
	ScavTrap	aa("Bobby");
	ScavTrap	bb;
	ScavTrap	cc(aa);

	aa.attack("a tree");
	aa.guardGate();
	bb.takeDamage(2);
	bb.guardGate();
	cc.beRepaired(3);
	cc.guardGate();

	cout << aa << bb << cc;
	return 0;
}
