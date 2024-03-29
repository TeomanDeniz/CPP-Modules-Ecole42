/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "Dog.hpp" /*
#  class Dog;
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
Dog::Dog(void)
	: Animal("Dog")
{
	cout << this->_type << " constructor called." << endl;
}

Dog::Dog(const Dog &src)
{
	cout << "Dog copy constructor called." << endl;
	*this = src;
}
/* ************************** [^] CONSTRUCTOR [^] *************************** */

/* *************************** [v] DESTRUCTOR [v] *************************** */
Dog::~Dog(void)
{
	cout << this->_type << " destructor called." << endl;
}
/* *************************** [^] DESTRUCTOR [^] *************************** */

/* **************************** [v] OPERATOR [v] **************************** */
Dog
	&Dog::operator = (const Dog &rhs) /* OPERATOR "=" */
{
	(void)rhs;
	cout << "Dog assignment operator called." << endl;
	return (*this);
}
/* **************************** [^] OPERATOR [^] **************************** */

void
	Dog::makeSound(void) const
{
	cout << "Woof!" << endl;
}
