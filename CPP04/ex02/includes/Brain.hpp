/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/26 11:46:23 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __BRAIN_HPP__
#define __BRAIN_HPP__

# include <string>
# include <iostream>

using	std::string;
using	std::ostream;

// ************************************************************************** //
//                                Brain Class                                //
// ************************************************************************** //

# define MAX_IDEAS 100

class Brain
{
	private:
		string	_ideas[MAX_IDEAS];
		void	setIdeas(string const ideas[]);

	public:
		Brain();
		Brain(Brain const &brain);
		Brain(string const ideas[]);

		Brain	&operator=(Brain const &brain);

		ostream	&display(ostream &os) const;
		string const	&getIdea(int i) const;
		void		setIdea(int i, string const &idea);

		~Brain(void);
};

ostream	&operator<<(ostream &os, Brain const &brain);

#endif /* __BRAIN_HPP__ */
