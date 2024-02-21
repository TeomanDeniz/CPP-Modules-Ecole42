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

class Fixed
{
public: /* ************************* [v] PUBLIC [v] ************************* */
	Fixed(void);
	Fixed(const Fixed &rhs);
	~Fixed(void);
	Fixed	&operator = (const Fixed &rhs);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
/* ***************************** [^] PUBLIC [^] ***************************** */

private: /* ************************ [v] PRIVATE [v] ************************ */
	int					_fixedPointValue;
	static const int	_fractionalBits = 8;
/* **************************** [^] PRIVATE [^] ***************************** */
};

#endif  /* FIXED_HPP */
