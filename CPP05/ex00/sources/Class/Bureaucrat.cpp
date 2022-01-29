/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/29 21:35:50 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ErrorBrcrat.hpp"
#include <string>
#include <iostream>

using	std::string;
using	std::cout;
using	std::cerr;
using	std::endl;
using	std::ostream;

/*************   PRIVATE   *************/ 

void	Bureaucrat::assign_grade(unsigned int grade)
{
	if (grade > 150)
	{
		throw (ErrorBrcrat(TOOLOW));
	}
	else if (grade < 1)
	{
		throw (ErrorBrcrat(TOOHIGH));
	}
	_grade = grade;
}

void	Bureaucrat::handle_grade(const char *error, unsigned int grade)
{
	if (grade > 150)
	{
		_grade = 150;
		cerr << error << endl;
	}
	else
	{
		_grade = 1;
		cerr << error << endl;
	}
}

/*************   PUBLIC   *************/ 

Bureaucrat::Bureaucrat() :  _name("Bobby"), _grade(150)
{
	cout << '<' << _name << "> default constructor called" << endl;
}

Bureaucrat::Bureaucrat(string const &name) : _name(name), _grade(150)
{
	cout << '<' << _name << "> name constructor called" << endl;
}

Bureaucrat::Bureaucrat(string const &name, unsigned int grade) : _name(name),
								_grade(grade)
{
	try
	{
		assign_grade(_grade);
	}
	catch (ErrorBrcrat &error)
	{
		handle_grade(error.what(), _grade);
	}
	cout << '<' << _name << "> name constructor called" << endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &brcrat) : _name(brcrat._name)
{
	cout << '<' << _name << "> copy constructor called" << endl;
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

ostream &Bureaucrat::display(ostream &os) const
{
	os << '<' << _name << "> Grade: " << _grade;
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
	try
	{
		assign_grade(--_grade);
		cout << '<' << _name << "> promoted to " << _grade << endl;
	}
	catch (ErrorBrcrat &error)
	{
		handle_grade(error.what(), _grade);
	}
}

void	Bureaucrat::degrade()
{
	try
	{
		assign_grade(++_grade);
		cout << '<' << _name << "> degraded to " << _grade << endl;
	}
	catch (ErrorBrcrat &error)
	{
		handle_grade(error.what(), _grade);
	}
}

ostream &operator<<(ostream &left, Bureaucrat const &right)
{
	right.display(left);
	return (left);
}

Bureaucrat::~Bureaucrat()
{
	cout << '<' << _name << "> destructor called" << endl;
}
