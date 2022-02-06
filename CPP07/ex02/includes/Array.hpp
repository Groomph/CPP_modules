/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/02/04 19:37:43 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __ARRAY_HPP__
# define __ARRAY_HPP__

# include <iostream>
# include <exception>

using	std::string;
using	std::ostream;
using	std::exception;

// ************************************************************************** //
//                              Array Class                              //
// ************************************************************************** //

template<typename T>
class Array
{
	private:
		unsigned int	_size;
		T		*_array;

		ostream &display(ostream &os) const
		{
			for (unsigned int i = 0; i < _size; i++)
			{
				os << _array[i] << ' ';
			}
			return (os);
		}

	public:

		Array(void) : _size(0), _array(NULL)
		{
		}

		Array(unsigned int nb) : _size(nb), _array(new T[nb])
		{
		}

		Array(Array const &array) : _size(0), _array(NULL)
		{
			operator=(array);
		}

		~Array()
		{
			delete[] _array;
		}

		Array   &operator=(Array const &array)
		{
			if (this != &array)
			{
				_size = array._size;
				if (_array)
					delete[] _array;
				_array = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
				{
					_array[i] = array._array[i];
				}
			}
			return (*this);
		}

		friend ostream &operator<<(ostream &os, Array const &array)
		{
			array.display(os);
			return (os);
		}

		T       &operator[](unsigned int index) const
		{
			if (index >= _size)
			{
				throw (IndexTooHighException());
			}
			else
			{
				return (_array[index]);
			}
		}

		unsigned int    size(void) const
		{
			return (_size);
		}

		class IndexTooHighException : public exception
		{
			public:
				char const	*what() const throw()
				{
					return ("IndexTooHighException");
				}
		};
};

#endif /* __ARRAY_HPP__ */
