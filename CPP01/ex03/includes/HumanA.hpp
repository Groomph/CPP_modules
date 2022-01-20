/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/17 18:07:21 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __HUMANA_HPP__
#define __HUMANA_HPP__

# include <string>
# include <Weapon.hpp>

using	std::string;

// ************************************************************************** //
//                               HumanA Class                                 //
// ************************************************************************** //

class HumanA {
	private:
		string	_name;
		Weapon	&_weapon;

	public:

		HumanA(string const &name, Weapon &weapon_nam);
		void	attack() const;
		~HumanA(void);
};

#endif /* __HUMANA_HPP__ */
