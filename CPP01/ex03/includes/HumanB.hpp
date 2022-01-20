/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/17 18:26:07 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __HUMANB_HPP__
#define __HUMANB_HPP__

# include <string>
# include <Weapon.hpp>

using	std::string;

// ************************************************************************** //
//                               HumanB Class                                 //
// ************************************************************************** //

class HumanB {
	private:
		string	_name;
		Weapon	*_weapon;

	public:

		HumanB(string const &name = "Bob");
		void	attack() const;
		void	setWeapon(Weapon &weapon);
		~HumanB(void);
};

#endif /* __HUMANB_HPP__ */
