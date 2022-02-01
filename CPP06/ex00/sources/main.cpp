/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:24:18 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/31 22:11:15 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <string>
#include <iostream>

using	std::cin;
using	std::cout;
using	std::endl;

int	main()
{
	Intern	bobby;
	Bureaucrat president("President", 1);
	string	form_name;
	string	target;
	Form	*form;

	while (!cin.eof())
	{
		cout << "Type request" << endl;
		getline(cin, form_name);
		if (!cin.eof())
		{
			cout << "Type target" << endl;
			getline(cin, target);
			form = bobby.makeForm(form_name, target);
			if (form)
			{
				president.signForm(*form);
				president.executeForm(*form);
				delete form;
			}
		}
	}
	return 0;
}
