/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "Fixed.hpp" /*
#  class Fixed;
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
Fixed::Fixed(void)
{
	cout << "Default constructor called" << endl;
	this->_fixedPointValue = 0;
}

Fixed::Fixed(const Fixed &rhs)
{
	cout << "Copy constructor called" << endl;
	this->setRawBits(rhs.getRawBits());
}
/* ************************** [^] CONSTRUCTOR [^] *************************** */

/* *************************** [v] DESTRUCTOR [v] *************************** */
Fixed::~Fixed(void)
{
	cout << "Destructor called" << endl;
}
/* *************************** [^] DESTRUCTOR [^] *************************** */

/* **************************** [v] OPERATOR [v] **************************** */
Fixed
	&Fixed::operator = (const Fixed &rhs) /* OPERATOR "=" */
{
	cout << "Copy assignment operator called" << endl;
	if (this != &rhs)
		this->_fixedPointValue = rhs.getRawBits();
	return (*this);
}
/* **************************** [^] OPERATOR [^] **************************** */

int
	Fixed::getRawBits(void) const
{
	cout << "getRawBits member function called" << endl;
	return (this->_fixedPointValue);
}

void
	Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}
