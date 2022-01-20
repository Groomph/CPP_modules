/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/17 18:19:56 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __WEAPON_HPP__
#define __WEAPON_HPP__

# include <string>

using	std::string;

// ************************************************************************** //
//                               Weapon Class                                 //
// ************************************************************************** //

class Weapon {
	private:
		string	_type;

	public:

		Weapon(string const &type = "");
		string const	&getType() const;
		void	setType(string const &name);
		~Weapon(void);
};

#endif /* __WEAPON_HPP__ */
