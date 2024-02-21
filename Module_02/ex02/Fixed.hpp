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

/*
	Static Function Members
	By declaring a function member as static, you make it independent of any
	 particular object of the class. A static member function can be called 
	 even if no objects of the class exist and the static functions are accessed
	 using only the class name and the scope resolution operator ::.
	A static member function can only access static data member, other static
	member functions and any other functions from outside the class.
	Static member functions have a class scope and they do not have access
	to the this pointer of the class. You could use a static member function
	to determine whether some objects of the class have been created or not.

	We can define class members static using static keyword. When we declare
	a member of a class as static it means no matter how many objects of the class are created, 
	there is only one copy of the static member.
	A static member is shared by all objects of the class. All static data is initialized to zero
	when the first object is created, if no other initialization is present. We can't put it in the 
	class definition but it can be initialized outside the by redeclaring the static variable, 
	using the scope resolution operator :: to identify which class it belongs to.
*/

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
	bool				operator > (const Fixed &rhs) const ;
	bool				operator < (const Fixed &rhs) const ;
	bool				operator >= (const Fixed &rhs) const ;
	bool				operator <= (const Fixed &rhs) const ;
	bool				operator == (const Fixed &rhs) const ;
	bool				operator != (const Fixed &rhs) const ;
	Fixed				operator + (const Fixed &rhs) const ;
	Fixed				operator - (const Fixed &rhs) const ;
	Fixed				operator * (const Fixed &rhs) const ;
	Fixed				operator / (const Fixed &rhs) const ;
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
	int                 _fixedPointValue;
	static const int    _fractionalBits = 8;
/* **************************** [^] PRIVATE [^] ***************************** */
};

std::ostream	&operator << (std::ostream &o, Fixed const &i);

#endif /* FIXED_HPP */
