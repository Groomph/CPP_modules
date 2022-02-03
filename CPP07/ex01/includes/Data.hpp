/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/02/03 20:57:03 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __DATA_HPP__
# define __DATA_HPP__

# include <string>
# include <iostream>
# include <exception>

using	std::string;
using	std::ostream;
using	std::exception;
 
// ************************************************************************** //
//                                  Data Class                                //
// ************************************************************************** //

struct Data
{
		Data(void);
		Data(Data const &data);
		~Data(void);

		Data	&operator=(Data const &data);
		friend ostream	&operator<<(ostream &os, Data const &data);

	private:
		int static	_count;
		int		_id;

		void	display(ostream &os) const;
};

#endif /* __DATA_HPP__ */
