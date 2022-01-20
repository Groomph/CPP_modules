/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:24:18 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/17 22:21:13 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"
#include <iostream>

using	std::cout;

int	main()
{
	Karen	karen;

	karen.complain("DEBUG");
	cout << "\n\n";
	karen.complain("INFO");
	cout << "\n\n";
	karen.complain("WARNING");
	cout << "\n\n";
	karen.complain("ERROR");
	cout << "\n\n";
	karen.complain("TAMER");
	return (0);
}
