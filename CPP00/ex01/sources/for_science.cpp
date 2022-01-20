/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:06:30 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/12 22:37:56 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>

using std::ostringstream;
using std::string;
using std::cout;
using std::endl;

static char	to_upper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

static void	convert_str(string *str)
{
	for (string::iterator i = str->begin(); *i ; i++)
	{
		*i = to_upper(*i);
	}
}

int	main(int ac, char **av)
{
	if (ac == 1)
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	ostringstream oss;
	string str;
	for (int i = 1; i < ac; i++)
	{
		str = av[i];
	cout << sizeof(str) << endl;
		convert_str(&str);
		if (i < ac - 1)
			str += ' ';
		oss << str;
	}
	cout << oss.str() << endl;
	return (0);
}
