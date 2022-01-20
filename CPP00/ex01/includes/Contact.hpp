/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/16 16:51:12 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <ostream>

using	std::string;
using	std::ostream;

class	Contact
{
	private:
		string	_first_name;
		string	_last_name;
		string	_nickname;
		string	_phone_number;
		string	_darkest_secret;

	public:
		Contact(string const &first = "", string const &last = "",
			string const &nick = "", string const &number = "",
			string const &secret = "");
		void	set_first_name(string const &str);
		void	set_last_name(string const &str);
		void	set_nickname(string const &str);
		void	set_phone_number(string const &str);
		void	set_darkest_secret(string const &str);
		void	display_first_name(void) const;
		void	display_last_name(void) const;
		void	display_nickname(void) const;
		void	display_phone_number(void) const;
		void	display_darkest_secret(void) const;
		void	display(ostream &os) const;
		~Contact(void);
};
#endif
