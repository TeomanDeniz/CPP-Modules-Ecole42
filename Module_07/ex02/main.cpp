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
#include "Array.hpp" /*
#
#        */
#include <iostream> /*
#nmspace std;
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USINGS [v] ***************************** */
using std::endl;
using std::cerr;
using std::exception;
/* ***************************** [^] USINGS [^] ***************************** */

/* ***************************** [v] MACROS [v] ***************************** */
#define MAX_ALLOCATION 750
/* ***************************** [^] MACROS [^] ***************************** */

int
	main(void)
{
	int			i;
	int			*mirror;
	Array <int>	numbers(MAX_ALLOCATION);

	mirror = new int[MAX_ALLOCATION]

	if (!mirror)
		return (1);

	srand(time((void *)0));

	for (i = 0; i < MAX_ALLOCATION; i++)
	{
		const int value = rand();

		numbers[i] = value;
		mirror[i] = value;
	}

	{ // Local
		Array <int>	tmp = numbers;
		Array <int>	test(tmp);
	} // Local

	for (i = 0; i < MAX_ALLOCATION; i++)
	{
		if (mirror[i] != numbers[i])
		{
			cerr << "didn't save the same value!!" << endl;
			return (1);
		}
	}

	try
	{
		numbers[-2] = 0;
	}
	catch (const exception &error)
	{
		cerr << error.what() << '\n';
	}

	try
	{
		numbers[MAX_ALLOCATION] = 0;
	}
	catch (const exception &error)
	{
		cerr << error.what() << '\n';
	}

	delete [] mirror;
	return (0);
}
