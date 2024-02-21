/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
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
ClapTrap::ClapTrap(string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	cout << "[ ClapTrap ] - " << this->_name;
	cout << " has been born." << endl;
}

ClapTrap::ClapTrap(const ClapTrap &rhs)
{
	*this = rhs;
	cout << "[ ClapTrap ] - " << this->_name;
	cout << " has been copied with copy constuctor." << endl;
}
/* ************************** [^] CONSTRUCTOR [^] *************************** */

/* *************************** [v] DESTRUCTOR [v] *************************** */
ClapTrap::~ClapTrap(void)
{
	cout << "[ ClapTrap ] - " << this->_name << " has been destroyed." << endl;
}
/* *************************** [^] DESTRUCTOR [^] *************************** */

/* **************************** [v] OPERATOR [v] **************************** */
ClapTrap
	&ClapTrap::operator = (const ClapTrap& rhs) /* OPERATOR "=" */
{
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	cout << "[ ClapTrap ] - " << this->_name;
	cout << " has been copied with copy assignment operator." << endl;
	return (*this);
}
/* **************************** [^] OPERATOR [^] **************************** */

void
	ClapTrap::attack(string const &target)
{
	if (_energyPoints <= 0)
	{
		cout << "[ ClapTrap ] - " << this->_name;
		cout << " is out of energy!" << endl;
		return ;
	}
	cout << "[ ClapTrap ] - " << this->_name << " attacks ";
	cout << target << ", causing " << this->_attackDamage;
	cout << " points of damage!" << endl;
	_energyPoints -= 1;
}

void
	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= amount)
	{
		cout << "[ ClapTrap ] - " << this->_name << " is dead!" << endl;
		return ;
	}
	cout << "[ ClapTrap ] - " << this->_name << " takes ";
	cout << amount << " damage!" << endl;
	_hitPoints -= amount;
}

void
	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints <= amount)
	{
		cout << "[ ClapTrap ] - " << this->_name;
		cout << " is out of energy!" << endl;
		return ;
	}
	cout << "[ ClapTrap ] - " << this->_name << " repairs itself for ";
	cout << amount << " hit points!" << endl;
	_energyPoints -= 1;
	_hitPoints += amount;
}
