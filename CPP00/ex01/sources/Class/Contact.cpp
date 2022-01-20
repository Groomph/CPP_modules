/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/16 16:52:42 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <string>
#include <iostream>

using	std::cout;
using	std::ostream;
using	std::endl;
using	std::string;

Contact::Contact(string const &first, string const &last, string const &nick,
		string const &number, string const &secret)
{
	_first_name = first;
	_last_name = last;
	_nickname = nick;
	_phone_number = number;
	_darkest_secret= secret;
}

void	Contact::set_first_name(string const &str)
{
	_first_name = str;
}

void	Contact::set_last_name(string const &str)
{
	_last_name = str;
}

void	Contact::set_nickname(string const &str)
{
	_nickname = str;
}

void	Contact::set_phone_number(string const &str)
{
	_phone_number = str;
}

void	Contact::set_darkest_secret(string const &str)
{
	_darkest_secret = str;
}

void	Contact::display_first_name() const
{
	cout << _first_name;
}

void	Contact::display_last_name() const
{
	cout << _last_name;
}

void	Contact::display_nickname() const
{
	cout << _nickname;
}

void	Contact::display_phone_number() const
{
	cout << _phone_number;
}

void	Contact::display_darkest_secret() const
{
	cout << _darkest_secret;
}

void	Contact::display(ostream &os) const
{
	os << _first_name << '\n'
		<< _last_name << '\n'
		<< _nickname << '\n'
		<< _phone_number << '\n'
		<< _darkest_secret << endl;
}

Contact::~Contact()
{

}
