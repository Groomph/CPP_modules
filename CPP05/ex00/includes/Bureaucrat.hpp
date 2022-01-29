/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/29 20:57:21 by rsanchez         ###   ########.fr       */
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

		void	assign_grade(unsigned int grade);
		void	handle_grade(const char *error, unsigned int grade);
	public:

		Bureaucrat(void);
		Bureaucrat(Bureaucrat const &brcrat);
		Bureaucrat(string const &name);
		Bureaucrat(string const &name, unsigned int grade);
		~Bureaucrat(void);

		Bureaucrat	&operator=(Bureaucrat const &brcrat);
		Bureaucrat	&operator--(void);
		Bureaucrat	operator--(int);
		Bureaucrat	&operator++(void);
		Bureaucrat	operator++(int);
		ostream		&display(ostream &os) const;

		string const	&getName(void) const;
		unsigned int	getGrade(void) const;
		void		promote(void);
		void		degrade(void);
};

ostream	&operator<<(ostream &os, Bureaucrat const &brcrat);

#endif /* __BUREAUCRAT_HPP__ */
