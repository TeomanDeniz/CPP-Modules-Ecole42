/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "Zombie.hpp" /*
#  class Zombie;
#*/
#include <iostream> /*
#namespc std;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USING [v] ****************************** */
using std::cout;
using std::string;
using std::flush;
/* ***************************** [^] USING [^] ****************************** */

Zombie::Zombie(void) /* CONSTRUCTOR */
{
	(void)0;
}

Zombie::~Zombie(void) /* DESTRUCTOR */
{
	cout << "Zombie " << this->_name << " has been destroyed." << endl;
}

void
	Zombie::announce(void)
{
	cout << this->_name << ": BraiiiiiiinnnzzzZ..." << endl;
}

void
	Zombie::setName(string name)
{
	this->_name = name;
}
