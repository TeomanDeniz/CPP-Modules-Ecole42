/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "Ice.hpp" /*
#  class Ice;
#*/
#include "ICharacter.hpp" /*
#  class ICharacter;
#*/
#include <iostream> /*
#namespc std;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USING [v] ****************************** */
using std::cout;
using std::endl;
/* ***************************** [^] USING [^] ****************************** */

/* ************************** [v] CONSTRUCTOR [v] *************************** */
Ice::Ice(void)
	: AMateria("ice")
{
	(void)0;
	// cout << "* Ice: materia is created *" << endl;
}

Ice::Ice(Ice const &src)
	: AMateria("ice")
{
	*this = src;
	// cout << "* Ice: materia is copied *" << endl;
}
/* ************************** [^] CONSTRUCTOR [^] *************************** */

/* *************************** [v] DESTRUCTOR [v] *************************** */
Ice::~Ice(void)
{
	(void)0;
	// cout << "* Ice: ice is destroyed *" << endl;
}
/* *************************** [^] DESTRUCTOR [^] *************************** */

/* **************************** [v] OPERATOR [v] **************************** */
Ice
	&Ice::operator = (const Ice &rhs) /* OPERATOR "=" */
{
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}
/* **************************** [^] OPERATOR [^] **************************** */

AMateria
	*Ice::clone(void) const
{
	return (new Ice(*this));
}

void
	Ice::use(ICharacter &target)
{
	cout << "I shoots an ice bolt at " << target.getName() << endl;
}
