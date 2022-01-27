/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/24 22:15:20 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __WRONGANIMAL_HPP__
#define __WRONGANIMAL_HPP__

#include <string>
#include <iostream>

using	std::string;
using	std::ostream;

// ************************************************************************** //
//                                WrongAnimal Class                                //
// ************************************************************************** //

class WrongAnimal
{
	protected:
		string	_type;

	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal const &wrong);
		WrongAnimal(string const &type);

		WrongAnimal	&operator=(WrongAnimal const &wrong);

		ostream	&display(ostream &os) const;
		string const	&getType(void) const;
		void	makeSound(void) const;

		~WrongAnimal(void);
};

ostream	&operator<<(ostream &os, WrongAnimal const &wrong);

#endif /* __WRONGANIMAL_HPP__ */
