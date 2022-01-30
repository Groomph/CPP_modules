/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/30 23:50:01 by rsanchez         ###   ########.fr       */
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
//	cout << '<' << _name << "> default constructor called" << endl;
}

Form::Form(string const &name, unsigned int sign, unsigned int exec)
	: _name(name), _isSigned(false), _gradeSign(sign), _gradeExec(exec)
{
//	cout << '<' << _name << "> args constructor called" << endl;
	if (_gradeSign > 150 || _gradeExec > 150)
		throw (GradeTooLowException());
	if (_gradeSign < 1 || _gradeExec < 1)
		throw (GradeTooHighException());
}

Form::Form(Form const &form) : _name(form._name),
	_gradeSign(form._gradeSign), _gradeExec(form._gradeExec)
{
//	cout << '<' << _name << "> copy constructor called" << endl;
	operator=(form);
}

Form	&Form::operator=(Form const &form)
{
	if (this != &form)
	{
		_isSigned = form._isSigned;
	}
	return (*this);
}

ostream &operator<<(ostream &os, Form const &form)
{
	os << "Form::<" << form._name << "> isSigned:" << form._isSigned
		<< " _gradeSign:" << form._gradeSign
		<< " _gradeExec:" << form._gradeExec;
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
		cout << "Formulaire::<" << _name << "> is already signed"
			<< endl;
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
