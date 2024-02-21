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
	Fixed				&operator = (const Fixed &rhs);
	bool				operator > (const Fixed &rhs) const;
	bool				operator < (const Fixed &rhs) const;
	bool				operator >= (const Fixed &rhs) const;
	bool				operator <= (const Fixed &rhs) const;
	bool				operator == (const Fixed &rhs) const;
	bool				operator != (const Fixed &rhs) const;
	Fixed				operator + (const Fixed &rhs) const;
	Fixed				operator - (const Fixed &rhs) const;
	Fixed				operator * (const Fixed &rhs) const;
	Fixed				operator / (const Fixed &rhs) const;
	Fixed&				operator ++ (void); /* PREFIX */
	Fixed				operator ++ (int); /* POSTFIX */
	Fixed&				operator -- (void); /* PREFIX */
	Fixed				operator -- (int); /* POSTFIX */
	int					getRawBits(void) const;
	void				setRawBits(int const raw);
	float				toFloat(void) const;
	int					toInt(void) const;
	static Fixed		&min(Fixed &a, Fixed &b);
	static const Fixed	&min(const Fixed &a, const Fixed &b);
	static Fixed		&max(Fixed &a, Fixed &b);
	static const Fixed	&max(const Fixed &a, const Fixed &b);
/* ***************************** [^] PUBLIC [^] ***************************** */

private: /* ************************ [v] PRIVATE [v] ************************ */
	int					_fixedPointValue;
	static const int	_fractionalBits = 8;
/* **************************** [^] PRIVATE [^] ***************************** */
};

std::ostream	&operator << (std::ostream &o, Fixed const &i);

#endif /* FIXED_HPP */
