/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:45:37 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/16 22:26:41 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

using	std::string;

static int	utoa(int nb, char *buffer, char *base, int size_base)
{
	int	i;

	i = 0;
	if (nb >= size_base)
		i = utoa(nb / size_base, buffer, base, size_base);
	buffer[i] = base[nb % size_base];
	return (i + 1);
}

static string	operator+(string str, int i)
{
	char	buffer[20];
	int	size;

	size = utoa(i, buffer, (char *)"0123456789", 10);
	buffer[size] = '\0';
	str.insert(str.size(), buffer);
	return (str);
}

Zombie	*zombieHorde(int N, string name)
{
	Zombie	*z_ptr;

	if (N <= 0)
		return (NULL);
	z_ptr = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		z_ptr[i].setName(name + i);
	}
	return (z_ptr);
}
