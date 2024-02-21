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
#include "FragTrap.hpp" /*
#  class FragTrap;
#*/
#include <cstdlib> /*
# define EXIT_SUCCESS;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

int
	main(void)
{
	FragTrap	ash("Ash");
	FragTrap	ash2(ash);

	ash.attack("the air");
	ash.takeDamage(10);
	ash.beRepaired(10);
	ash.highFive();
	return (EXIT_SUCCESS);
}
