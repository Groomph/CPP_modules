/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:24:18 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/18 16:00:37 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <ios>
#include <fstream>

using	std::cout;
using	std::endl;
using	std::string;
using	std::ifstream;
using	std::ofstream;

static void	replace(string &total, string &s1, string &s2)
{
	size_t	stop;
	size_t	len(s1.size());

	do
	{
		stop = total.rfind(s1, stop);
		if (stop != string::npos)
		{
			total.erase(stop, len);
			total.insert(stop, s2);
		}
	}
	while (stop != string::npos);
}

static void	read_infile(ifstream &infile, ofstream &outfile, char **av)
{
	string		s1(av[2]);
	string		s2(av[3]);
	char		buffer[1000];
	string		total;

	do
	{
		infile.getline(buffer, 1000);
		total += buffer;
		if (!infile.eof())
			total += '\n';
	} while (!infile.eof());
	replace(total, s1, s2);
	outfile << total;
	infile.close();
	outfile.close();
}

static void	build_out_name(string &filename)
{
	size_t	last(filename.rfind("/"));

	if (last != string::npos)
		filename.erase(0, last + 1);
	filename.insert(filename.size(), ".replace");
}

static int	return_error(int i)
{

	switch (i)
	{
		case 0:
			cout << "Wrong number of arguments" << endl;
			break;
		case 1:
			cout << "Empty arguments are not accepted" << endl;
			break;
		case 2:
			cout << "Unable to open infile" << endl;
			break;
		case 3:
			cout << "Unable to open outfile" << endl;
			break;
	}
	return (1);
}

int	main(int ac, char **av)
{
	if (ac != 4)
		return (return_error(0));
	if (av[1][0] == '\0' || av[2][0] == '\0' || av[3][0] == '\0')
		return (return_error(1));

	string		filename(av[1]);

	build_out_name(filename);
	ofstream	outfile(filename.c_str());
	if (!outfile.is_open())
		return (return_error(3));
	ifstream	infile(av[1]);
	if (!infile.is_open())
		return (return_error(2));

	read_infile(infile, outfile, av);
	return (0);
}
