/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/31 19:09:23 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __SHRUBBERY_HPP__
# define __SHRUBBERY_HPP__

# include "Form.hpp"
# include <string>
# include <iostream>
# include <exception>

using	std::string;
using	std::ostream;
using	std::exception;
 
class Bureaucrat;

// ************************************************************************** //
//                         ShrubberyCreationForm Class                        //
// ************************************************************************** //

class ShrubberyCreationForm : public Form
{
# define Shrubbery ShrubberyCreationForm
	private:
		unsigned int static	_nb;

	public:

		Shrubbery(void);
		Shrubbery(string const &target);
		Shrubbery(Shrubbery const &form);
		~Shrubbery(void);

		Shrubbery	&operator=(Shrubbery const &form);

		void	execute(Bureaucrat const &executor) const;
/*		friend ostream	&operator<<(ostream &os, Shrubbery const &form);

		string const	&getName(void) const;
		bool		isSigned(void) const;
		unsigned int	getGradeSign(void) const;
		unsigned int	getGradeExec(void) const;
		void		beSigned(Bureaucrat const &brcrat);

	class GradeTooHighException : public exception
	{
		public:
			char const	*what() const throw();
	};

	class GradeTooLowException : public exception
	{
		public:
			char const	*what() const throw();
	};*/
};

#endif /* __SHRUBBERY_HPP__ */
