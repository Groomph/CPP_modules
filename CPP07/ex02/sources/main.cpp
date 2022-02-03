/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:24:18 by rsanchez          #+#    #+#             */
/*   Updated: 2022/02/03 22:21:48 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>
#include <ctime>

using	std::string;
using	std::cin;
using	std::cout;
using	std::endl;
using	std::exception;

char static	generated;
char static	identified;

static Base	*generate(void)
{
	int	i = rand() % 3;

	switch (i)
	{
		case 0:
			generated = 'A';
			return (new A);
		case 1:
			generated = 'B';
			return (new B);
		case 2:
			generated = 'C';
			return (new C);
		default:
			cout << "not supposed to happen" << endl;
			return (NULL);
	}
}

static void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
	{
		identified = 'A';
		cout << "A class identified by pointer" << endl;
	}
	else if (dynamic_cast<B*>(p))
	{
		identified = 'B';
		cout << "B class identified by pointer" << endl;
	}
	else if (dynamic_cast<C*>(p))
	{
		identified = 'C';
		cout << "C class identified by pointer" << endl;
	}
}

static void	identify(Base &p)
{
	try
	{
		A	&tmp = dynamic_cast<A&>(p);
		(void)tmp;
		identified = 'A';
		cout << "A class identified by reference" << endl;
		return ;
	}
	catch (exception &e)
	{
//		cout << "cast to A failed: " << e.what() << endl;
	}
	try
	{
		B	&tmp = dynamic_cast<B&>(p);
		(void)tmp;
		identified = 'B';
		cout << "B class identified by reference" << endl;
		return ;
	}
	catch (exception &e)
	{
//		cout << "cast to B failed: " << e.what() << endl;
	}
	try
	{
		C	&tmp = dynamic_cast<C&>(p);
		(void)tmp;
		identified = 'C';
		cout << "C class identified by reference" << endl;
		return ;
	}
	catch (exception &e)
	{
//		cout << "cast to C failed: " << e.what() << endl;
	}
	cout << "not supposed to happen" << endl;
}

int	main()
{
	Base	*ptr;
	srand(time(NULL));
	string	buff;

	while (!cin.eof())
	{
		ptr = generate();
		identify(ptr);
		if (generated != identified)
			cout << "Wrong identifying" << endl;
		identify(*ptr);
		if (generated != identified)
			cout << "Wrong identifying" << endl;
		else
			cout << "The generated Class was indeed an "
				<< generated << endl;
		delete ptr;
		cout << "\n\nPress enter for another test" << endl;
		getline(cin, buff);
	}
	return (0);
}
