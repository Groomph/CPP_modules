/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/31 21:23:19 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <string>
#include <iostream>

using	std::string;
using	std::cout;
using	std::cerr;
using	std::endl;
using	std::ostream;

/*************   PRIVATE   *************/ 

/*************   PUBLIC   *************/ 

Bureaucrat::Bureaucrat() :  _name("Bobby"), _grade(150)
{
//	cout << '<' << _name << "> default constructor called" << endl;
}

Bureaucrat::Bureaucrat(string const &name) : _name(name), _grade(150)
{
//	cout << '<' << _name << "> name constructor called" << endl;
}

Bureaucrat::Bureaucrat(string const &name, unsigned int grade) : _name(name),
								_grade(grade)
{
//	cout << '<' << _name << "> name constructor called" << endl;
	if (_grade > 150)
		throw (GradeTooLowException());
	if (_grade < 1)
		throw (GradeTooHighException());
}

Bureaucrat::Bureaucrat(Bureaucrat const &brcrat) : _name(brcrat._name)
{
//	cout << '<' << _name << "> copy constructor called" << endl;
	operator=(brcrat);
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &brcrat)
{
	if (this != &brcrat)
	{
		_grade = brcrat._grade;
	}
	return (*this);
}

Bureaucrat	&Bureaucrat::operator++()
{
	promote();
	return (*this);
}

Bureaucrat	Bureaucrat::operator++(int)
{
	Bureaucrat copy(*this);
	promote();
	return (copy);
}

Bureaucrat	&Bureaucrat::operator--()
{
	degrade();
	return (*this);
}

Bureaucrat	Bureaucrat::operator--(int)
{
	Bureaucrat copy(*this);
	degrade();
	return (copy);
}

ostream		&operator<<(ostream &os, Bureaucrat const &cra)
{
	os << "Bureaucrat::<" << cra._name << "> Grade: " << cra._grade;
	return (os);
}

string const	&Bureaucrat::getName() const
{
	return (_name);
}

unsigned int	Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::promote()
{
	if (_grade > 1)
	{
		--_grade;
		cout << '<' << _name << "> promoted to " << _grade << endl;
	}
	else
		throw (GradeTooHighException());
}

void	Bureaucrat::degrade()
{
	if (_grade < 150)
	{
		++_grade;
		cout << '<' << _name << "> degraded to " << _grade << endl;
	}
	else
		throw (GradeTooLowException());
}

void	Bureaucrat::signForm(Form &form) const
{
	try
	{
		form.beSigned(*this);
		cout << "Bureaucrat::<" << _name << "> signed <" 
			<< form.getName() << '>' << endl;
	}
	catch (exception &e)
	{
		cout << "Bureaucrat::<" << _name << "> couldn't sign "
		<< form.getName() << " because " << e.what() << endl;
	}
}

void	Bureaucrat::executeForm(Form const &form) const
{
	try
	{
		form.execute(*this);
		cout << "Bureaucrat::<" << _name << "> executed <"
			<< form.getName() << '>' << endl;
	}
	catch (exception &e)
	{
		cout << "Bureaucrat::<" << _name << "> couldn't execute <"
		<< form.getName() << "> because " << e.what() << endl;
	}
}

Bureaucrat::~Bureaucrat()
{
	cout << "<<Bureaucrat>><" << _name << "> destructor called" << endl;
}

char const	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat::GradeTooLowException";
}

char const	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat::GradeTooHighException";
}
