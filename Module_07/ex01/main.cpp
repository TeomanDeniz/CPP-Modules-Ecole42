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

/* **************************** [v] INCLUDES [v] **************************** */
#include "iter.hpp" /*
#
#        */
#include <iostream> /*
#nmspace std;
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USINGS [v] ***************************** */
using std::string;
/* ***************************** [^] USINGS [^] ***************************** */


int
	main(void)
{
	int		args[2];
	string	exampleStrings[5];

	exampleStrings[0] = "aaa";
	exampleStrings[1] = "bbb";
	exampleStrings[2] = "ccc";
	exampleStrings[3] = "ddd";
	exampleStrings[4] = (string)0;
	args[0] = 1;
	args[1] = 3;

	::iter(args, 2, print);
	::swap(args[0], args[1]);
	::iter(args, 2, print);
	::iter(exampleStrings, 5, print);
	return (0);
}
