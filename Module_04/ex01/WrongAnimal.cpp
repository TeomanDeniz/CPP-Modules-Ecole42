/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "WrongAnimal.hpp" /*
#  class WrongAnimal;
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
WrongAnimal::WrongAnimal(void)
	: _type("WrongAnimel")
{
	cout << this->_type << " constructor called" << endl;
}

WrongAnimal::WrongAnimal(string type)
	: _type(type)
{
	cout << "WrongAnimal " << this->_type << " constructor called" << endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	cout << "WrongAnimal copy constructor called" << endl;
	*this = src;
}
/* ************************** [^] CONSTRUCTOR [^] *************************** */

/* *************************** [v] DESTRUCTOR [v] *************************** */
WrongAnimal::~WrongAnimal(void)
{
	cout << "WrongAnimal destructor called" << endl;
}
/* *************************** [^] DESTRUCTOR [^] *************************** */

/* **************************** [v] OPERATOR [v] **************************** */
WrongAnimal
	&WrongAnimal::operator = (const WrongAnimal &rhs) /* OPERATOR "=" */
{
	cout << "WrongAnimal assignment operator called" << endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}
/* **************************** [^] OPERATOR [^] **************************** */

void
	WrongAnimal::makeSound(void) const
{
	cout << "WrongAnimal makeSound called" << endl;
}

string
	WrongAnimal::getType(void) const
{
	return (this->_type);
}
