/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:24:18 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/17 22:30:47 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"
#include <iostream>

using	std::cout;
using	std::endl;

int	main(int ac, char **av)
{
	Karen	karen;

	if (ac != 2)
	{
		cout << "One complaint a the time please" << endl;
		return (1);
	}
	karen.complain(av[1]);
	return (0);
}
