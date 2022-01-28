/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/26 19:58:30 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __ICE_HPP__
#define __ICE_HPP__

# include "AMateria.hpp"
# include "Character.hpp"
# include <string>
# include <iostream>

using	std::string;
using	std::ostream;

// ************************************************************************** //
//                                 Ice Class                                 //
// ************************************************************************** //

class Ice : public AMateria
{
	public:
		Ice();
		Ice(Ice const &ice);
		~Ice(void);

		Ice	&operator=(Ice const &ice);

		AMateria	*clone(void) const;
		void		use(ICharacter const &target) const;
};

//ostream	&operator<<(ostream &os, Ice const &ice);

#endif /* __ICE_HPP__ */
