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
	cout << "ClapTrap " << _name << " is born!" << endl;
}

ClapTrap::ClapTrap(const ClapTrap &rhs)
{
	*this = rhs;
	cout << "ClapTrap copy constructor called" << endl;
	return ;
}
/* ************************** [^] CONSTRUCTOR [^] *************************** */

/* *************************** [v] DESTRUCTOR [v] *************************** */
ClapTrap::~ClapTrap(void)
{
	cout << "ClapTrap destructor called" << endl;
	return ;
}
/* *************************** [^] DESTRUCTOR [^] *************************** */

/* **************************** [v] OPERATOR [v] **************************** */
ClapTrap
	&ClapTrap::operator = (const ClapTrap &rhs) /* OPERATOR "=" */
{
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	return (*this);
}
/* **************************** [^] OPERATOR [^] **************************** */

void
	ClapTrap::attack(string const &target)
{
	if (_energyPoints <= 0)
	{
		cout << "ClapTrap " << _name << " is out of energy!" << endl;
		return ;
	}
	cout << "ClapTrap " << _name << " attacks " << target;
	cout << ", causing " << _attackDamage << " points of damage!" << endl;
	_energyPoints -= 1;
}

void
	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= amount)
	{
		cout << "ClapTrap " << _name << " is dead!" << endl;
		return ;
	}
	cout << "ClapTrap " << _name << " takes " << amount << " damage!" << endl;
	_hitPoints -= amount;
}

void
	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints <= amount)
	{
		cout << "ClapTrap " << _name << " is out of energy!" << endl;
		return ;
	}
	cout << "ClapTrap " << _name << " repairs itself for ";
	cout << amount << " hit points!" << endl;
	_energyPoints -= 1;
	_hitPoints += amount;
}

const string
	&ClapTrap::getName(void) const
{
	return (this->_name);
}

const unsigned int
	&ClapTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}

void
	ClapTrap::setAttackDamage(unsigned int amount)
{
	this->_attackDamage = amount;
}
