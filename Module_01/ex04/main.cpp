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
#include "SedV2.hpp" /*
#  class SedV2;
#*/
#include <cstdlib> /*
# define EXIT_FAILURE;
# define EXIT_SUCCESS;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USING [v] ****************************** */
using std::cerr;
using std::endl;
/* ***************************** [^] USING [^] ****************************** */

int
	main(register int argc, const char **const argv)
{
	if (argc != 4)
	{
		cerr << ARG_ERROR_MESSAGE << endl;
		return (EXIT_FAILURE);
	}
	else
	{
		SedV2	asdasdasd(argv[1]);

		asdasdasd.replace(argv[2], argv[3]);
	}
	return (EXIT_SUCCESS);
}