/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/26 12:37:08 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <string>
#include <iostream>

using	std::string;
using	std::cout;
using	std::endl;
using	std::ostream;

/*************   PRIVATE   *************/ 

void	Brain::setIdeas(string const ideas[])
{
	for (int i = 0; i < MAX_IDEAS; i++)
		_ideas[i] = ideas[i];
}

/*************   PUBLIC   *************/ 

Brain::Brain()
{
	cout << "<Brain> default constructor called" << endl;
}

Brain::Brain(string const ideas[])
{
	cout << "<Brain> ideas constructor called" << endl;
	setIdeas(ideas);
}

Brain::Brain(Brain const &brain)
{
	cout << "<Brain> copy constructor called" << endl;
	operator=(brain);
}

Brain	&Brain::operator=(Brain const &brain)
{
	cout << "<Brain> = operator called" << endl;
	if (this != &brain)
	{
		setIdeas(brain._ideas);
		if (&_ideas == &(brain._ideas)
				|| &(_ideas[0]) == &(brain._ideas[0]))
			cout << "Copy of brain was not deep" << endl;
	}
	return (*this);
}

ostream &Brain::display(ostream &os) const
{
	int	i = 0;
	bool	have_idea = false;

	os << "<Brain>\n";
	while (i < MAX_IDEAS)
	{
		if (_ideas[i] != "")
		{
			os << "idea " << i << ": " << _ideas[i] << endl;
			have_idea = true;
		}
		i++;
	}
	if (!have_idea)
		os << "No idea here" << endl;
	return (os);
}

void	Brain::setIdea(int i, string const &idea)
{
	if (i < 100)
		_ideas[i] = idea;
}

string const	&Brain::getIdea(int i) const
{
	string static const	empty("");
	if (i > 99)
		return (empty);
	return (_ideas[i]);
}

ostream &operator<<(ostream &left, Brain const &right)
{
	return (right.display(left));
}

Brain::~Brain()
{
	cout << "<Brain> destructor called" << endl;
}
