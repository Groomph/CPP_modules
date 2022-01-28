/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/26 23:27:56 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __MATERIASOURCE_HPP__
# define __MATERIASOURCE_HPP__

# include "AMateria.hpp"
# include <string>
# include <iostream>

using	std::string;
using	std::ostream;

// ************************************************************************** //
//                           MateriaSource Interface                          //
// ************************************************************************** //

class IMateriaSource
{
	public:
		virtual ~IMateriaSource(void) {}

		virtual void		learnMateria(AMateria *materia) = 0;
		virtual AMateria	*createMateria(string const &type) const = 0;
};

// ************************************************************************** //
//                             MateriaSource Class                            //
// ************************************************************************** //

# define MAX_INVENTORY 4

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_inventory[MAX_INVENTORY];

	public:
		MateriaSource();
		MateriaSource(MateriaSource const &materia);
		~MateriaSource(void);

		MateriaSource	&operator=(MateriaSource const &materia);
		ostream	&display(ostream &os) const;

		void		learnMateria(AMateria *materia);
		AMateria	*createMateria(string const &type) const;
};

ostream	&operator<<(ostream &os, MateriaSource const &materia);

#endif /* __MATERIASOURCE_HPP__ */
