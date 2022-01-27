/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/27 17:02:29 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

using	std::string;
using	std::cout;
using	std::endl;
using	std::ostream;

/*************   PRIVATE   *************/ 

/*************   PUBLIC   *************/ 

Bureaucrat::Bureaucrat() :  _name("Bobby"), _grade(150)
{
	cout << '<' << _name << "> default constructor called" << endl;
}

Bureaucrat::Bureaucrat(string const &name) : _name(name), _grade(150)
{
	cout << '<' << _name << "> name constructor called" << endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &brcrat) _name(brcrat._name)
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

Bureaucrat	&Bureaucrat::operator--()
{
	degrade();
	return (*this);
}

ostream &Bureaucrat::display(ostream &os) const
{
	os << '<' << _name << "> Grade: " << _grade;
	return (os);
}

string const	&Bureaucrat::getName() const
{
	return (_name);

	nsigned int	Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::promote()
{
	if (_grade > 1)
	{
		_grade--;
		cout << '<' << _name << "> promoted to " _grade << endl;
	}
	else
		cout << '<' << _name
			<< "> is already the highest bureaucrat around"	<< endl;
}

void	Bureaucrat::degrade()
{
	if (_grade < 150)
	{
		_grade++;
		cout << '<' << _name << "> degraded to " _grade << endl;
	}
	else
		cout << '<' << _name
			<< "> is already at the lowest grade" << endl;
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
