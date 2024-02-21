/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "WrongCat.hpp" /*
#  class WrongCat;
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
WrongCat::WrongCat(void)
	: WrongAnimal("WrongCat")
{
	cout << this->_type << " constructor called" << endl;
}
/* ************************** [^] CONSTRUCTOR [^] *************************** */

/* *************************** [v] DESTRUCTOR [v] *************************** */
WrongCat::~WrongCat(void)
{
	cout << this->_type << " destructor called" << endl;
}
/* *************************** [^] DESTRUCTOR [^] *************************** */

void
	WrongCat::makeSound(void) const
{
	cout << "Meow!" << endl;
}
