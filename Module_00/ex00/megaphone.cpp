/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <iostream> /*
#namespc std;
#*/
#include <cctype> /*
#    int toupper(int);
#*/
#include <cstdlib> /*
# define EXIT_SUCCESS;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USING [v] ****************************** */
using std::cout;
using std::endl;
/* ***************************** [^] USING [^] ****************************** */

int
	main(int argc, char **argv)
{
	auto	strIndex = 1;
	auto	charIndex = 0;

	if (argc == 1)
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (strIndex = 1; argv[strIndex]; strIndex++)
		{
			for (charIndex = 0; argv[strIndex][charIndex]; charIndex++)
				cout << (char) toupper(argv[strIndex][charIndex]);
			if (strIndex < argc - 1)
				cout << ' ';
		}
	}
	cout << endl;
	return (EXIT_SUCCESS);
}
