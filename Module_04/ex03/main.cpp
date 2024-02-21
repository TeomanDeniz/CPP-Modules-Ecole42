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
#include "Character.hpp" /*
#  class Character;
#*/
#include "ICharacter.hpp" /*
#  class ICharacter;
#*/
#include "IMateriaSource.hpp" /*
#  class IMateriaSource;
#*/
#include "MateriaSource.hpp" /*
#  class MateriaSource;
#*/
#include "Ice.hpp" /*
#  class Ice;
#*/
#include "Cure.hpp" /*
#  class Cure;
#*/
#include <cstdlib> /*
# define EXIT_SUCCESS;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

int
	main(void)
{
	ICharacter		*bob;
	IMateriaSource	*src;
	ICharacter		*me;
	AMateria		*tmp;

	src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	me = new Character("me");
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return (EXIT_SUCCESS);
}
