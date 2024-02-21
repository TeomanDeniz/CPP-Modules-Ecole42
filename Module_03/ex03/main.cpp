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
#include "DiamondTrap.hpp" /*
#  class DiamondTrap;
#*/
#include <cstdlib> /*
# define EXIT_SUCCESS;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

int
	main(void)
{
	DiamondTrap	ash("Ash");
	DiamondTrap	ash2(ash);
	DiamondTrap	ash3(".");

	ash.whoAmI();
	ash2.whoAmI();
	ash3 = ash;
	ash3.whoAmI();
	ash.attack("the air");
	ash.takeDamage(10);
	ash.beRepaired(10);
	return (EXIT_SUCCESS);
}
