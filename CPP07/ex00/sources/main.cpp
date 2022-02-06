/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:24:18 by rsanchez          #+#    #+#             */
/*   Updated: 2022/02/04 08:31:35 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SwapMinMax.hpp"
#include "Fixed.hpp"
#include <string>
#include <cstdlib>
#include <ctime>

using	std::cin;
using	std::cout;
using	std::endl;

int	main()
{
	Fixed	*fixed1;
	Fixed	*fixed2;
	string	buff;

	srand(time(NULL));
	while (!cin.eof())
	{

		fixed1 = new Fixed(rand()/static_cast<float>(rand()));
		fixed2 = new Fixed(rand()/static_cast<float>(rand()));

		cout << "INIT: Fixed point number 1: " << *fixed1 << endl;
		cout << "INIT: Fixed point number 2: " << *fixed2 << endl;
		cout << "Min result: " << min(*fixed1, *fixed2) << endl;
		cout << "Max result: " << max(*fixed1, *fixed2) << endl;
		cout << "Swap result:\n";
		swap(*fixed1, *fixed2);
		cout << "Fixed point number 1: " << *fixed1 << endl;
		cout << "Fixed point number 2: " << *fixed2 << endl;
		delete fixed1;
		delete fixed2;
		cout << "\n\nPress enter for another test" << endl;
		getline(cin, buff);
	}
	return (0);
}
