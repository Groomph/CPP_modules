/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorBrcrat.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/29 21:32:05 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ErrorBrcrat.hpp"

/*************   PRIVATE   *************/ 

/*************   PUBLIC   *************/ 

ErrorBrcrat::ErrorBrcrat(t_error num) throw() :  _num(num)
{
}

char const	*ErrorBrcrat::what() const throw()
{
	static const char	*arr[MAX_ERROR] =
	{
		"Bureaucrat::UndefinedError",
		"Bureaucrat::GradeTooHighException",
		"Bureaucrat::GradeTooLowException"
	};

	return (arr[_num]);
}
