/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:24:18 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/28 21:30:24 by rsanchez         ###   ########.fr       */
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

int	main()
{
	DiamondTrap	bb("Bobby");
	DiamondTrap	aa;
	DiamondTrap	cc(aa);

	cout << "******* BOUCLE 1 *******" << endl;
	aa.attack("Bobby");
	bb.takeDamage(50);
	bb.guardGate();
	bb.highFivesGuys();
	bb.whoAmI();
	for (int i = 0; i < 15; i++)
		cc.beRepaired(3);
	cc.guardGate();
	cc.whoAmI();
	cout << aa << bb << cc;
	cout << "\n\n******* BOUCLE 2 *******" << endl;
	aa.attack("Bobby");
	bb.takeDamage(50);
	bb.guardGate();
	bb.highFivesGuys();
	bb.whoAmI();
	for (int i = 0; i < 15; i++)
		cc.beRepaired(3);
	cc.guardGate();
	cc.whoAmI();
	cout << aa << bb << cc;
	return 0;
}
