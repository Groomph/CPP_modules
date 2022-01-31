/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/31 20:08:39 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __ROBOTOMY_HPP__
# define __ROBOTOMY_HPP__

# include "Form.hpp"
# include <string>
# include <iostream>
# include <exception>

using	std::string;
using	std::ostream;
using	std::exception;
 
class Bureaucrat;


// ************************************************************************** //
//                           RobotomyRequestForm Class                        //
// ************************************************************************** //

class RobotomyRequestForm : public Form
{
# define Robotomy RobotomyRequestForm
	private:
		unsigned int static	_nb;

	public:

		Robotomy(void);
		Robotomy(string const &target);
		Robotomy(Robotomy const &form);
		~Robotomy(void);

		Robotomy	&operator=(Robotomy const &form);

		void	execute(Bureaucrat const &executor) const;
/*		friend ostream	&operator<<(ostream &os, Robotomy const &form);

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

#endif /* __ROBOTOMY_HPP__ */
