/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/26 12:54:10 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __DOG_HPP__
#define __DOG_HPP__

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>

using	std::string;
using	std::ostream;

// ************************************************************************** //
//                                  Dog Class                                 //
// ************************************************************************** //

class Dog : public AAnimal
{
	private:
		Brain	*_brain;
	public:
		Dog();
		Dog(Dog const &dog);
		Dog(string const &type);

		Dog	&operator=(Dog const &dog);

		ostream	&display(ostream &os) const;
		void	makeSound(void) const;
		void	setSomeIdeas(void) const;

		~Dog(void);
};

ostream	&operator<<(ostream &os, Dog const &dog);

#endif /* __DOG_HPP__ */
