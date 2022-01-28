/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/26 11:59:53 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include <string>
#include <iostream>

using	std::string;
using	std::ostream;

// ************************************************************************** //
//                                Animal Class                                //
// ************************************************************************** //

class Animal
{
	protected:
		string	_type;

	public:
		Animal();
		Animal(Animal const &animal);
		Animal(string const &type);

		Animal	&operator=(Animal const &animal);

		ostream	&display(ostream &os) const;
		string const	&getType(void) const;
		void virtual	makeSound(void) const;

		virtual ~Animal(void);
};

ostream	&operator<<(ostream &os, Animal const &animal);

#endif /* __ANIMAL_HPP__ */
