/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:24:18 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/26 13:10:11 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongDog.hpp"
#include "WrongCat.hpp"
#include <string>
#include <iostream>

using	std::string;
using	std::cout;
using	std::endl;

/*
static void	wrong_example()
{
	cout << "\n*******EXAMPLE IF DESTRUCTOR ARE NOT VIRTUAL*******" 
		<< "*******NO COMPIL IS ON PURPOSE*******" << endl;
	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* j = new WrongDog();
	const WrongAnimal* i = new WrongCat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	delete	meta;
	delete	j;
	delete	i;
}
*/

static void	example2()
{
	Dog	*dog = new Dog("Husky");

	dog->setSomeIdeas();
	cout << *dog << endl;

	Dog	dog2(*dog);
	cout << dog2 << endl;

	Dog	dog3 = dog2;
	cout << dog3 << endl;
	delete	dog;
}

int	main()
{
//	won't compil if uncommented
//	const AAnimal* meta = new AAnimal();
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	delete	j;
	delete	i;
	example2();
//	wrong_example();
	return 0;
}
