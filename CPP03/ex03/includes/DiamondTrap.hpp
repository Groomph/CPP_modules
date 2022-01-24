/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/24 16:04:39 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __DIAMONDTRAP_HPP__
#define __DIAMONDTRAP_HPP__

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>
#include <iostream>

using	std::string;
using	std::ostream;

// ************************************************************************** //
//                               DiamondTrap Class                               //
// ************************************************************************** //

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		string	_name;
		void	display_name() const;

	public:
		DiamondTrap(void);
		DiamondTrap(DiamondTrap const &diamondtrap);
		DiamondTrap(string const &name);

		DiamondTrap	&operator=(DiamondTrap const &diamondtrap);

		void		attack(string const &target) const;
		void		whoAmI(void) const;
//		void		takeDamage(unsigned int amount);
//		void		beRepaired(unsigned int amout);
		ostream	&display(ostream &os) const;

		~DiamondTrap(void);
};

ostream	&operator<<(ostream &os, DiamondTrap const &diamond);

#endif /* __DIAMONDTRAP_HPP__ */
