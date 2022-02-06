/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SwapMinMax.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/02/04 08:12:05 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __SWAPMINMAX_HPP__
# define __SWAPMINMAX_HPP__

template <typename T>
void	swap(T &a, T &b)
{
        T	tmp(a);
        a = b;
        b = tmp;
}

template <typename T>
T	&min(T &a, T &b)
{
        if (a < b)
                return (a);
        return (b);
}

template <typename T>
T	&max(T &a, T &b)
{
        if (a > b)
                return (a);
        return (b);
}

#endif /* __SWAPMINMAX_HPP__ */
