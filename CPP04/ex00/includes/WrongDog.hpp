/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/24 22:16:53 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __WRONGDOG_HPP__
#define __WRONGDOG_HPP__

#include "WrongAnimal.hpp"
#include <string>
#include <iostream>

using	std::string;
using	std::ostream;

// ************************************************************************** //
//                                  WrongDog Class                                 //
// ************************************************************************** //

class WrongDog : public WrongAnimal
{
	public:
		WrongDog();
		WrongDog(WrongDog const &wrong);
		WrongDog(string const &type);

		WrongDog	&operator=(WrongDog const &wrong);

		ostream	&display(ostream &os) const;
		void	makeSound(void) const;

		~WrongDog(void);
};

ostream	&operator<<(ostream &os, WrongDog const &wrong);

#endif /* __WRONGDOG_HPP__ */
