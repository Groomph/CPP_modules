/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:24:18 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/28 20:50:36 by rsanchez         ###   ########.fr       */
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

	cout << "******* BOUCLE 1 *******" << endl;
	bb.attack("Bobby");
	bb.guardGate();
	aa.takeDamage(50);
	aa.guardGate();
	for (int i = 0; i < 15; i++)
		cc.beRepaired(3);
	cc.guardGate();
	cout << aa << bb << cc;
	cout << "\n\n******* BOUCLE 2 *******" << endl;
	bb.attack("Bobby");
	aa.takeDamage(50);
	aa.guardGate();
	for (int i = 0; i < 15; i++)
		cc.beRepaired(3);
	cc.guardGate();
	cout << aa << bb << cc;
	return 0;
}
