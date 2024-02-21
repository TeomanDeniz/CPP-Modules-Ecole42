/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
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
Character::Character(string const &name)
	: _name(name)
{
	register int	index;

	for (index = 0; index < 4; ++index)
		this->_inventory[index] = NULL;
	cout << "Character " << this->_name << " created" << endl;
}

Character::Character(Character const &src)
	: _name(src._name)
{
	// for (int i = 0; i < 4; i++)
	//     this->_inventory[i] = src._inventory[i];
	*this = src;
	cout << "Character " << this->_name << " created" << endl;
}
/* ************************** [^] CONSTRUCTOR [^] *************************** */

/* *************************** [v] DESTRUCTOR [v] *************************** */
Character::~Character(void)
{
	register int	index;

	cout << "Character " << this->_name << " destroyed" << endl;
	for (index = 0; index < 4; ++index)
		if (this->_inventory[index])
			delete this->_inventory[index];
}
/* *************************** [^] DESTRUCTOR [^] *************************** */

/* **************************** [v] OPERATOR [v] **************************** */
Character
	&Character::operator = (Character const &rhs) /* OPERATOR "=" */
{
	register int	index;

	if (this != &rhs)
	{
		this->_name = rhs._name;
		for (index = 0; index < 4; ++index)
			this->_inventory[index] = rhs._inventory[index];
	}
	return (*this);
}
/* **************************** [^] OPERATOR [^] **************************** */


void
	Character::equip(AMateria *m)
{
	register int	index;

	for (index = 0; index < 4; ++index)
	{
		if (this->_inventory[index] == NULL)
		{
			this->_inventory[index] = m;
			cout << "Character " << this->_name;
			cout << " equipped with " << m->getType() << endl;
			return ;
		}
	}
	cout << "Character " << this->_name << " can't equip ";
	cout << m->getType() << endl;
}

void
	Character::unequip(int idx)
{
	if (this->_inventory[idx])
	{
		delete this->_inventory[idx];
		this->_inventory[idx] = NULL;
		cout << "Character " << this->_name << " unequipped" << endl;
	}
	else
		cout << "Character " << this->_name << " can't unequip" << endl;
}

void
	Character::use(int idx, ICharacter &target)
{
	if (this->_inventory[idx])
	{
		this->_inventory[idx]->use(target);
		cout << "Character " << this->_name << " uses ";
		cout << this->_inventory[idx]->getType() << endl;
	}
	else
		cout << "Character " << this->_name << " can't use" << endl;
}

string const
	&Character::getName(void) const
{
	return (this->_name);
}
