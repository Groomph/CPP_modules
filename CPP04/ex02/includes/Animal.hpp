/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/26 12:55:50 by rsanchez         ###   ########.fr       */
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
//                          AAnimal Abstract Class                            //
// ************************************************************************** //

class AAnimal
{
	protected:
		string	_type;

	public:
		AAnimal();
		AAnimal(AAnimal const &animal);
		AAnimal(string const &type);

		AAnimal	&operator=(AAnimal const &animal);

		ostream	&display(ostream &os) const;
		string const	&getType(void) const;
		void virtual	makeSound(void) const = 0;

		virtual ~AAnimal(void);
};

ostream	&operator<<(ostream &os, AAnimal const &animal);

#endif /* __ANIMAL_HPP__ */
