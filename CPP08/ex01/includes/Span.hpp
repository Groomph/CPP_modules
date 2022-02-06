/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/02/06 13:42:50 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __SPAN_HPP__
#define __SPAN_HPP__

# include <iostream>
# include <vector>

using	std::string;
using	std::ostream;
using	std::vector;
using	std::exception;

// ************************************************************************** //
//                               Span Class                                 //
// ************************************************************************** //

#define DEFAULT_SIZE 10

typedef vector<int>::iterator	t_iterator;

class Span {
	private:
		unsigned int		_capacity;
		vector<int>		_array;

		static int	abs(int nb);
		ostream	&display(ostream &os) const;

	public:

		Span();
		Span(unsigned int nb);
		Span(Span const &span);
		~Span(void);

		Span		&operator=(Span const &fixed);
		friend ostream	&operator<<(ostream &os, Span const &fixed);

		void		addNumber(int tocopy);
		void		addNumber(t_iterator b, t_iterator e);
		int		shortestSpan(void) const;
		int		longestSpan(void) const;

	class NotEnoughIndexException : public exception
	{
		public:
			char const	*what(void) const throw();
	};

	class CapacityReachedException : public exception
	{
		public:
			char const	*what(void) const throw();
	};
};

#endif /* __SPAN_HPP__ */
