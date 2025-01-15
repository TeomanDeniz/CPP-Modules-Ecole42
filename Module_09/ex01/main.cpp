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
#include "RPN.hpp" /*
#  class RPN;
#        */
#include <iostream> /*
#nmspace std;
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USINGS [v] ***************************** */
using std::exception;
using std::cout;
using std::endl;
/* ***************************** [^] USINGS [^] ***************************** */

int
	main(int argc, char **argv)
{
	if (argc != 2)
	{
		cout << "Error: No inverted Polish mathematical expression provided.";
		cout << endl;
		return (1);
	}

	try
	{
		RPN().calculate(argv[1]);
	}
	catch (const exception &e)
	{
		cout << e.what() << endl;
	}

	return (0);
}
