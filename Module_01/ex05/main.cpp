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
using std::cout;
using std::endl;
/* ***************************** [^] USING [^] ****************************** */

static void
	toLowercase(string &stringArg)
{
	register int	ecx;

	if (stringArg.empty())
		return ;
	for (ecx = 0; !!stringArg[ecx]; ecx++)
		if (stringArg[ecx] >= 'A' && stringArg[ecx] <= 'Z')
			stringArg[ecx] += 'a' - 'A';
}

int
	main(void)
{
	string	input;
	Harl	harl;

	do
	{
		cout << "Levels: DEBUG - INFO - WARNING - ERROR - EXIT" << endl;
		cout << "Enter a level: ";
		std::cin >> input;
		toLowercase(input);
		harl.complain(input);
	} while (input.compare("exit") && !(!std::cin.good() && input.empty()));
	return (EXIT_SUCCESS);
}