/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/31 20:33:49 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

using	std::string;
using	std::cout;
using	std::cerr;
using	std::endl;
using	std::ostream;

/*************   PRIVATE   *************/ 

/*************   PUBLIC   *************/ 

Form::Form() : _name("BasicForm"), _isSigned(false),
	_gradeSign(100), _gradeExec(50)
{
}

Form::Form(string const &name, unsigned int sign, unsigned int exec)
	: _name(name), _isSigned(false), _gradeSign(sign), _gradeExec(exec)
{
	if (_gradeSign > 150 || _gradeExec > 150)
		throw (GradeTooLowException());
	if (_gradeSign < 1 || _gradeExec < 1)
		throw (GradeTooHighException());
}

Form::Form(Form const &form) : _name(form._name),
	_gradeSign(form._gradeSign), _gradeExec(form._gradeExec)
{
	operator=(form);
}

Form	&Form::operator=(Form const &form)
{
	if (this != &form)
	{
		_isSigned = form._isSigned;
		_target = form._target;
	}
	return (*this);
}

ostream &operator<<(ostream &os, Form const &form)
{
	os << "Form::<" << form._name << "> isSigned:" << form._isSigned
		<< " _gradeSign:" << form._gradeSign
		<< " _gradeExec:" << form._gradeExec
		<< " _target:" << form._target;
	return (os);
}

string const	&Form::getName() const
{
	return (_name);
}

bool		Form::isSigned() const
{
	return (_isSigned);
}

unsigned int	Form::getGradeSign() const
{
	return (_gradeSign);
}

unsigned int	Form::getGradeExec() const
{
	return (_gradeExec);
}

void	Form::beSigned(Bureaucrat const &brcrat)
{
	if (!_isSigned)
	{
		if (_gradeSign >= brcrat.getGrade())
			_isSigned = true;
		else
			throw (GradeTooLowException());
	}
	else
		throw (FormAlreadySignedException());
}

Form::~Form()
{
	cout << "<<Form>><" << _name << "> destructor called" << endl;
}

char const	*Form::GradeTooLowException::what() const throw()
{
	return "Form::GradeTooLowException";
}

char const	*Form::GradeTooHighException::what() const throw()
{
	return "Form::GradeTooHighException";
}

char const	*Form::FormNotSignedException::what() const throw()
{
	return "Form::FormNotSignedException";
}

char const	*Form::FormAlreadySignedException::what() const throw()
{
	return "Form::FormAlreadySignedException";
}

static void	utoa_rec(unsigned int nb, string &dest, string const &base)
{
	if (nb >= 10)
		utoa_rec(nb / 10, dest, base);
	dest += base[nb % 10];
}

string		operator+(string const &str, unsigned int nb)
{
	string	tmp(str);
	utoa_rec(nb, tmp, "0123456789");
	return (tmp);
}
