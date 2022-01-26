/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/18 20:18:19 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __CLAPTRAP_HPP__
#define __CLAPTRAP_HPP__

#include <string>
#include <iostream>

using	std::string;
using	std::ostream;

// ************************************************************************** //
//                              ClapTrap Class                                //
// ************************************************************************** //

class ClapTrap
{
	protected:
		string	_name;
		int	_hitPoints;
		int	_energyPoints;
		int	_attackDamages;

	public:

		ClapTrap(void);
		ClapTrap(ClapTrap const &claptrap);
		ClapTrap(string const &name);

		ClapTrap	&operator=(ClapTrap const &fixed);

		void		attack(string const &target) const;
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amout);
		ostream	&display(ostream &os) const;

		~ClapTrap(void);
};

ostream	&operator<<(ostream &os, ClapTrap const &point);

#endif /* __CLAPTRAP_HPP__ */
