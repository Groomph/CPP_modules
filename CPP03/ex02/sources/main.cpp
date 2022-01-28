/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:24:18 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/28 21:25:46 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>
#include <iostream>

using	std::string;
using	std::cout;
using	std::endl;

int	main()
{
	FragTrap	bb("Bobby");
	ScavTrap	aa;
	ScavTrap	cc(aa);

	cout << "******* BOUCLE 1 *******" << endl;
	aa.attack("Bobby");
	aa.guardGate();
	bb.takeDamage(50);
	bb.highFivesGuys();
	for (int i = 0; i < 15; i++)
		cc.beRepaired(3);
	cc.guardGate();
	cout << aa << bb << cc;
	cout << "\n\n******* BOUCLE 2 *******" << endl;
	aa.attack("Bobby");
	aa.guardGate();
	bb.takeDamage(50);
	bb.highFivesGuys();
	for (int i = 0; i < 15; i++)
		cc.beRepaired(3);
	cc.guardGate();
	cout << aa << bb << cc;
	return 0;
}
