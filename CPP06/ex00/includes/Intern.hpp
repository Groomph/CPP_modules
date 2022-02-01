/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/31 22:05:10 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __INTERN_HPP__
# define __INTERN_HPP__

# include "Form.hpp"

// ************************************************************************** //
//                                 Intern Class                               //
// ************************************************************************** //

class Intern
{
	private:
		static Form    *alloc_shrubbery(string const &target);
		static Form    *alloc_robotomy(string const &target);
		static Form    *alloc_presidential(string const &target);

	public:

		Intern(void);
		Intern(Intern const &intern);
		~Intern(void);

		Intern	&operator=(Intern const &intern);

		Form	*makeForm(string const &name, string const &target)
									const;
};

#endif /* __INTERN_HPP__ */
