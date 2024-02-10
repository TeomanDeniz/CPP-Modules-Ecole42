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
# define EXIT_SUCCESS;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USING [v] ****************************** */
using std::string;
/* ***************************** [^] USING [^] ****************************** */

int
	main(void)
{
	string	input;
	Harl	harl;

	do
	{
		std::cout << "Enter a level: ";
		std::cin >> input;
		harl.complain(input);
	} while (input.compare("exit"));
	return (EXIT_SUCCESS);
}