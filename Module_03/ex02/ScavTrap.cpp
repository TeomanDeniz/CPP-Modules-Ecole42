/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "ScavTrap.hpp" /*
#  class ScavTrap;
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
using std::cout;
using std::endl;
/* ***************************** [^] USING [^] ****************************** */

/* ************************** [v] CONSTRUCTOR [v] *************************** */
ScavTrap::ScavTrap(string name)
	: ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	cout << "< ScavTrap > - " << this->_name << " constructed." << endl;
}
/* ************************** [^] CONSTRUCTOR [^] *************************** */

/* *************************** [v] DESTRUCTOR [v] *************************** */
ScavTrap::~ScavTrap(void)
{
	cout << "< ScavTrap > - " << this->_name << " destructed." << endl;
}
/* *************************** [^] DESTRUCTOR [^] *************************** */

void
	ScavTrap::attack(string const &target)
{
	if (this->_energyPoints <= 0)
	{
		cout << "< ScavTrap > - " << this->_name;
		cout << " is out of energy." << endl;
		return ;
	}
	cout << "< ScavTrap > - " << this->_name << " attacks ";
	cout << target << " at range, causing " << this->_attackDamage;
	cout << " points of damage !" << endl;
	this->_energyPoints -= 1;
}

void
	ScavTrap::guardGate(void)
{
	cout << "< ScavTrap > - " << this->_name;
	cout << " is now in Gate keeper mode." << endl;
}
