/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/16 21:52:51 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__

# include <string>

using	std::string;

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Zombie {
	private:
		string	_name;

	public:

		Zombie(string const &name = "Croute");
		void	announce() const;
		~Zombie(void);
};

#endif /* __ZOMBIE_HPP__ */
