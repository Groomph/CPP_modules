/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:24:18 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/16 22:28:11 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

using	std::string;

int	main()
{
	Zombie	*z_ptr;
	int	size;

	size = 1;
	z_ptr = zombieHorde(size, "Rudolphe");
	for (int i = 0; i < size; i++)
		z_ptr[i].announce();
	if (z_ptr)
		delete[] z_ptr;
	return (0);
}
