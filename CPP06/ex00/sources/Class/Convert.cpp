/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/02/01 16:14:22 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"
#include "Form.hpp"
#include <string>
#include <iostream>

using	std::string;
using	std::cout;
using	std::cerr;
using	std::endl;
using	std::ostream;

/*************   PRIVATE   *************/ 

bool	Convert::isWhitespace(char c)
{
	if (c == '\n' || c == '\r' || c == '\v' || c == '\f' || c == '\t' || c == ' ')
		return (true);
	return (false);
}

bool	Convert::isNumeric(char c)
{
	if (c < '0' || c > '9')
		return (false);
	return (true);
}

int		Convert::countWhitespace(bool reverse)
{
	int	i = 0;
	int	size = _arg.length();
	if (reverse)
	{	
		i = size - 1;
		while (i >= 0 && isWhitespace(_arg[i]))
		{
			i--;
		}
		return (size - 1 - i);
	}
	while (i < size && isWhitespace(_arg[i]))
	{
		i++;
	}
	return (i);
}

void	Convert::trim()
{
	int		i = 0;
	int		len = countWhitespace(false);
	if (len > 0)
		_arg.erase(0, len);
	len = countWhitespace(true);
	i = _arg.length() - len;
	if (len > 0)
		_arg.erase(i, len);
}

bool	Convert::isValidNumeric(void) const
{
	int		i = 0;
	bool	dot_reached = false;

	if (_arg[i] == '-' || _arg[i] == '+')
		i++;
	while (_arg[i])
	{
		if (!isNumeric(_arg[i]))
		{
			if (_arg[i] == 'f' && _arg[i] == '\0')
				return (FLOAT);
			return (false);
		
		}
		if (dot_reached && _arg[i] == '.')
			return (false);
		if ()
	}
}

bool	Convert::isChar(void) const
{
	if (_arg[0] && _arg[1] == '\0')
		return (true);
	return (false);
}

bool	Convert::isInt(void) const
{
	int	size = 0;

	for (int i = 0, max = _arg.length(); i < max; i++)
	{
		

	}
}

/*************   PUBLIC   *************/ 

Convert::Convert() : _arg(""), _char('\0'), _int(0), _float(0), _double(0)
{
}

Convert::Convert(char const *str) : _arg(str), _char('\0'), _int(0), _float(0), _double(0)
{
	if (isChar())
		saveAsChar();
	trim();
	if (isValidNumeric())
	if (isInt())
	else if (isFloat())
	else if (isDouble())
	
}

Convert::Convert(Convert const &convert) : _arg(convert._arg)
{
	operator=(convert);
}

Convert::~Convert()
{
	cout << "<<Convert>><" << _name << "> destructor called" << endl;
}

Convert	&Convert::operator=(Convert const &convert)
{
	if (this != &convert)
	{
		_char = convert._char;
		_int = convert._int;
		_float = convert._float;
		_double = convert._double;
	}
	return (*this);
}

ostream		&operator<<(ostream &os, Convert const &cra)
{
	os << "char: " << _char 
	<< "\nint: " << _int
	<< "\nfloat: " << _float
	<< "\ndouble: " << _double << endl;
	return (os);
}