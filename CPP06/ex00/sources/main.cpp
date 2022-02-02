/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:24:18 by rsanchez          #+#    #+#             */
/*   Updated: 2022/02/02 19:46:32 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"
#include <string>
#include <iostream>

using	std::cout;
using	std::cerr;
using	std::endl;

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		cerr << "One argument is required, exiting" << endl;
		return (1);
	}
	else if (ac > 2)
		cerr << "Only one argument is required" << endl;

	Convert	convert(av[1]);
	cout << convert<< endl;
	return (0);
}
