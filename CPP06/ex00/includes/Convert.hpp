/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/02/01 16:10:48 by rsanchez         ###   ########.fr       */
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
	CHAR = 0,
	INT,
	FLOAT,
	DOUBLE,
	UNDEFINED
}

class Convert
{
	private:
		string			_arg;
		char			_char;
		int				_int;
		float			_float;
		double			_double;
		

		static bool	isWhitespace(char c);
		static bool	isNumeric(char c);
		int			countWhitespace(bool reverse);
		void		trim(void);
		bool		isValidNumeric(void) const;
		bool		isChar(void) const;
		bool		isInt(void) const;
	public:

		Convert(void);
		Convert(Convert const &convert);
		Convert(char const *str);
		~Convert(void);

		Convert	&operator=(Convert const &convert);
		friend ostream	&operator<<(ostream &os, Convert const &convert);

};

#endif /* __CONVERT_HPP__ */
