/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorBrcrat.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/29 21:16:21 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __ERRORBRCRAT_HPP__
#define __ERRORBRCRAT_HPP__

#include <exception>

using	std::exception;
 
// ************************************************************************** //
//                              ErrorBrcrat Class                             //
// ************************************************************************** //

typedef enum
{
	UNDEF = 0,
	TOOHIGH,
	TOOLOW,
	MAX_ERROR
}	t_error;

class ErrorBrcrat : public exception
{
	private:
		int	_num;
	public:
		ErrorBrcrat(t_error num) throw();
		const char	*what(void) const throw();
};

#endif /* __ERRORBRCRAT_HPP__ */
