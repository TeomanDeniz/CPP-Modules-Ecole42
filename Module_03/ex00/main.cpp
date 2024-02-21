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
#include "ClapTrap.hpp" /*
#  class ClapTrap;
#*/
#include <cstdlib> /*
# define EXIT_SUCCESS;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

int
	main(void)
{
	ClapTrap	Clap("Ash");
	ClapTrap	Staff("Staff");

	Clap.setAttackDamage(42);
	Clap.attack(Staff.getName());
	Staff.takeDamage(Clap.getAttackDamage());
	return (EXIT_SUCCESS);
}
