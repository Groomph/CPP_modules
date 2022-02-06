/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:24:18 by rsanchez          #+#    #+#             */
/*   Updated: 2022/02/05 19:35:05 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include "Fixed.hpp"
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using	std::cin;
using	std::cout;
using	std::cerr;
using	std::endl;
using	std::vector;

int	main()
{
	vector<int>			vec(5, 3);
	vector<int> const		cvec(5, 3);
//	vector<Fixed> const		cvec(5, Fixed(3.6f));
	vector<int>::iterator		it;
	vector<int>::const_iterator	cit;
//	vector<Fixed>::const_iterator	cit;
	int				test;
	string	buff;

	srand(time(NULL));
	while (!cin.eof())
	{

		vec[0] = rand() % 5;
		vec[1] = rand() % 5;
		vec[2] = rand() % 5;
		vec[3] = rand() % 5;
		vec[4] = rand() % 5;
		test = rand() % 5;
		try
		{
			it = easyfind(vec, test);
		}
		catch (exception const &e)
		{
			cerr << e.what() << " for " << test << endl;
		}
		test = rand() % 5;
		cit = easyfind(cvec, test);
		if (cit == cvec.end())
		{
			cerr << "No occurence of " << test
				<< " found in const vector" << endl;
		}
		else
		{
			cout << "First occurence of " << test
				<< " was at index " << cit - cvec.begin()
				<< endl;
		}
		cout << vec[0] << "     " << cvec[0] << endl;
		cout << vec[1] << "     " << cvec[1] << endl;
		cout << vec[2] << "     " << cvec[2] << endl;
		cout << vec[3] << "     " << cvec[3] << endl;
		cout << vec[4] << "     " << cvec[4] << endl;
		cout << "\n\nPress enter for another test" << endl;
		getline(cin, buff);
	}
	return (0);
}
