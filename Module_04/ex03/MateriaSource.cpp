/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "MateriaSource.hpp" /*
#  class MateriaSource;
#*/
#include <iostream> /*
#namespc std;
#*/
#include <string> /*
#  class std::string;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USING [v] ****************************** */
using std::string;
//using std::cout;
//using std::endl;
/* ***************************** [^] USING [^] ****************************** */

/* ************************** [v] CONSTRUCTOR [v] *************************** */
MateriaSource::MateriaSource(void)
{
	register int	index;

	index = 0;
	for (index = 0; index < 4; ++index)
		materias[index] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &src)
{
	*this = src;
}
/* ************************** [^] CONSTRUCTOR [^] *************************** */

/* *************************** [v] DESTRUCTOR [v] *************************** */
MateriaSource::~MateriaSource(void)
{
	register int	index;

	for (index = 0; index < 4; ++index)
		if (materias[index])
			delete materias[index];
}
/* *************************** [^] DESTRUCTOR [^] *************************** */

/* **************************** [v] OPERATOR [v] **************************** */
MateriaSource
	&MateriaSource::operator = (MateriaSource const &rhs) /* OPERATOR "=" */
{
	register int	index;

	if (this != &rhs)
		for (index = 0; index < 4; ++index)
			materias[index] = rhs.materias[index];
	return (*this);
}
/* **************************** [^] OPERATOR [^] **************************** */

AMateria
	*MateriaSource::getMateria(string const &type)
{
	register int	index;

	for (index = 0; index < 4; ++index)
		if (materias[index] && materias[index]->getType() == type)
			return (materias[index]);
	return (NULL);
}

void
	MateriaSource::learnMateria(AMateria *m)
{
	register int	index;

	for (index = 0; index < 4; ++index)
	{
		if (materias[index] == NULL)
		{
			materias[index] = m;
			// cout << "MateriaSource learned " << m->getType() << endl;
			return ;
		}
	}
	// cout << "MateriaSource can't learn " << m->getType() << endl;
}

AMateria
	*MateriaSource::createMateria(string const &type)
{
	register int	index;

	for (index = 0; index < 4; ++index)
		if (materias[index] && materias[index]->getType() == type)
			return (materias[index]->clone());
	return (NULL);
}
