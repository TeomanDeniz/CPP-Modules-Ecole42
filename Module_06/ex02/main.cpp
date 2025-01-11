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
#include "Base.hpp" /*
#  class Base;
#        */
#include <iostream> /*
#nmspace std;
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USINGS [v] ***************************** */
using std::exception;
using std::cerr;
using std::endl;
/* ***************************** [^] USINGS [^] ***************************** */

int
	main(void)
{
	Base	*theBase;

	try
	{
		theBase = generate();

		identify(theBase);
		identify(*theBase);

		delete theBase;
	}
	catch (const exception &error)
	{
		cerr << error.what() << endl;
	}

	return (0);
}
