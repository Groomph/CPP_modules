/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:24:18 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/17 16:01:31 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

using	std::cout;
using	std::endl;
using	std::string;

int	main()
{
	string	str("HI THIS IS BRAIN");
	string	*stringPTR(&str);
	string	&stringREF(str);

	cout << "Notre string: " << str << '\n'
	<< "Adresse de la string: " << &str << '\n'
	<< "Contenu du pointeur sur la string: " << stringPTR << '\n'
	<< "Adresse de la reference de la string: " << &stringREF << '\n'
	<< "(Les 3 adresses devraient être identiques)" << '\n'
	<< "Notre string par le pointeur: " << *stringPTR << '\n'
	<< "Notre string par la reference: " << stringREF << endl;
	return (0);
}
