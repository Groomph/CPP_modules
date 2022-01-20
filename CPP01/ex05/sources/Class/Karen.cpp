/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/17 22:22:28 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"
#include <iostream>
#include <string>

using	std::cout;
using	std::endl;
using	std::string;

/*************   PRIVATE   *************/ 

void	Karen::debug()
{
	cout << "I love to get extra bacon for my 7XL-double-cheese-triple"
		<< "-pickle-special-ketchup burger. I just love it!" << endl;
}

void	Karen::info()
{
	cout << "I cannot believe adding extra bacon cost more money. You don’t"		<< " put enough! If you did I would not have to ask for it!"
		<< endl;
}

void	Karen::warning()
{
	cout << "I think I deserve to have some extra bacon for free. I’ve "
		"been coming here for years and you just started working"
		" here last month." << endl;
}

void	Karen::error()
{
	cout << "This is unacceptable, I want to speak to the manager now."
		<< endl;
}

void	Karen::_default()
{
	cout << "*complaining*"	<< endl;
}

/*************   PUBLIC   *************/ 

Karen::Karen()
{
	karen_t static const	karen_function[6] = {
		&Karen::debug,
		&Karen::info,
		&Karen::warning,
		&Karen::error,
		&Karen::_default,
		NULL,
	};

	_f = karen_function;
}

void	Karen::complain(string level)
{
	string static const grognasse[5] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i = 0;

	while (i < 4 && level != grognasse[i])
		i++;
	(this->*_f[i])();
}
