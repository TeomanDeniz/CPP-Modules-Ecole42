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
#include <cmath> /*
#  float std::roundf(float);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USING [v] ****************************** */
using std::cout;
using std::endl;
/* ***************************** [^] USING [^] ****************************** */

/* ************************** [v] CONSTRUCTOR [v] *************************** */
Fixed::Fixed(void)
	: _fixedPointValue(0)
{
	cout << "Default constructor called" << endl;
}

Fixed::Fixed(const int n)
	: _fixedPointValue(n << _fractionalBits)
{
	cout << "Int constructor called" << endl;
}

Fixed::Fixed(const float n)
	: _fixedPointValue(std::roundf(n * (1 << _fractionalBits)))
{
	cout << "Float constructor called" << endl;
}

Fixed::Fixed(const Fixed &rhs)
{
	cout << "Copy constructor called" << endl;
	*this = rhs;
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
	return (this->_fixedPointValue);
}

void
	Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

float
	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->getRawBits()) / (1 << _fractionalBits));
}

int
	Fixed::toInt(void) const
{
	return (this->_fixedPointValue >> _fractionalBits);
}

std::ostream
	&operator << (std::ostream &o, Fixed const &i)
{
	o << i.toFloat();
	return (o);
}
