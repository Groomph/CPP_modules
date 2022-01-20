/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/18 11:02:55 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __FIXED_HPP__
#define __FIXED_HPP__

# include <string>

using	std::string;

// ************************************************************************** //
//                               Fixed Class                                 //
// ************************************************************************** //

class Fixed {
	private:
		int			_rawValue;
		int const static	_fraction_bits = 8;

	public:

		Fixed();
		Fixed(int nb);
		Fixed(double nb);
		Fixed(Fixed const &fixed);

		Fixed	&operator=(Fixed const &fixed);

		int	getRawBits(void) const;
		void	setRawBits(int const raw);

		~Fixed(void);
};

#endif /* __FIXED_HPP__ */
