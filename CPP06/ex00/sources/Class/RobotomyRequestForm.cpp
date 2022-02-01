/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/31 21:25:20 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <ctime>

using	std::string;
using	std::cout;
using	std::endl;
using	std::ofstream;

/*************   PRIVATE   *************/ 

unsigned int	Robotomy::_nb = 0;

string static const	g_target("target");
string static const	g_robo("Robotomy");

/*************   PUBLIC   *************/

Robotomy::Robotomy() : Form(g_robo + Robotomy::_nb, 72, 45)
{
	_target = g_target + Robotomy::_nb;
	Robotomy::_nb++;
}

Robotomy::Robotomy(string const &target) :
			Form(g_robo + Robotomy::_nb, 72, 45)
{
	_target = target;
	Robotomy::_nb++;
}

Robotomy::Robotomy(Robotomy const &form) : Form(form)
{
	Form::operator=(form);
}

Robotomy	&Robotomy::operator=(Robotomy const &form)
{
	if (this != &form)
	{
		Form::operator=(form);
	}
	return (*this);
}

void	Robotomy::execute(Bureaucrat const &executor) const
{
	time_t	timer = std::time(NULL);

	if (executor.getGrade() > getGradeExec())
		throw (GradeTooLowException());
	if (!isSigned())
		throw (FormNotSignedException());
	if (timer % 2)
	{
		cout << "Robotomy::<" << _target
			<< "> has been robotomized successfully" << endl;
	}
	else
	{
		 cout << "Robotomy::robotomization of <" << _target
       	                << "> failed" << endl;
	}
}

Robotomy::~Robotomy()
{
	Robotomy::_nb--;
	cout << "<<Robotomy>><" << getName() << "> destructor called" << endl;
}
