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
Dog::Dog(void)
	: Animal("Dog")
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

Dog::Dog(const Dog &src)
{
	*this = src;
}
/* ************************** [^] CONSTRUCTOR [^] *************************** */

/* *************************** [v] DESTRUCTOR [v] *************************** */
Dog::~Dog(void)
{
	delete this->_brain;
	cout << this->_type << " destructor called" << endl;
}
/* *************************** [^] DESTRUCTOR [^] *************************** */

/* **************************** [v] OPERATOR [v] **************************** */
Dog
	&Dog::operator = (const Dog &src) /* OPERATOR "=" */
{
	cout << "<Dog.cpp:32> Dog copy called." << endl;
	if (this != &src)
	{
		this->_type = src._type;
		this->_brain = new Brain(*src._brain);
	}
	return (*this);
}
/* **************************** [^] OPERATOR [^] **************************** */

void
	Dog::makeSound(void) const
{
	cout << "Woof!" << endl;
}
