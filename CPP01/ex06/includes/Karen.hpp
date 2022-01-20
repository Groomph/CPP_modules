/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/17 22:20:20 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __KAREN_HPP__
#define __KAREN_HPP__

# include <string>

using	std::string;


// ************************************************************************** //
//                               Karen Class                                 //
// ************************************************************************** //

class Karen {
	typedef	void	(Karen::*karen_t)(void);

	private:
		const karen_t	*_f;
		void		debug(void);
		void		info(void);
		void		warning(void);
		void		error(void);
		void		_default(void);

	public:
		Karen(void);
		void	complain(string level);
};

#endif /* __KAREN_HPP__ */
