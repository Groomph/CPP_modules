/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:24:18 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/30 23:47:10 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <string>
#include <iostream>
#include <exception>

using	std::string;
using	std::cout;
using	std::cerr;
using	std::endl;

static void	test_ex01(void)
{
	cout << "\n\n*******EX01 TESTS*******" << endl;
	Form form("Formulaire1", 125, 95);
	cout << form << endl;
	try
	{
//		Form("Formulaire2", 180, -95);
	}
	catch (exception &e)
	{
		cerr << "exception caught: " << e.what() << endl;
	}
	Bureaucrat greg("greg", 120);
	greg.signForm(form);
	Form form2("Formulaire2", 115, 95);
	cout << form2 << endl;
	greg.signForm(form2);
	cout << "\n\n*******DESTRUCTOR FLOOD*******" << endl;
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
