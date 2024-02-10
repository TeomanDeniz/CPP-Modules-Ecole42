/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "Weapon.hpp" /*
#  class Weapon;
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
/* ***************************** [^] USING [^] ****************************** */

Weapon::Weapon(string type) /* CONSTRUCTOR */
{
	this->setType(type);
}

Weapon::~Weapon(void) /* DESTRUCTOR */
{
	(void)0;
}

const string
	&Weapon::getType(void)
{
	return (this->type);
}

void
	Weapon::setType(string newType)
{
	this->type = newType;
}
