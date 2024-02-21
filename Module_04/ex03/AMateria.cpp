/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "AMateria.hpp" /*
#  class AMateria;
#*/
#include "ICharacter.hpp" /*
#  class ICharacter;
#*/
#include <iostream> /*
#namespc std;
#*/
#include <string> /*
#  class std::string;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USING [v] ****************************** */
using std::string;
using std::cout;
using std::endl;
/* ***************************** [^] USING [^] ****************************** */

/* ************************** [v] CONSTRUCTOR [v] *************************** */
AMateria::AMateria(void)
	: _type("")
{
	(void)0;
	// cout << "* AMateria: materia is created *" << endl;
}

AMateria::AMateria(string const &type)
	: _type(type)
{
	cout << "AMateria " << this->_type << " created" << endl;
}

AMateria::AMateria(AMateria const &src)
{
	*this = src;
}
/* ************************** [^] CONSTRUCTOR [^] *************************** */

/* *************************** [v] DESTRUCTOR [v] *************************** */
AMateria::~AMateria(void)
{
	cout << "AMateria " << this->_type << " destroyed" << endl;
}
/* *************************** [^] DESTRUCTOR [^] *************************** */

string const
	&AMateria::getType(void) const
{
	return (this->_type);
}

AMateria
	*AMateria::clone(void) const
{
	return ((AMateria *)this);
}

void
	AMateria::use(ICharacter &target)
{
	cout << "AMateria " << this->_type << " used on ";
	cout << target.getName() << endl;
}
