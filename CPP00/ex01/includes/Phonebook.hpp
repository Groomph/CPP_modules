/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/16 16:50:41 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <string>

using	std::string;

class	Phonebook
{
	private:
		int		_contacts_index;
		Contact 	_contacts[8];
		string		_format_contacts[8];
		string const	_prompt_display;
		string const	_empty_list;

		void	get_input(string const &prompt, string &input) const;
		void	get_line(string const &prompt, string &input) const;
		void	formatting_contact(string &str) const;
	public:
		Phonebook();
		void	add_contact(void);
		bool	display_all(void) const;
		void	display_one(int index) const;
		~Phonebook();
};
#endif
