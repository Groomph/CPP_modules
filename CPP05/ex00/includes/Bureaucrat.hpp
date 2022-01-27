/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/27 16:59:50 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <string>
#include <iostream>

using	std::string;
using	std::ostream;
 
// ************************************************************************** //
//                              Bureaucrat Class                              //
// ************************************************************************** //

class Bureaucrat
{
	private:
		string const	_name;
		unsigned int	_grade;
	public:

		Bureaucrat(void);
		Bureaucrat(Bureaucrat const &brcrat);
		Bureaucrat(string const &name);
		~Bureaucrat(void);

		Bureaucrat	&operator=(Bureaucrat const &brcrat);
		Bureaucrat	&operator--(void);
		Bureaucrat	&operator++(void);
		ostream		&display(ostream &os) const;

		string const	&getName(void) const;
		unsigned int	getGrade(void) const;
		void		promote(void);
		void		degrade(void);
};

ostream	&operator<<(ostream &os, Bureaucrat const &brcrat);

#endif /* __BUREAUCRAT_HPP__ */
