/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/02/02 22:54:40 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __CONVERT_HPP__
# define __CONVERT_HPP__

# include <string>
# include <iostream>
# include <exception>

using	std::string;
using	std::ostream;
using	std::exception;
 
// ************************************************************************** //
//                                Convert Class                               //
// ************************************************************************** //

enum	e_type
{
	UNDEFINED = (1U << 0),
	CHAR = (1U << 1),
	INT = (1U << 2),
	NAN = (1U << 3),
	INF = (1U << 4),
	FLOAT = (1U << 5),
	DOUBLE = (1U << 6),
	NEGATIVE = (1U << 7)
};

typedef char t_type;

class Convert
{
	typedef ostream &(Convert::*t_print)(ostream &) const;

	private:
		string			_arg;
		t_type			_type;

		static bool	isWhitespace(char c);
		static bool	isNumeric(char c);
		t_type		getFloatError(void) const;
		int			countWhitespace(bool reverse) const;
		void		trim(void);
		t_type		getNumericType(void) const;
		bool		isChar(void) const;

		t_print static const	_print[];
		ostream	&print(ostream &os) const;
		ostream	&printUndef(ostream &os) const;
		ostream	&printNan(ostream &os) const;
		ostream	&printInf(ostream &os) const;
		ostream	&printChar(ostream &os) const;
		ostream	&printInt(ostream &os) const;
		ostream	&printFloat(ostream &os) const;
		ostream	&printDouble(ostream &os) const;
	public:

		Convert(void);
		Convert(Convert const &convert);
		Convert(char const *str);
		~Convert(void);

		Convert	&operator=(Convert const &convert);
		friend ostream	&operator<<(ostream &os, Convert const &conver);

};

#endif /* __CONVERT_HPP__ */
