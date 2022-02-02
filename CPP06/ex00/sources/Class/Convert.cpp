/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/02/02 23:00:37 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cerrno>
#include <climits>

using	std::string;
using	std::cout;
using	std::endl;
using	std::setprecision;
using	std::fixed;
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

t_type		Convert::getFloatError() const
{
	t_type	type(UNDEFINED);

	if (_arg.length() < 3)
		return (UNDEFINED);
	if (_arg.find("inf", 0, 3) == 0)
		type = INF;
	else if (_arg.find("INF", 0, 3) == 0)
		type = INF;
	else if (_arg.find("Inf", 0, 3) == 0)
		type = INF;
	else if (_arg.find("nan", 0, 3) == 0)
		type = NAN;
	else if (_arg.find("NAN", 0, 3) == 0)
		type = NAN;
	else if (_arg.find("NaN", 0, 3) == 0)
		type = NAN;
	if (_arg[3] == 'f' && _arg[4] == '\0' && type != UNDEFINED)
		type |= FLOAT;
	else if (_arg[3])
		return (UNDEFINED);
	return (type);
}

int		Convert::countWhitespace(bool reverse) const
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
	while (_arg[0] == '-' || _arg[0] == '+')
	{
		if (_arg[0] == '-')
			_type ^= NEGATIVE;
		_arg.erase(0, 1);
	}
}

t_type	Convert::getNumericType(void) const
{
	int		i;
	t_type		float_error;
	bool	dot_reached = false;

	float_error = getFloatError();
	if (float_error != UNDEFINED)
		return (float_error);
	for (i = 0; _arg[i]; i++)
	{
		if (_arg[i] == '.')
		{
			if (dot_reached)
				return (UNDEFINED);
			else
				dot_reached = true;
		}
		else if (!isNumeric(_arg[i]))
		{
			if (_arg[i] == 'f' && _arg[i + 1] == '\0')
				return (FLOAT);
			return (UNDEFINED);
		}
	}
	if (dot_reached)// || i > 9)
		return (DOUBLE);
	return (INT);
}

bool	Convert::isChar(void) const
{
	size_t	size = _arg.length();

	if (!(_arg[0] & (1U << 7)) && _arg[1] == '\0')
		return (true);
	else if (_arg[0] & (1U << 7))
	{
		if (_arg[0] & (1U << 4) && size == 4)
			return (true);
		if (_arg[0] & (1U << 5) && size == 3)
			return (true);
		if (_arg[0] & (1U << 6) && size == 2)
			return (true);
	}
	return (false);
}

/*************   PUBLIC   *************/ 

Convert::Convert() : _arg(""), _type(UNDEFINED)
{
}

Convert::Convert(char const *str) : _arg(str), _type(0)
{
	t_type	num_type;

	if (_arg[0] == '\0')
	{
		_type = UNDEFINED;
		return ;
	}
	if (isChar())
	{
		_type = CHAR;
		return ;
	}
	trim();
	num_type = getNumericType();
	if (num_type == UNDEFINED)
		_type = UNDEFINED;
	else
		_type |= num_type;
}

Convert::Convert(Convert const &convert)
{
	operator=(convert);
}

Convert::~Convert()
{
}

Convert	&Convert::operator=(Convert const &convert)
{
	if (this != &convert)
	{
		_arg = convert._arg;
		_type = convert._type;
	}
	return (*this);
}

ostream		&operator<<(ostream &os, Convert const &convert)
{
	return (convert.print(os));
}

Convert::t_print const Convert::_print[] =
{
	&Convert::printUndef,
	&Convert::printChar,
	&Convert::printInt,
	&Convert::printNan,
	&Convert::printInf,
	&Convert::printFloat,
	&Convert::printDouble,
	NULL
};

ostream		&Convert::print(ostream &os) const
{
	for (int i = 0; _print[i]; i++)
	{
		if (_type & (1U << i))
		{
			return ((this->*_print[i])(os));
		}
	}
	return (os);
}

ostream		&Convert::printUndef(ostream &os) const
{
	os << "char: undefined\n"
		<< "int: undefined\nfloat: undefined\ndouble: undefined"; 
	return (os);
}

ostream		&Convert::printNan(ostream &os) const
{
	os << "char: impossible\nint: impossible\n";
	if (_type & NEGATIVE)
		os << "float: -NaNf\ndouble: -NaN";
	else
		os << "float: NaNf\ndouble: NaN";
	return (os);
}

ostream		&Convert::printInf(ostream &os) const
{
	os << "char: impossible\nint: impossible\n";
	if (_type & NEGATIVE)
		os << "float: -inff\ndouble: -inf";
	else
		os << "float: inff\ndouble: inf";
	return (os);
}

ostream		&Convert::printChar(ostream &os) const
{
	unsigned int	tmp = 0;

	if (_arg[1])
	{
		os << "char: '" << _arg << "'\n";
		for (int i = 0, i2; _arg[i]; i++)
		{
			for (i2 = 0; i2 < 8; i2++)
				tmp |= _arg[i] << i2;
		}
		os << "int: " << (tmp) << '\n';
		os << "float: " << static_cast<float>(tmp) << ".0f\n";
		os << "double: " << static_cast<double>(tmp) << ".0";
		return (os);
	}
	if (_arg[0]< 32 || _arg[0] == 127)
		os << "char: Non displayable\n";
	else if (_arg[0] > 127)
		os << "char: impossible\n";
	else
		os << "char: '" << _arg[0] << "'\n";
	os << "int: " << static_cast<int>(_arg[0]) << '\n';
	os << "float: " << static_cast<float>(_arg[0]) << ".0f\n";
	os << "double: " << static_cast<double>(_arg[0]) << ".0";
	return (os);
}

ostream		&Convert::printInt(ostream &os) const
{
	int		int_nb;
	long int	nb = strtol(_arg.c_str(), NULL, 10);

	if (errno == ERANGE || nb - 1 > INT_MAX
			|| (nb > INT_MAX && !(_type & NEGATIVE)))
	{
		os << "char: impossible\nint: overflow\n"
			<< "float: <int>overflowed\ndouble: <int>overflowed"; 
		return (os);
	}
	if (_type & NEGATIVE)
		nb = -nb;
	int_nb = static_cast<int>(nb);
	if (int_nb < 32 || int_nb == 127)
		os << "char: Non displayable\n";
	else if (int_nb > 127)
		os << "char: impossible\n";
	else
		os << "char: '" << static_cast<char>(int_nb) << "'\n";
	os << "int: " << int_nb << '\n';
	os << "float: " << static_cast<float>(int_nb) << ".0f\n";
	os << "double: " << static_cast<double>(int_nb) << ".0";
	return (os);
}

ostream		&Convert::printFloat(ostream &os) const
{
	float	nb = strtof(_arg.c_str(), NULL);

	if (errno == ERANGE)
	{
		os << "char: impossible\nint: <float>overflowed\n"
			<< "float: overflow\ndouble: <float>overflowed"; 
		return (os);
	}
	if (_type & NEGATIVE)
		nb = -nb;
	if (static_cast<int>(nb) < 32 || static_cast<int>(nb) == 127)
		os << "char: Non displayable\n";
	else if (nb > 127)
		os << "char: impossible\n";
	else
		os << "char: '" << static_cast<char>(nb) << "'\n";
	if (nb > 2147483647.0f || nb < -2147483648.0f)
		os << "int: impossible\n";
	else
		os << "int: " << static_cast<int>(nb) << '\n';
	os << "float: " << nb;
	if (nb == static_cast<int>(nb))
		os << ".0f\ndouble: " << nb << ".0";
	else
		os << "f\ndouble: " << static_cast<double>(nb);
	return (os);
}

ostream		&Convert::printDouble(ostream &os) const
{
	float	nb = strtod(_arg.c_str(), NULL);

	if (errno == ERANGE)
	{
		os << "char: impossible\nint: <double>overflowed\n"
			<< "float: <double>overflowed\ndouble: overflow"; 
		return (os);
	}
	if (_type & NEGATIVE)
		nb = -nb;
	if (static_cast<int>(nb) < 32 || static_cast<int>(nb) == 127)
		os << "char: Non displayable\n";
	else if (nb > 127)
		os << "char: impossible\n";
	else
		os << "char: '" << static_cast<char>(nb) << "'\n";
	if (nb > 2147483647.0 || nb < -2147483648.0)
		os << "int: impossible\n";
	else
		os << "int: " << static_cast<int>(nb) << '\n';
	os << "float: " << static_cast<float>(nb);
	if (nb == static_cast<int>(nb))
		os << ".0f\ndouble: " << static_cast<double>(nb) << ".0";
	else
		os << "f\ndouble: " << static_cast<double>(nb);
	return (os);
}
