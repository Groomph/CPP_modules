/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/02/05 19:30:16 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __EASYFIND_HPP__
#define __EASYFIND_HPP__

# include <iostream>
# include <exception>
# include <vector>
# include <algorithm>

using	std::cout;
using	std::endl;
using	std::exception;
using	std::iterator;

// ************************************************************************** //
//                               Exception Class                              //
// ************************************************************************** //

template <typename T>
class NoOccurenceFoundException : public exception
{
		void	skipNorme(T const &t)	{(void)t;}
	public:
		char const	*what(void) const throw()
		{
			return ("NoOccurenceFoundException");
		}
};

template <typename T>
typename T::const_iterator	easyfind(T const &t, int nb)
{
	return (find(t.begin(), t.end(), nb));
}

//This function above was enough, but I wanted to practice
template <typename T>
typename T::iterator	easyfind(T &t, int nb)
{
	typename T::iterator it = t.begin();
	for (typename T::iterator it2 = t.end(); it != it2; it++)
	{
		if (nb == *it)
		{
			cout << "Occurence of " << nb << " was found at index "
				<< it - t.begin() << endl;
			return (it);
		}
	}
	throw (NoOccurenceFoundException<int>());
	return (it);
}

#endif /* __EASYFIND_HPP__ */
