/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "Animal.hpp" /*
#  class Animal;
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
Animal::Animal(void)
	: _type("Animel")
{
	cout << this->_type << " constructor called" << endl;
}

Animal::Animal(string type)
	: _type(type)
{
	cout << "Animal " << this->_type << " constructor called" << endl;
}

Animal::Animal(const Animal &src)
{
	cout << "Animal copy constructor called" << endl;
	*this = src;
}
/* ************************** [^] CONSTRUCTOR [^] *************************** */

/* *************************** [v] DESTRUCTOR [v] *************************** */
Animal::~Animal(void)
{
	cout << "Animal destructor called" << endl;
}
/* *************************** [^] DESTRUCTOR [^] *************************** */

/* **************************** [v] OPERATOR [v] **************************** */
Animal
	&Animal::operator = (const Animal &rhs) /* OPERATOR "=" */
{
	cout << "<Animal.cpp:35: Animal assignment operator called" << endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}
/* **************************** [^] OPERATOR [^] **************************** */

void
	Animal::makeSound(void) const
{
	cout << "Animal makeSound called" << endl;
}

string
	Animal::getType(void) const
{
	return (this->_type);
}
