/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 21:03:24 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/28 21:52:45 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <string>
#include <iostream>

using	std::string;
using	std::cin;
using	std::cout;
using	std::endl;

static bool is_valid_number(string const &input)
{
	if (input[0] >= '0' && input[0] <= '9')
		return (true);
	cout << "Wrong input!" << endl;
	return (false);
}

int	main()
{
	string	input;
	Phonebook	book;

	while (input != "EXIT")
	{
		cout << "\e[1;35mphonebook: \e[0m";
		cin >> input;
		if (cin.eof())
			break;
		if (input == "ADD")
			book.add_contact();
		else if (input == "SEARCH")
		{
			if (book.display_all())
			{
				cout << "Which index do you need?" << endl;
				do
					cin >> input;
				while (!is_valid_number(input));
				book.display_one(input[0] - '0');
			}
		}
	}
	cout << "\nHave a nice day!" << endl;
	return (0);
}
