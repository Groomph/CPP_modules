/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:24:18 by rsanchez          #+#    #+#             */
/*   Updated: 2022/02/04 19:34:41 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Fixed.hpp"
#include <string>
#include <cstdlib>
#include <ctime>
#include <exception>

using	std::cin;
using	std::cout;
using	std::cerr;
using	std::endl;

static void	test_intarray(void)
{
	cout << "CREATING ARRAY AND INITIALIZE IT" << endl;
	Array<int>	arr1(10);
	for (int i = 0; i < 10; i++)
	{
		arr1[i] = rand() % 500;
	}
	cout << arr1 << endl;
	cout << "size: " << arr1.size() << endl;
	cout << "\nCOPY AND MODIFY THE FIRST ARRAY" << endl;
	Array<int>	arr2 = arr1;
	for (int i = 0; i < 10; i++)
	{
		arr1[i] = rand() % 500;
	}
	cout << "array1 (after modification):" << endl;
	cout << arr1 << endl;
	cout << "size: " << arr1.size() << endl;
	cout << "array2 (copy):" << endl;
	cout << arr2 << endl;
	cout << "size: " << arr2.size() << endl;
}

static void	test_fixedarray(void)
{
	cout << "\n\nSAME BUT WITH FIXED POINT NUMBERS" << endl;
	Array<Fixed>	arr1(10);
	for (int i = 0; i < 10; i++)
	{
		arr1[i] = Fixed(rand()/static_cast<float>(rand()));
	}
	cout << arr1 << endl;
	cout << "size: " << arr1.size() << endl;
	cout << "\nCOPY AND MODIFY THE FIRST ARRAY" << endl;
	Array<Fixed>	arr2 = arr1;
	for (int i = 0; i < 10; i++)
	{
		arr1[i] = Fixed(rand()/static_cast<float>(rand()));
	}
	cout << "array1 (after modification):" << endl;
	cout << arr1 << endl;
	cout << "size: " << arr1.size() << endl;
	cout << "array2 (copy):" << endl;
	cout << arr2 << endl;
	cout << "size: " << arr2.size() << endl;
}

static void	test_errorarray(void)
{
	Array<int>	arr1;
	cout << "\n\nINIT AN EMPTY ARRAY AND TRY TO REACH AN INDEX" << endl;
	cout << arr1 << endl;
	cout << "size: " << arr1.size() << endl;
	try
	{
		arr1[11] = 0;
	}
	catch (exception &e)
	{
		cerr << "Exception::" << e.what() << endl;
	}
}

int	main()
{
	string	buff;

	srand(time(NULL));
	while (!cin.eof())
	{
		test_intarray();
		test_fixedarray();
		test_errorarray();
		cout << "\n\nPress enter for another test" << endl;
		getline(cin, buff);
	}
	return (0);
}
