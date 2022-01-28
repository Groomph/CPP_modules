/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/28 21:23:42 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __FRAGTRAP_HPP__
#define __FRAGTRAP_HPP__

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

using	std::string;
using	std::ostream;

// ************************************************************************** //
//                               FragTrap Class                               //
// ************************************************************************** //

class FragTrap : public virtual ClapTrap
{
	private:
		void	display_name(void) const;
	public:
		FragTrap(void);
		FragTrap(FragTrap const &fragtrap);
		FragTrap(string const &name);
		virtual	~FragTrap(void);

		FragTrap	&operator=(FragTrap const &fragtrap);

		void		attack(string const &target);
		void		highFivesGuys(void) const;
//		void		takeDamage(unsigned int amount);
//		void		beRepaired(unsigned int amout);
//		ostream	&display(ostream &os) const;
};

//ostream	&operator<<(ostream &os, FragTrap const &point);

#endif /* __FRAGTRAP_HPP__ */
