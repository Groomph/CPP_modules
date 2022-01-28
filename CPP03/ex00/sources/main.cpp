/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:24:18 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/28 20:45:36 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

using	std::string;
using	std::cout;
using	std::endl;

int	main()
{
	ClapTrap	a("Bobby");
	ClapTrap	b;
	ClapTrap	c(a);

	b.attack("Bobby");
	a.takeDamage(11);
	a.attack("a tree");
	for (int i = 0; i < 11; i++)
		c.beRepaired(3);

	cout << a << b << c;
	return 0;
}
