/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:24:18 by rsanchez          #+#    #+#             */
/*   Updated: 2022/02/03 21:06:06 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <iostream>
#include <stdint.h>

using	std::cout;
using	std::endl;

static Data	*deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

static uintptr_t	serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

int	main()
{
	cout << "Creation of multiple Data objects" << endl;
	Data	*d0 = new Data;
	cout << *d0 << '\n';
	Data	*d1 = new Data;
	cout << *d1 << '\n';
	Data	*d2 = new Data;
	cout << *d2 << endl;
	uintptr_t	tmp0;
	uintptr_t	tmp1;
	uintptr_t	tmp2;
	cout << "\n\nSERIALIZING (convert data objects pointers \
into unsigned int pointer type)" << endl;
	tmp0 = serialize(d0);
	tmp1 = serialize(d1);
	tmp2 = serialize(d2);
	cout << "unsigned int: " << tmp0 << '\n';
	cout << "unsigned int: " << tmp1 << '\n';
	cout << "unsigned int: " << tmp2 << endl;
	Data	*ptr0;
	Data	*ptr1;
	Data	*ptr2;
	cout << "\n\nDESERIALIZING (convert unsigned int pointers back into \
data objects pointer)" << endl;
	ptr0 = deserialize(tmp0);
	ptr1 = deserialize(tmp1);
	ptr2 = deserialize(tmp2);
	cout << "ptr: " << ptr0 << '\n' << *ptr0 << '\n';
	cout << "ptr: " << ptr1 << '\n' << *ptr1 << '\n';
	cout << "ptr: " << ptr2 << '\n' << *ptr2 << endl;
	delete ptr0;
	delete ptr1;
	delete ptr2;
	return (0);
}
