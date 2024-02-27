 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "Cat.hpp" /*
#  class Cat;
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
Cat::Cat(void)
	: Animal("Cat")
{
	cout << this->_type << " constructor called." << endl;
}

Cat::Cat(const Cat &src)
{
	cout << "Cat copy constructor called." << endl;
	*this = src;
}
/* ************************** [^] CONSTRUCTOR [^] *************************** */

/* *************************** [v] DESTRUCTOR [v] *************************** */
Cat::~Cat(void)
{
	cout << this->_type << " destructor called." << endl;
}
/* *************************** [^] DESTRUCTOR [^] *************************** */

/* **************************** [v] OPERATOR [v] **************************** */
Cat
	&Cat::operator = (const Cat &rhs) /* OPERATOR "=" */
{
	(void)rhs;
	cout << "Cat assignment operator called." << endl;
	return (*this);
}
/* **************************** [^] OPERATOR [^] **************************** */

void
	Cat::makeSound(void) const
{
	cout << "Meow!" << endl;
}
