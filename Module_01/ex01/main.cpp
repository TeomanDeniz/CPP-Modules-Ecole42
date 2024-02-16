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
#include "Zombie.hpp" /*
#  class Zombie;
#*/
#include <cstdlib> /*
# define EXIT_SUCCESS;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

#define N 4 /* PDF WANTED THE NAME OF THIS DEFINE AS "N" */

int
	main(void)
{
	Zombie			*zombies;
	register int	ecx;

	zombies = zombieHorde(N, "zombi");
	for (ecx = 0; ecx < N; ++ecx)
		zombies[ecx].announce();

	delete [] zombies;
	return (EXIT_SUCCESS);
}