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
// using std::cout;
// using std::endl;
/* ***************************** [^] USING [^] ****************************** */

/* ************************** [v] CONSTRUCTOR [v] *************************** */
Fixed::Fixed(void)
	: _fixedPointValue(0)
{
	// cout << "Default constructor called" << endl;
}

Fixed::Fixed(const int n)
	: _fixedPointValue(n << _fractionalBits)
{
	// cout << "Int constructor called" << endl;
}

Fixed::Fixed(const float n)
	: _fixedPointValue(std::roundf(n * (1 << _fractionalBits)))
{
	// cout << "Float constructor called" << endl;
}

Fixed::Fixed(const Fixed &rhs)
{
	*this = rhs;
}
/* ************************** [^] CONSTRUCTOR [^] *************************** */

Fixed
	&Fixed::operator = (const Fixed &rhs)
{
	if (this != &rhs)
		this->_fixedPointValue = rhs.getRawBits();
	return (*this);
}

/* *************************** [v] DESTRUCTOR [v] *************************** */
Fixed::~Fixed(void)
{
	(void)0;
}
/* *************************** [^] DESTRUCTOR [^] *************************** */

/* **************************** [v] OPERATOR [v] **************************** */
std::ostream
	&operator << (std::ostream &o, Fixed const &i) /* OPERATOR "<<" */
{
	o << i.toFloat();
	return (o);
}

bool
	Fixed::operator > (const Fixed &rhs) const /* OPERATOR ">" <Fixed> */
{
	return (this->getRawBits() > rhs.getRawBits());
}

bool
	Fixed::operator < (const Fixed &rhs) const /* OPERATOR "<" <Fixed> */
{
	return (this->getRawBits() < rhs.getRawBits());
}

bool
	Fixed::operator >= (const Fixed &rhs) const /* OPERATOR ">=" <Fixed> */
{
	return (this->getRawBits() >= rhs.getRawBits());
}

bool
	Fixed::operator <= (const Fixed &rhs) const /* OPERATOR "<=" <Fixed> */
{
	return (this->getRawBits() <= rhs.getRawBits());
}

bool
	Fixed::operator == (const Fixed &rhs) const /* OPERATOR "==" <Fixed> */
{
	return (this->getRawBits() == rhs.getRawBits());
}

bool
	Fixed::operator != (const Fixed &rhs) const /* OPERATOR "!=" <Fixed> */
{
	return (this->getRawBits() != rhs.getRawBits());
}

Fixed
	Fixed::operator + (const Fixed &rhs) const /* OPERATOR "+" <Fixed> */
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed
	Fixed::operator - (const Fixed &rhs) const /* OPERATOR "-" <Fixed> */
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed
	Fixed::operator * (const Fixed &rhs) const /* OPERATOR "*" <Fixed> */
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed
	Fixed::operator / (const Fixed &rhs) const /* OPERATOR "/" <Fixed> */
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed
	&Fixed::operator ++ (void) /* OPERATOR "++" ++<FIXED> */
{
	++this->_fixedPointValue;
	return (*this);
}

Fixed
	Fixed::operator ++ (int) /* OPERATOR "++" <int> <FIXED>++ */
{
	Fixed	temp(*this);

	this->_fixedPointValue++;
	return (temp);
}

Fixed
	&Fixed::operator -- (void) /* OPERATOR "--" */
{
	this->_fixedPointValue--;
	return (*this);
}

Fixed
	Fixed::operator -- (int) /* OPERATOR "--" <int> */
{
	Fixed	temp(*this);

	this->_fixedPointValue--;
	return (temp);
}
/* **************************** [^] OPERATOR [^] **************************** */

Fixed
	&Fixed::min(Fixed &a, Fixed &b)
{
	return ((a < b) ? a : b);
}

const Fixed
	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

Fixed
	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

const Fixed
	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

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
