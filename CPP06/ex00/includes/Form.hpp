/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/31 20:33:10 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __FORM_HPP__
# define __FORM_HPP__

# include <string>
# include <iostream>
# include <exception>

using	std::string;
using	std::ostream;
using	std::exception;
 
class Bureaucrat;

// ************************************************************************** //
//                             Form Abstract Class                            //
// ************************************************************************** //

class Form
{
	private:
		string const		_name;
		bool			_isSigned;
		unsigned int const	_gradeSign;
		unsigned int const	_gradeExec;

	protected:
		string			_target;

	public:

		Form(void);
		Form(Form const &form);
		Form(string const &name, unsigned int sign, unsigned int exec);
		virtual ~Form(void);

		Form		&operator=(Form const &form);
		friend ostream	&operator<<(ostream &os, Form const &form);

		string const	&getName(void) const;
		bool		isSigned(void) const;
		unsigned int	getGradeSign(void) const;
		unsigned int	getGradeExec(void) const;
		void		beSigned(Bureaucrat const &brcrat);
		virtual void	execute(Bureaucrat const &executor) const = 0;

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
	class FormNotSignedException : public exception
	{
		public:
			char const	*what() const throw();
	};
	class FormAlreadySignedException : public exception
	{
		public:
			char const	*what() const throw();
	};
};

string	operator+(string const &str, unsigned int nb);

#endif /* __FORM_HPP__ */
