/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ostream.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/16 16:51:30 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSTREAM_HPP
# define OSTREAM_HPP

# include <Contact.hpp>
# include <ostream>

using	std::ostream;

void	operator<<(ostream &os, Contact const &contact);

#endif
