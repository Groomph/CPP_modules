/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:24:18 by rsanchez          #+#    #+#             */
/*   Updated: 2022/02/06 13:56:06 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using	std::cin;
using	std::cout;
using	std::cerr;
using	std::endl;
using	std::generate;

int	random_gen()
{
	return (rand() % 500);
}

int main()
{
	cout << "SUBJECT TEST" << endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	srand(time(NULL));

	vector<int>	vectmp(100000);
	vector<int>	vectmp2(10);
	string	buff;
	while (!cin.eof())
	{
		cout << "\n\nSMALL ARRAY TEST" << endl;
		Span sptmp = Span(2);
		sptmp.addNumber(rand() % 5);
		sptmp.addNumber(rand() % 5);
		cout << sptmp << endl;
		std::cout << sptmp.shortestSpan() << std::endl;
		std::cout << sptmp.longestSpan() << std::endl;

		cout << "\n\nTOO SMALL ARRAY TEST" << endl;
		sptmp = Span(5);
		sptmp.addNumber(rand() % 5);
		cout << sptmp << endl;
		try
		{
			std::cout << sptmp.shortestSpan() << std::endl;
			std::cout << sptmp.longestSpan() << std::endl;
		}
		catch (exception &e)
		{
			cerr << "ERROR::" << e.what() << endl;
		}

		cout << "\n\nREGULAR SIZE ARRAY TEST + ASSIGN WITH ITERATOR" << endl;
		sptmp = Span(10);
		generate(vectmp2.begin(), vectmp2.end(), random_gen);
		sptmp.addNumber(vectmp2.begin(), vectmp2.end());
		cout << sptmp << endl;
		try
		{
			std::cout << sptmp.shortestSpan() << std::endl;
			std::cout << sptmp.longestSpan() << std::endl;
		}
		catch (exception &e)
		{
			cerr << "ERROR::" << e.what() << endl;
		}
		cout << "\n\nPress enter for another test" << endl;
		getline(cin, buff);
		if (cin.eof())
			break ;
		cout << "\n\nVERY BIG ARRAY TEST + ASSIGN WITH ITERATOR" << endl;
		sptmp = Span(100000);
		generate(vectmp.begin(), vectmp.end(), random_gen);
		sptmp.addNumber(vectmp.begin(), vectmp.end());
		cout << sptmp << endl;
		try
		{
			std::cout << sptmp.shortestSpan() << std::endl;
			std::cout << sptmp.longestSpan() << std::endl;
		}
		catch (exception &e)
		{
			cerr << "ERROR::" << e.what() << endl;
		}
		cout << "\n\nPress enter for another test" << endl;
		getline(cin, buff);
	}

	return (0);
}
