/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/31 21:11:56 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <fstream>

using	std::string;
using	std::cout;
using	std::cerr;
using	std::endl;
using	std::ofstream;

/*************   PRIVATE   *************/ 

unsigned int	Shrubbery::_nb = 0;

string static const	g_target("target");
string static const	g_shrub("Shrubbery");
char static const	tree[] = "\n\
                                                         .\n\
                                              .         ;\n\
                 .              .              ;%     ;;\n\
                   ,           ,                :;%  %;\n\
                    :         ;                   :;%;'     .,\n\
           ,.        %;     %;            ;        %;'    ,;\n\
             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n\
              %;       %;%;      ,  ;       %;  ;%;   ,%;'\n\
               ;%;      %;        ;%;        % ;%;  ,%;'\n\
                `%;.     ;%;     %;'         `;%%;.%;'\n\
                 `:;%.    ;%%. %@;        %; ;@%;%'\n\
                    `:%;.  :;bd%;          %;@%;'\n\
                      `@%:.  :;%.         ;@@%;'\n\
                        `@%.  `;@%.      ;@@%;\n\
                          `@%%. `@%%    ;@@%;\n\
                            ;@%. :@%%  %@@%;\n\
                              %@bd%%%bd%%:;\n\
                                #@%%%%%:;;\n\
                                %@@%%%::;\n\
                                %@@@%(o);  . '\n\
                                %@@@o%;:(.,'\n\
                            `.. %@@@o%::;\n\
                               `)@@@o%::;\n\
                                %@@(o)::;\n\
                               .%@@@@%::;\n\
                               ;%@@@@%::;.\n\
                              ;%@@@@%%:;;;.\n\
                          ...;%@@@@@%%:;;;;,..";

/*************   PUBLIC   *************/

Shrubbery::Shrubbery() : Form(g_shrub + Shrubbery::_nb, 145, 137)
{
	_target = g_target + Shrubbery::_nb;
	Shrubbery::_nb++;
}

Shrubbery::Shrubbery(string const &target) :
			Form(g_shrub + Shrubbery::_nb, 145, 137)
{
	_target = target;
	Shrubbery::_nb++;
}

Shrubbery::Shrubbery(Shrubbery const &form) :
					Form(form)
{
	Form::operator=(form);
}

Shrubbery	&Shrubbery::operator=(Shrubbery const &form)
{
	if (this != &form)
	{
		Form::operator=(form);
	}
	return (*this);
}

void	Shrubbery::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > getGradeExec())
		throw (GradeTooLowException());
	if (!isSigned())
		throw (FormNotSignedException());
	ofstream	file(string(_target + "_shrubbery").c_str());
	if (file)
		file << tree;
	else
		cerr << "ERROR: open file failed" << endl;
}

Shrubbery::~Shrubbery()
{
	Shrubbery::_nb--;
	cout << "<<Shrubbery>><" << getName() << "> destructor called" << endl;
}
