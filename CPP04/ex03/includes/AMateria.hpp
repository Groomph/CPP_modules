/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/26 23:48:30 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __MATERIA_HPP__
# define __MATERIA_HPP__

# include "Character.hpp"
# include <string>
# include <iostream>

using	std::string;
using	std::ostream;

// ************************************************************************** //
//                           AMateria Abstract Class                          //
// ************************************************************************** //

class AMateria
{
	protected:
		string	_type;

	public:
		AMateria();
		AMateria(string const &type);
		AMateria(AMateria const &materia);

		AMateria	&operator=(AMateria const &materia);
		ostream	&display(ostream &os) const;

		string const		&getType(void) const;
		virtual	AMateria	*clone(void) const = 0;
		virtual void		use(ICharacter const &target) const;

		virtual	~AMateria(void);
};

ostream	&operator<<(ostream &os, AMateria const &materia);

#endif /* __MATERIA_HPP__ */
