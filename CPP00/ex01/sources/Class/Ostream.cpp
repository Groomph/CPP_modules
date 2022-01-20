/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ostream.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 15:53:09 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/16 16:52:56 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ostream>
#include "Contact.hpp"

using	std::ostream;

void	operator<<(ostream &os, Contact const &contact)
{
	contact.display(os);
}
