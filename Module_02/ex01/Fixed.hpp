/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP 202402

/* **************************** [v] INCLUDES [v] **************************** */
# include <iostream> /*
# namespc std;
# */
/* **************************** [^] INCLUDES [^] **************************** */

class Fixed
{
public: /* ************************* [v] PUBLIC [v] ************************* */
	Fixed(void);
	Fixed(const int n);
	Fixed(const float n);
	Fixed(const Fixed &rhs);
	~Fixed(void);
	Fixed	&operator = (const Fixed &rhs);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
/* ***************************** [^] PUBLIC [^] ***************************** */

private: /* ************************ [v] PRIVATE [v] ************************ */
	int					_fixedPointValue;
	static const int	_fractionalBits = 8;
/* **************************** [^] PRIVATE [^] ***************************** */
};

/* *************************** [v] PROTOTYPES [v] *************************** */
std::ostream	&operator << (std::ostream &o, Fixed const &i);
/* *************************** [^] PROTOTYPES [^] *************************** */

#endif /* FIXED_HPP */
