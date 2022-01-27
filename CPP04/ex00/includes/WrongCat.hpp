/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/24 22:17:44 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __WRONGCAT_HPP__
#define __WRONGCAT_HPP__

#include "WrongAnimal.hpp"
#include <string>
#include <iostream>

using	std::string;
using	std::ostream;

// ************************************************************************** //
//                                  WrongCat Class                                 //
// ************************************************************************** //

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(WrongCat const &wrong);
		WrongCat(string const &type);

		WrongCat	&operator=(WrongCat const &wrong);

		ostream	&display(ostream &os) const;
		void	makeSound(void) const;

		~WrongCat(void);
};

ostream	&operator<<(ostream &os, WrongCat const &wrong);

#endif /* __WRONGCAT_HPP__ */
