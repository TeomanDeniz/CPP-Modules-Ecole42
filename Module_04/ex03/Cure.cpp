/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "Cure.hpp" /*
#  class Cure;
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
Cure::Cure(void)
	: AMateria("cure")
{
	(void)0;
	// cout << "* Cure: materia is created *" << endl;
}

Cure::Cure(Cure const &src)
	: AMateria("cure")
{
	*this = src;
	// cout << "* Cure: materia is copied *" << endl;
}
/* ************************** [^] CONSTRUCTOR [^] *************************** */

/* *************************** [v] DESTRUCTOR [v] *************************** */
Cure::~Cure(void)
{
	(void)0;
	// cout << "* Ice: cure is destroyed *" << endl;
}
/* *************************** [^] DESTRUCTOR [^] *************************** */

/* **************************** [v] OPERATOR [v] **************************** */
Cure
	&Cure::operator = (const Cure &rhs) /* OPERATOR "=" */
{
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}
/* **************************** [^] OPERATOR [^] **************************** */

AMateria
	*Cure::clone(void) const
{
	return (new Cure(*this));
}

void
	Cure::use(ICharacter &target)
{
	cout << "* heals " << target.getName() << "'s wounds *" << endl;
}
