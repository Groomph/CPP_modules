/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/27 00:04:46 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __CHARACTER_HPP__
# define __CHARACTER_HPP__

# include <string>
# include <iostream>

class AMateria;

using	std::string;
using	std::ostream;

// ************************************************************************** //
//                             Character Interface                            //
// ************************************************************************** //

class ICharacter
{
	public:
		virtual	~ICharacter(void) {}

		virtual	string const &getName(void) const = 0;
		virtual	void equip(AMateria *materia) = 0;
		virtual	void unequip(int idx) = 0;
		virtual	void use(int idx, ICharacter const &target) = 0;

		virtual ostream	&display(ostream &os) const = 0;
};

// ************************************************************************** //
//                               Character Class                              //
// ************************************************************************** //

# define MAX_INVENTORY 4

class Character : public ICharacter
{
	private:
		AMateria	*_inventory[MAX_INVENTORY];
		AMateria	*_ground;
		string		_name;

	public:
		Character(void);
		Character(string const &name);
		Character(Character const &character);
		~Character(void);


		Character	&operator=(Character const &character);
		ostream	&display(ostream &os) const;

		string const &getName(void) const;
                void equip(AMateria *materia);
                void unequip(int idx);
                void use(int idx, ICharacter const &target);
};

ostream	&operator<<(ostream &os, ICharacter const &character);

#endif /* __CHARACTER_HPP__ */
