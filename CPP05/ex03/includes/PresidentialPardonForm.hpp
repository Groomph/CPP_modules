/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/31 20:27:56 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __PRESIDENTIAL_HPP__
# define __PRESIDENTIAL_HPP__

# include "Form.hpp"
# include <string>
# include <iostream>
# include <exception>

using	std::string;
using	std::ostream;
using	std::exception;
 
class Bureaucrat;


// ************************************************************************** //
//                          PresidentialPardonForm Class                      //
// ************************************************************************** //

class PresidentialPardonForm : public Form
{
# define Presidential PresidentialPardonForm
	private:
		unsigned int static	_nb;

	public:

		Presidential(void);
		Presidential(string const &target);
		Presidential(Presidential const &form);
		~Presidential(void);

		Presidential	&operator=(Presidential const &form);

		void	execute(Bureaucrat const &executor) const;
/*		friend ostream	&operator<<(ostream &os, Presidential const &form);

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

#endif /* __PRESIDENTIAL_HPP__ */
