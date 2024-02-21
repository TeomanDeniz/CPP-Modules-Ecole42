/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// resource: https://www.youtube.com/watch?v=gc1Nl3mmCuY

/* **************************** [v] INCLUDES [v] **************************** */
#include "Fixed.hpp" /*
#  class Fixed;
#*/
#include <iostream> /*
#namespc std;
#*/
#include <cstdlib> /*
# define EXIT_SUCCESS;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/******************************************************************************\
|*                                                                            *|
|* https://www.easysurf.cc/scintd.htm <- Scientific notation                  *|
|* https://www.h-schmidt.net/FloatConverter/IEEE754.html <- Float IEEE 754    *|
|*                                                                            *|
\******************************************************************************/

/******************************************************************************\
|*                                                                            *|
|* SIGNED BIT                                                                 *|
|* |                                                                          *|
|* | EXPONENT MANTISSA                                                        *|
|* S EEEEEEEE FFFFFFFFFFFFFFFFFFFFFFF                                         *|
|*                                                                            *|
|* S Bit 00: -                                                                *|
|* E Bit 01: 128                                                              *|
|* E Bit 02: 64                                                               *|
|* E Bit 03: 32                                                               *|
|* E Bit 04: 16                                                               *|
|* E Bit 05: 8                                                                *|
|* E Bit 06: 4                                                                *|
|* E Bit 07: 2                                                                *|
|* E Bit 08: 1                                                                *|
|* F Bit 09: 0.5                                                              *|
|* F Bit 10: 0.25                                                             *|
|* F Bit 11: 0.125                                                            *|
|* F Bit 12: 0.0625                                                           *|
|* F Bit 13: 0.03125                                                          *|
|* F Bit 14: 0.015625                                                         *|
|* F Bit 15: 0.0078125                                                        *|
|* F Bit 16: 0.00390625                                                       *|
|* F Bit 17: 0.001953125                                                      *|
|* F Bit 18: 0.0009765625                                                     *|
|* F Bit 19: 0.00048828125                                                    *|
|* F Bit 20: 0.000244140625                                                   *|
|* F Bit 21: 0.0001220703125                                                  *|
|* F Bit 22: 0.00006103515625                                                 *|
|* F Bit 23: 0.000030517578125                                                *|
|* F Bit 24: 0.0000152587890625                                               *|
|* F Bit 25: 0.00000762939453125                                              *|
|* F Bit 26: 0.000003814697265625                                             *|
|* F Bit 27: 0.0000019073486328125                                            *|
|* F Bit 28: 0.00000095367431640625                                           *|
|* F Bit 29: 0.000000476837158203125                                          *|
|* F Bit 30: 0.0000002384185791015625                                         *|
|* F Bit 31: 0.00000011920928955078125                                        *|
|*                                                                            *|
\******************************************************************************/

/* ***************************** [v] USING [v] ****************************** */
using std::cout;
using std::endl;
/* ***************************** [^] USING [^] ****************************** */

int
	main(void)
{
	Fixed		a;
	Fixed const	b(10);
	Fixed const	c(42.42F);
	Fixed const	d(b);

	a = Fixed(1234.4321F);
	cout << "a is " << a << endl;
	cout << "b is " << b << endl;
	cout << "c is " << c << endl;
	cout << "d is " << d << endl;
	cout << "a is " << a.toInt() << " as integer" << endl;
	cout << "b is " << b.toInt() << " as integer" << endl;
	cout << "c is " << c.toInt() << " as integer" << endl;
	cout << "d is " << d.toInt() << " as integer" << endl;
	return (EXIT_SUCCESS);
}
