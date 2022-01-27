/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/24 22:34:37 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __DOG_HPP__
#define __DOG_HPP__

#include "Animal.hpp"
#include <string>
#include <iostream>

using	std::string;
using	std::ostream;

// ************************************************************************** //
//                                  Dog Class                                 //
// ************************************************************************** //

class Dog : public Animal
{
	public:
		Dog();
		Dog(Dog const &dog);
		Dog(string const &type);

		Dog	&operator=(Dog const &dog);

		ostream	&display(ostream &os) const;
		void	makeSound(void) const;

		~Dog(void);
};

ostream	&operator<<(ostream &os, Dog const &dog);

#endif /* __DOG_HPP__ */
