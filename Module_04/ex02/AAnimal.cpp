/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "AAnimal.hpp" /*
#  class AAnimal;
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
AAnimal::AAnimal(void)
	: _type("AAnimel")
{
	cout << this->_type << " constructor called" << endl;
}

AAnimal::AAnimal(string type)
	: _type(type)
{
	cout << "AAnimal " << this->_type << " constructor called" << endl;
}

AAnimal::AAnimal(const AAnimal &src)
{
	cout << "AAnimal copy constructor called" << endl;
	*this = src;
}
/* ************************** [^] CONSTRUCTOR [^] *************************** */

/* *************************** [v] DESTRUCTOR [v] *************************** */
AAnimal::~AAnimal(void)
{
	cout << "Animal destructor called" << endl;
}
/* *************************** [^] DESTRUCTOR [^] *************************** */

/* **************************** [v] OPERATOR [v] **************************** */
AAnimal
	&AAnimal::operator = (const AAnimal& rhs) /* OPERATOR "=" */
{
	cout << "<AAnimal.cpp:35: AAnimal assignment operator called" << endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}
/* **************************** [^] OPERATOR [^] **************************** */

void
	AAnimal::makeSound(void) const
{
	cout << "AAnimal makeSound called" << endl;
}

string
	AAnimal::getType(void) const
{
	return (this->_type);
}
