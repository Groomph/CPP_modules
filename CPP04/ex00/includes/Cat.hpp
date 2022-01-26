/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/24 22:34:43 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __CAT_HPP__
#define __CAT_HPP__

#include "Animal.hpp"
#include <string>
#include <iostream>

using	std::string;
using	std::ostream;

// ************************************************************************** //
//                                  Cat Class                                 //
// ************************************************************************** //

class Cat : public Animal
{
	public:
		Cat();
		Cat(Cat const &cat);
		Cat(string const &type);

		Cat	&operator=(Cat const &cat);

		ostream	&display(ostream &os) const;
		void	makeSound(void) const;

		~Cat(void);
};

ostream	&operator<<(ostream &os, Cat const &cat);

#endif /* __CAT_HPP__ */
