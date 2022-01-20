/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:24:18 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/17 18:15:39 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

using	std::string;

void	test1()
{
	Weapon	club = Weapon("crude spiked club");
	HumanA	bob("Bob", club);

	bob.attack();
	club.setType("some other type of club");
	bob.attack();
}

void	test2()
{
	Weapon	club = Weapon("crude spiked club");
	HumanB	jim("Jim");

	jim.setWeapon(club);
	jim.attack();
	club.setType("some other type of club");
	jim.attack();
}

int	main()
{
	test1();
	test2();
	return (0);
}
