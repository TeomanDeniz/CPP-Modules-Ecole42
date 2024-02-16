/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedV2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "SedV2.hpp" /*
#  class SedV2;
#*/
#include <iostream> /*
#namespc std;
#*/
#include <string> /*
#  class std::string;
#istream &std::getline(istream &, string &);
#*/
#include <cstdlib> /*
# define EXIT_FAILURE;
#*/
#include <fstream> /*
#typedef ifstream;
#*/
#include <fstream> /*
#typedef ofstream;
#*/
#include <cstddef> /*
#typedef std::size_t;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USING [v] ****************************** */
using std::cerr;
using std::string;
using std::endl;
/* ***************************** [^] USING [^] ****************************** */

SedV2::SedV2(string filename) /* CONSTRUCTOR */ \
	: _inFile(filename)
{
	this->_outFile = this->_inFile + ".replace";
}

SedV2::~SedV2(void) /* DESTRUCTOR */
{
	(void)0;
}

void
	SedV2::replace(string toFind, string replace)
{
	std::ifstream	ifs(this->_inFile);

	if (ifs.is_open())
	{
		string	content;

		if (std::getline(ifs, content, '\0'))
		{
			std::ofstream	ofs(this->_outFile);
			std::size_t		pos = content.find(toFind);

			while (pos != string::npos)
			{
				content.erase(pos, toFind.length());
				content.insert(pos, replace);
				pos = content.find(toFind);
			}
			ofs << content;
			ofs.close();
		}
		else
			cerr << "Empty file found." << endl;
		ifs.close();
	}
	else
	{
		cerr << "Unable to open the file." << endl;
		exit(EXIT_FAILURE);
	}
}
