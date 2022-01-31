/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:24:18 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/31 21:28:47 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>
#include <iostream>
#include <exception>

using	std::string;
using	std::cout;
using	std::cerr;
using	std::endl;

static void	test_ex01(void)
{
	cout << "\n\n*******EX02 TESTS*******" << endl;
	Shrubbery form("home");
	Robotomy form2("novak");
	Presidential form3("jiji");
	Bureaucrat peon("peon", 145);
	Bureaucrat ouvrier("ouvrier", 120);
	Bureaucrat manager("manager", 70);
	Bureaucrat cadre("cadre", 10);
	Bureaucrat president("president", 1);
	cout << peon << endl;
	cout << ouvrier << endl;
	cout << manager << endl;
	cout << cadre << endl;
	cout << president << endl;
	cout << form << endl;
	cout << form2 << endl;
	cout << form3 << endl;
	president.executeForm(form);
	president.executeForm(form2);
	president.executeForm(form3);
	cout << "\n\033[32;01mPEON ROUTINE" << endl;
	peon.signForm(form);
	peon.signForm(form);
	peon.signForm(form2);
	peon.signForm(form3);
	peon.executeForm(form);
	peon.executeForm(form2);
	peon.executeForm(form3);
	cout << "\n\033[33;01mOUVRIER ROUTINE" << endl;
	ouvrier.signForm(form);
	ouvrier.signForm(form2);
	ouvrier.signForm(form3);
	ouvrier.executeForm(form);
	ouvrier.executeForm(form2);
	ouvrier.executeForm(form3);
	cout << "\n\033[34;01mMANAGER ROUTINE" << endl;
	manager.signForm(form);
	manager.signForm(form2);
	manager.signForm(form3);
	manager.executeForm(form);
	manager.executeForm(form2);
	manager.executeForm(form3);
	cout << "\n\033[35;01mCADRE ROUTINE" << endl;
	cadre.signForm(form);
	cadre.signForm(form2);
	cadre.signForm(form3);
	cadre.executeForm(form);
	cadre.executeForm(form2);
	cadre.executeForm(form3);
	cout << "\n\033[36;01mPRESIDENT ROUTINE" << endl;
	president.signForm(form);
	president.signForm(form2);
	president.signForm(form3);
	president.executeForm(form);
	president.executeForm(form2);
	president.executeForm(form3);
	try
	{
//		Shrubbery form2("Formulaire2", 180, -95);
	}
	catch (exception &e)
	{
		cerr << "exception caught: " << e.what() << endl;
	}
	cout << "\033[00m\n\n*******DESTRUCTOR FLOOD*******" << endl;
}

int	main()
{
	Bureaucrat	bob;
	Bureaucrat	brigit("Brigit");

	cout << "*******BASIC TESTS*******" << endl;
	cout << brigit << endl;
	for (int i = 0; i < 10; i++)
		++brigit;
	cout << brigit << endl;
	try
	{
		for (int i = 0; i < 12; i++)
		--brigit;
	}
	catch (exception &e)
	{
		cerr << "exception caught: " << e.what() << endl;
	}
	cout << brigit << endl;
	cout << bob << endl;
	bob = brigit;
	cout << bob << endl;

	Bureaucrat	claire("Claire", 2);
	cout << claire << endl;
	++claire;
	try
	{
		++claire;
		++claire;
	}
	catch (exception &e)
	{
		cerr << "exception caught: " << e.what() << endl;
	}
	cout << claire << endl;
	test_ex01();
	return 0;
}
