/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP 202402

/* **************************** [v] INCLUDES [v] **************************** */
# include "Fixed.hpp" /*
#   class Fixed;
# */
/* **************************** [^] INCLUDES [^] **************************** */

class Point
{
public: /* ************************* [v] PUBLIC [v] ************************* */
	Point(void);
	Point(const float x, const float y);
	Point(const Point &src);
	~Point(void);
	Point	&operator = (const Point &rhs);
	Fixed	getX(void) const;
	Fixed	getY(void) const;
/* ***************************** [^] PUBLIC [^] ***************************** */

private: /* ************************ [v] PRIVATE [v] ************************ */
	const Fixed	_x;
	const Fixed	_y;
/* **************************** [^] PRIVATE [^] ***************************** */
};

extern bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif /* POINT_HPP */
