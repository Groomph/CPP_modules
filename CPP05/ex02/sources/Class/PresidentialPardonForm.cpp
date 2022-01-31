/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/31 20:41:20 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <ctime>

using	std::string;
using	std::cout;
using	std::endl;
using	std::ofstream;

/*************   PRIVATE   *************/ 

unsigned int	Presidential::_nb = 0;

string static const	g_target("target");
string static const	g_presi("Presidential");

/*************   PUBLIC   *************/

Presidential::Presidential() :
		Form(g_presi + Presidential::_nb, 25, 5)
{
	_target = g_target + Presidential::_nb;
	Presidential::_nb++;
}

Presidential::Presidential(string const &target) :
			Form(g_presi + Presidential::_nb, 25, 5)
{
	_target = target;
	Presidential::_nb++;
}

Presidential::Presidential(Presidential const &form) : Form(form)
{
	Form::operator=(form);
}

Presidential	&Presidential::operator=(Presidential const &form)
{
	if (this != &form)
	{
		Form::operator=(form);
	}
	return (*this);
}

void	Presidential::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > getGradeExec())
		throw (GradeTooLowException());
	if (!isSigned())
		throw (FormNotSignedException());
	cout << "Presidential::<" << _target
		<< "> has been pardoned by Zaphod Beeblebrox" << endl;
}

Presidential::~Presidential()
{
	Presidential::_nb--;
	cout << "<<Presidential>><" << getName() << "> destructor called" << endl;
}
