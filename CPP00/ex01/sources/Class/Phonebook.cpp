/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/16 16:55:25 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "Contact.hpp"
#include "Ostream.hpp"
#include <string>
#include <iostream>

using	std::cin;
using	std::cout;
using	std::getline;
using	std::endl;
using	std::string;

void	Phonebook::get_input(string const &prompt, string &input) const
{
	cout << prompt << endl;
	do
		cin >> input;
	while (input == "");
	cin.ignore(999999999, '\n');
	cout << endl;
}

void	Phonebook::get_line(string const &prompt, string &input) const
{
	cout << prompt << endl;
	getline(cin, input);
	while (input == "")
		getline(cin, input);
	cout << endl;
}

void	Phonebook::formatting_contact(string &str) const
{
	size_t	size;

	size = str.length();
	if (size > 10)
	{
		str[9] = '.';
		str.resize(10);
	}
	else if (size < 10)
	{
		string	tmp;
		tmp.resize(10 - size, ' ');
		str.insert(0, tmp);
	}
}

Phonebook::Phonebook() :
	_prompt_display("     index| firstname|  lastname|  nickname"),
	_empty_list("     empty|     empty|     empty|     empty")
{

	_contacts_index = -1;
}

void	Phonebook::add_contact()
{
	string	input;

	if (_contacts_index < 7)
		_contacts_index++;
	get_input("What is your first name?", input);
	_contacts[_contacts_index].set_first_name(input);
	formatting_contact(input);
	_format_contacts[_contacts_index] = '|' + input;
	get_input("What is your last name?", input);
	_contacts[_contacts_index].set_last_name(input);
	formatting_contact(input);
	_format_contacts[_contacts_index] += '|' + input;
	get_input("What is your nickname?", input);
	_contacts[_contacts_index].set_nickname(input);
	formatting_contact(input);
	_format_contacts[_contacts_index] += '|' + input;
	get_input("What is your phone number?", input);
	_contacts[_contacts_index].set_phone_number(input);
	get_line("What is your darkest secret?", input);
	_contacts[_contacts_index].set_darkest_secret(input);
}

bool	Phonebook::display_all() const
{	
	cout << _prompt_display << endl;
	if (_contacts_index < 0)
	{
		cout << _empty_list << endl;
		return (false);
	}
	for (int i = 0; i <= _contacts_index; i++)
	{
		cout << "         ";
		cout << (i + 1);
		cout << _format_contacts[i] << endl;
	}
	return (true);
}

void	Phonebook::display_one(int index) const
{
	index--;
	if (index >= 0 && index <= _contacts_index)
		cout << _contacts[index];
	else
		cout << "Wrong index!" << endl;
}

Phonebook::~Phonebook()
{
}
