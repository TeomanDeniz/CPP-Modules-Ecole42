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
#include "Brain.hpp" /*
#  class Brain;
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
	cout << this->_type << " constructor called" << endl;
	try
	{
		this->_brain = new Brain();
	}
	catch (const std::bad_alloc &e)
	{
		cout << "Memory Allocation is failed : " << e.what() << endl;
	}
}

Cat::Cat(const Cat &src)
{
	*this = src;
}
/* ************************** [^] CONSTRUCTOR [^] *************************** */

/* *************************** [v] DESTRUCTOR [v] *************************** */
Cat::~Cat(void)
{
	cout << this->_type << " destructor called." << endl;
	delete  this->_brain;
}
/* *************************** [^] DESTRUCTOR [^] *************************** */

/* **************************** [v] OPERATOR [v] **************************** */
Cat
	&Cat::operator = (const Cat &src) /* OPERATOR "=" */
{
	cout << "Cat assignment operator called." << endl;
	if (this != &src)
	{
		this->_type = src._type;
		*this->_brain = *src._brain;
	}
	return (*this);
}
/* **************************** [^] OPERATOR [^] **************************** */

void
	Cat::makeSound(void) const
{
	cout << "Meow!" << endl;
}
