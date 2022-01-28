/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/28 21:23:59 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __SCAVTRAP_HPP__
#define __SCAVTRAP_HPP__

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

using	std::string;
using	std::ostream;

// ************************************************************************** //
//                               ScavTrap Class                               //
// ************************************************************************** //

class ScavTrap : public virtual ClapTrap
{
	protected:
		int	_energyPoints2;

	private:
		void	display_name() const;

	public:
		ScavTrap(void);
		ScavTrap(ScavTrap const &scavtrap);
		ScavTrap(string const &name);
		virtual	~ScavTrap(void);

		ScavTrap	&operator=(ScavTrap const &scavtrap);

		void		attack(string const &target);
		void		guardGate(void) const;
//		void		takeDamage(unsigned int amount);
//		void		beRepaired(unsigned int amout);
//		ostream	&display(ostream &os) const;
};

//ostream	&operator<<(ostream &os, ScavTrap const &point);

#endif /* __SCAVTRAP_HPP__ */
