/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/30 23:48:12 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __FORM_HPP__
#define __FORM_HPP__

#include <string>
#include <iostream>
#include <exception>

using	std::string;
using	std::ostream;
using	std::exception;
 
class Bureaucrat;

// ************************************************************************** //
//                              Form Class                              //
// ************************************************************************** //

class Form
{
	private:
		string const		_name;
		bool			_isSigned;
		unsigned int const	_gradeSign;
		unsigned int const	_gradeExec;

		void	check_grade() const;
		void	low_grade(const char *error);
		void	high_grade(const char *error);
	public:

		Form(void);
		Form(Form const &form);
		Form(string const &name, unsigned int sign, unsigned int exec);
		~Form(void);

		Form		&operator=(Form const &form);
		friend ostream	&operator<<(ostream &os, Form const &form);

		string const	&getName(void) const;
		bool		isSigned(void) const;
		unsigned int	getGradeSign(void) const;
		unsigned int	getGradeExec(void) const;
		void		beSigned(Bureaucrat const &brcrat);

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


#endif /* __FORM_HPP__ */
