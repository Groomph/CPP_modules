/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/02/06 16:09:27 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __MUTANTSTACK_HPP__
# define __MUTANTSTACK_HPP__

# include <iostream>
# include <exception>
# include <stack>

using	std::string;
using	std::ostream;
using	std::exception;
using	std::stack;

// ************************************************************************** //
//                              MutantStack Class                              //
// ************************************************************************** //

template<typename T>
class MutantStack : public stack<T>
{
	protected:
		typedef typename stack<T>::container_type	container_type;

	public:
		typedef typename container_type::iterator	iterator;
		typedef typename container_type::const_iterator	const_iterator;

	private:
		typedef iterator	t_it;
		typedef const_iterator	t_cit;

		ostream &display(ostream &os) const
		{
			for (t_it it = begin(), it2 = end(); it != it2; it++)
			{
				os << *it << ' ';
			}
			return (os);
		}

	public:
		MutantStack(void) : stack<T>()
		{
		}

		MutantStack(unsigned int nb) : stack<T>(nb)
		{
		}

		MutantStack(MutantStack const &mstack) : stack<T>(mstack)
		{
		}

		~MutantStack()
		{
		}

		MutantStack   &operator=(MutantStack const &mstack)
		{
			if (this != &mstack)
			{
				stack<T>::operator=(mstack);
			}
			return (*this);
		}

		friend ostream &operator<<(ostream &os, MutantStack const &mst)
		{
			mst.display(os);
			return (os);
		}

		t_it		begin()
		{
			return (this->c.begin());
		}

		t_it		end()
		{
			return (this->c.end());
		}
};

#endif /* __MUTANTSTACK_HPP__ */
