/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/31 22:08:13 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>
#include <iostream>

using	std::string;
using	std::cout;
using	std::endl;

/*************   PRIVATE   *************/ 

/*************   PUBLIC   *************/ 

Intern::Intern()
{
//	cout << '<' << _name << "> default constructor called" << endl;
}

Intern::Intern(__attribute__((unused)) Intern const &brcrat)
{
//	cout << '<' << _name << "> copy constructor called" << endl;
}

Intern::~Intern()
{
	cout << "<<Intern>> destructor called" << endl;
}

Intern	&Intern::operator=(__attribute__((unused)) Intern const &brcrat)
{
	return (*this);
}

Form	*Intern::alloc_shrubbery(string const &target)
{
	return (new Shrubbery(target));
}

Form	*Intern::alloc_robotomy(string const &target)
{
	return (new Robotomy(target));
}

Form	*Intern::alloc_presidential(string const &target)
{
	return (new Presidential(target));
}

Form	*Intern::makeForm(string const &name, string const &target) const
{
	string const static	request[] =
	{
		"shrubbery request",
		"robotomy request",
		"presidential request"
	};
	Form	*(*f[])(string const &) =
	{
		Intern::alloc_shrubbery,
		Intern::alloc_robotomy,
		Intern::alloc_presidential
	};
	for (int i = 0, max = sizeof(request) / sizeof(string); i < max; i++)
	{
		if (name == request[i])
		{
			cout << "Intern creates <" << name << '>' << endl;
			return (f[i](target));
		}
	}
	cout << "Intern couldn't create the form <" << name
		<< "> because it doesn't exist" << endl;
	return (NULL);
}
