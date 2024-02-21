/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
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
FragTrap::FragTrap(string name)
	: ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	cout << "| FragTrap | - " << this->_name << " constructed." << endl;
	cout << ClapTrap::_attackDamage << endl;
}
/* ************************** [^] CONSTRUCTOR [^] *************************** */

/* *************************** [v] DESTRUCTOR [v] *************************** */
FragTrap::~FragTrap(void)
{
	cout << "| FragTrap | - " << this->_name << " destructed." << endl;
}
/* *************************** [^] DESTRUCTOR [^] *************************** */

void
	FragTrap::highFive(void)
{
	if (this->_energyPoints <= 0)
	{
		cout << "| FragTrap | - " << this->_name;
		cout << " is out of energy." << endl;
		return ;
	}
	cout << "| FragTrap | - " << this->_name;
	cout << " high fives everybody." << endl;
	this->_energyPoints -= 1;
}
