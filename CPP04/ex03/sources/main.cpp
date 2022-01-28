/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:24:18 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/27 00:16:34 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include <string>
#include <iostream>

using	std::string;
using	std::cout;
using	std::endl;

static void	creation_materia()
{
	cout << "*******TEST1 create & clone materia*******\n";
	Cure	cure;

	cout << cure << endl;
	AMateria	*cure2 = cure.clone();
	if (cure2 == &cure)
		cout << "WRONG, cure2 was not a deep copy of cure\n";
	cout << *cure2 << "\n";
	delete cure2;
	cout << "/////DESTRUCTOR FLOOD/////" << endl;
}

static void	creation_materia_source()
{
	cout << "\n\n*******TEST2 create & use of MateriaSource*******" << endl;
	MateriaSource	source;
	Cure		cure1;
	Cure		cure2;
	Cure		cure3;
	Cure		ice1;
	Cure		ice2;

	cout << source << endl;
	source.learnMateria(&cure1);
	source.learnMateria(&cure2);
	source.learnMateria(&ice1);
	source.learnMateria(&cure3);
	cout << source << endl;

	MateriaSource *source2 = new MateriaSource(source);
	cout << *source2 << endl;
	cout << "/////DESTRUCTOR FLOOD/////\n";
	delete source2;

	cout << "\n\n***Copy of a full materia source and try to learn***";
	MateriaSource source3;
	source3 = source;
	source.learnMateria(&ice2);
	cout << "\n\n/////DESTRUCTOR FLOOD/////" << endl;
}

static void	subject_test()
{
	cout << "\n\n*******TEST3 subject test*******" << endl;
	IMateriaSource* src = new MateriaSource();

	Ice	*ice = new Ice();
	Cure	*cure = new Cure();
	src->learnMateria(ice);
	src->learnMateria(cure);

	ICharacter* me = new Character("me");
	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	cout << *me << endl;
	me->use(0, *bob);
	me->use(1, *bob);
	cout << *me << endl;
	cout << *bob << endl;
	delete bob;
	delete me;
	delete src;
	delete ice;
	delete cure;
}

int	main()
{
	creation_materia();
	creation_materia_source();
	subject_test();
	return (0);
}
