/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
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
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
static Fixed	abs(Fixed x);
static Fixed	area(Point const a, Point const b, Point const c);
/* *************************** [^] PROTOTYPES [^] *************************** */

bool
	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	abcArea = abs(area(a, b, c));
	Fixed	pabArea = abs(area(point, a, b));
	Fixed	pbcArea = abs(area(point, b, c));
	Fixed	pcaArea = abs(area(point, c, a));

	return ((abcArea == pabArea) && !!pbcArea && !!pcaArea);
}

static Fixed
	abs(Fixed x)
{
	if (x < 0)
		x = (~x) + 1;
	return (x);
}

static Fixed
	area(Point const a, Point const b, Point const c)
{
	return (\
		(\
			(\
				a.getX() * (b.getY() - c.getY())\
			) + (\
				b.getX() * (c.getY() - a.getY())\
			) + (\
				c.getX() * (a.getY() - b.getY())\
			)\
		) / 2\
	);
}
