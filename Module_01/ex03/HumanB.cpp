/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "HumanB.hpp" /*
#  class HumanB;
#*/
#include <iostream> /*
#namespc std;
#*/
#include <string> /*
#  class std::string;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USING [v] ****************************** */
using std::cout;
using std::string;
using std::endl;
/* ***************************** [^] USING [^] ****************************** */

HumanB::HumanB(string name) /* CONSTRUCTOR */ \
	: _name(name)
{
	this->_weapon = NULL;
}

HumanB::~HumanB(void) /* DESTRUCTOR */
{
	(void)0;
}

void
	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

void
	HumanB::attack(void) const
{
	if (this->_weapon != NULL && this->_weapon->getType() != "")
		cout << _name << " attacks with their " << \
			this->_weapon->getType() << endl;
	else
		cout << _name << " doesn't have a weapon to attack." << endl;
}
