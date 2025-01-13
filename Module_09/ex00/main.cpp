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
#include "BitcoinExchange.hpp" /*
#  class BitcoinExchange;
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
		cout << "Error: more or less argument" << endl;
		return (1);
	}

	try
	{
		BitcoinExchange btc;
		btc.readInput(argv[1]);
	}
	catch (const exception &error)
	{
		cout << error.what() << endl;
	}

	return (0);
}
