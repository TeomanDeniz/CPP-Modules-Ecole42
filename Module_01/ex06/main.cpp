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

static void
	toLowercase(char *stringArg)
{
	register int	ecx;

	if (!stringArg)
		return ;
	for (ecx = 0; !!stringArg[ecx]; ecx++)
		if (stringArg[ecx] >= 'A' && stringArg[ecx] <= 'Z')
			stringArg[ecx] += 'a' - 'A';
}

int
	main(int argc, char *argv[])
{
	Harl	harl;

	if (argc != 2)
	{
		cout << "Levels: DEBUG - INFO - WARNING - ERROR" << endl;
		cout << "Example: ./harlFilter [level]" << endl;
		return (EXIT_FAILURE);
	}
	toLowercase(argv[1]);
	harl.complain(argv[1]);
	return (EXIT_SUCCESS);
}