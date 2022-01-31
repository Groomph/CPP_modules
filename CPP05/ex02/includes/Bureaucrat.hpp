/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/31 18:52:14 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __BUREAUCRAT_HPP__
# define __BUREAUCRAT_HPP__

# include "Form.hpp"
# include <string>
# include <iostream>
# include <exception>

using	std::string;
using	std::ostream;
using	std::exception;
 
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
		Bureaucrat(string const &name, unsigned int grade);
		~Bureaucrat(void);

		Bureaucrat	&operator=(Bureaucrat const &brcrat);
		Bureaucrat	&operator--(void);
		Bureaucrat	operator--(int);
		Bureaucrat	&operator++(void);
		Bureaucrat	operator++(int);
		friend ostream	&operator<<(ostream &os, Bureaucrat const &cra);

		string const	&getName(void) const;
		unsigned int	getGrade(void) const;
		void		promote(void);
		void		degrade(void);
		void		signForm(Form &form) const;
		void		executeForm(Form const &form) const;

	class GradeTooHighException : public exception
	{
		public:
			char const	*what() const throw();
	};

	class GradeTooLowException : public exception
	{
		public:
			char const	*what() const throw();
	};
};

#endif /* __BUREAUCRAT_HPP__ */
