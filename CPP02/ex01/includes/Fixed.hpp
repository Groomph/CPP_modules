/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/18 14:10:58 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __FIXED_HPP__
#define __FIXED_HPP__

# include <string>
# include <iostream>

using	std::string;
using	std::ostream;

// ************************************************************************** //
//                               Fixed Class                                 //
// ************************************************************************** //

class Fixed {
	private:
		int			_rawValue;
		int const static	_fraction_bits = 8;
		int const static	_coef = 1 << _fraction_bits;

		void inline	_setPositive();
		void inline	_setNegative();
		bool		_isNegative() const;
		bool		_isInteger() const;
		void		_setFromInt(int nb);
		void		_setFromFloat(float nb);

	public:

		Fixed();
		Fixed(int nb);
		Fixed(float nb);
		Fixed(Fixed const &fixed);

		Fixed	&operator=(Fixed const &fixed);
		ostream	&display(ostream &os) const;

		float	toFloat(void) const;
		int	toInt(void) const;

		int	getRawBits(void) const;
		void	setRawBits(int const raw);

		~Fixed(void);
};

ostream &operator<<(ostream &os, Fixed const &fixed);

#endif /* __FIXED_HPP__ */
