/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:06:30 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/14 21:01:17 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using std::string;
using std::cout;
using std::endl;

inline static char	to_upper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

static void	convert_str(string &str)
{
	for (int i = 0; str[i]; i++)
	{
		str[i] = to_upper(str[i]);
	}
}

int	main(int ac, char **av)
{
	if (ac == 1)
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	string str;
	for (int i = 1; i < ac; i++)
	{
		str += av[i];
		convert_str(str);
		if (i < ac - 1)
			str += ' ';
	}
	cout << str << endl;
	return (0);
}
