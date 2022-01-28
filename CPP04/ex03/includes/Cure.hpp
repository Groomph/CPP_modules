/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/26 19:58:39 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __CURE_HPP__
#define __CURE_HPP__

# include "AMateria.hpp"
# include "Character.hpp"
# include <string>
# include <iostream>

using	std::string;
using	std::ostream;

// ************************************************************************** //
//                                 Cure Class                                 //
// ************************************************************************** //

class Cure : public AMateria
{
	public:
		Cure();
		Cure(Cure const &cure);
		~Cure(void);

		Cure	&operator=(Cure const &cure);

		AMateria	*clone(void) const;
		void		use(ICharacter const &target) const;
};

//ostream	&operator<<(ostream &os, Cure const &cure);

#endif /* __CURE_HPP__ */
