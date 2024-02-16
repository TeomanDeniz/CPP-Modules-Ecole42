/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "HumanA.hpp" /*
#  class HumanA;
#*/
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
using std::cout;
using std::string;
using std::endl;
/* ***************************** [^] USING [^] ****************************** */

HumanA::HumanA(string name, Weapon &weapon) /* CONSTRUCTOR */ \
	: _name(name), _weapon(weapon)
{
	(void)name, (void)weapon;
}

HumanA::~HumanA(void) /* DESTRUCTOR */
{
	(void)0;
}

void
	HumanA::attack(void) const
{
	if (this->_weapon.getType() != "")
		cout << _name << " attacks with their " << \
			this->_weapon.getType() << endl;
	else
		cout << _name << " doesn't have a weapon to attack." << endl;
}