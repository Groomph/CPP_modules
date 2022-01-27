/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:24:18 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/27 17:02:51 by rsanchez         ###   ########.fr       */
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
	for (int i = 0; i < 30; i++)
		brigit++;
	cout << brigit << endl;
	cout << bob << endl;
	bob = brigit;
	cout << bob << endl;

	return 0;
}
