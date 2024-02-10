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
#include "Harl.hpp" /*
#  class Harl;
#*/
#include <iostream> /*
#namespc std;
#*/
#include <string> /*
#  class std::string;
#*/
#include <cstdlib> /*
# define EXIT_FAILURE;
# define EXIT_SUCCESS;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USING [v] ****************************** */
using std::cout;
using std::endl;
using std::string;
/* ***************************** [^] USING [^] ****************************** */

int
	main(int argc, char **argv)
{
	string	input;
	Harl	harl;

	if (argc != 2)
	{
		cout << "Example: ./harlFilter [level]" << endl;
		return (EXIT_FAILURE);
	}
	input = argv[1];
	harl.complain(input);
	return (EXIT_SUCCESS);
}