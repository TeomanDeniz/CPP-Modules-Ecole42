/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "Point.hpp" /*
#  class Point;
#*/
//#include <iostream> /*
//#namespc std;
//#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USING [v] ****************************** */
// using std::cout;
// using std::endl;
/* ***************************** [^] USING [^] ****************************** */

/* ************************** [v] CONSTRUCTOR [v] *************************** */
Point::Point(void)
	: _x(0), _y(0)
{
	(void)0;
	// cout << "Point created" << endl;
}

Point::Point(const float x, const float y)
	: _x(x), _y(y)
{
	(void)0;
	// cout << "Point created" << endl;
}

Point::Point(const Point &src)
	: _x(src._x), _y(src._y)
{
	(void)0;
	// cout << "Point created" << endl;
}
/* ************************** [^] CONSTRUCTOR [^] *************************** */

/* *************************** [v] DESTRUCTOR [v] *************************** */
Point::~Point(void)
{
	(void)0;
	// cout << "Point destroyed" << endl;
}
/* *************************** [^] DESTRUCTOR [^] *************************** */

/* **************************** [v] OPERATOR [v] **************************** */
Point
	&Point::operator = (const Point &rhs) /* OPERATOR "=" */
{
	if (this != &rhs)
	{
		// const_cast <Fixed &> (this->_x) = rhs.getX();
		// const_cast <Fixed &> (this->_y) = rhs.getY();
		(Fixed)this->_x = rhs.getX();
		(Fixed)this->_y = rhs.getY();
	}
	return (*this);
}
/* **************************** [^] OPERATOR [^] **************************** */

Fixed
	Point::getX(void) const
{
	return (this->_x);
}

Fixed
	Point::getY(void) const
{
	return (this->_y);
}
