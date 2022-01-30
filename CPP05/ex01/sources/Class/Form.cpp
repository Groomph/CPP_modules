/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/30 13:22:11 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <string>
#include <iostream>

using	std::string;
using	std::cout;
using	std::cerr;
using	std::endl;
using	std::ostream;

/*************   PRIVATE   *************/ 

void	Form::check_grade()
{
	if (_gradeSign > 150 || _gradeExec > 150)
	{
		throw (GradeTooLowException());
	}
	else if (_gradeSign < 1 || _gradeExec < 1)
	{
		throw (GradeTooHighException());
	}
}

void	Form::low_grade(const char *error)
{
	if (_gradeSign > 150)
		_gradeSign = 150;
	if (_gradeExec > 150)
		_gradeExec = 150;
	cerr << error << endl;
}

void	Form::high_grade(const char *error)
	if (_gradeSign < 1)
		_gradeSign = 1;
	if (_gradeExec < 1)
		_gradeExec = 1;
	cerr << error << endl;
}

/*************   PUBLIC   *************/ 

Form::Form() : _name("BasicForm"), _isSigned(false),
		_gradeSign(100), _gradeExec(50)
{
//	cout << '<' << _name << "> default constructor called" << endl;
}

Form::Form(string const &name, unsigned int sign, unsigned int exec)
	: _name(name), _isSigned(false), _gradeSign(sign), _gradeExec(exe)
{
//	cout << '<' << _name << "> args constructor called" << endl;
	try
		check_grade();
	catch (GradetooLowException const &error)
		lowGrade(error.what(), _grade);
	catch (GradetooLowException const &error)
		highGrade(error.what(), _grade);
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

ostream &Form::display(ostream &os) const
{
	os << "Form::<" << _name << "> isSigned:" << _isSigned
		<< " _gradeSign:" << _gradeSign << " _gradeExec:" << _gradeExec;
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

void	Form::beSigned(Bureaucrat brcrat)
{
	unsigned int	grade(brcrat.getGrade());

	try
	{
		if (_gradeSign >= grade)
			_isSigned = true;
		else
			throw (Grade

	try
	{
		assign_grade(--_grade);
		cout << '<' << _name << "> promoted to " << _grade << endl;
	}
	catch (exception const &error)
	{
		handle_grade(error.what(), _grade);
	}
}

void	Form::degrade()
{
	try
	{
		assign_grade(++_grade);
		cout << '<' << _name << "> degraded to " << _grade << endl;
	}
	catch (exception const &error)
	{
		handle_grade(error.what(), _grade);
	}
}

ostream &operator<<(ostream &left, Form const &right)
{
	right.display(left);
	return (left);
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
