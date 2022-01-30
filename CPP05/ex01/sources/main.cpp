/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:24:18 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/29 23:34:22 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

using	std::string;
using	std::cout;
using	std::endl;

int	main()
{
	Bureaucrat	bob;
	Bureaucrat	brigit("Brigit");

	cout << brigit << endl;
	for (int i = 0; i < 10; i++)
		++brigit;
	cout << brigit << endl;
	for (int i = 0; i < 12; i++)
		--brigit;
	cout << brigit << endl;
	cout << bob << endl;
	bob = brigit;
	cout << bob << endl;

	Bureaucrat	claire("Claire", 2);
	cout << claire << endl;
	++claire;
	++claire;
	++claire;
	cout << claire << endl;
	return 0;
}
