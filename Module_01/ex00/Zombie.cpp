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
#include <string> /*
#  class string;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USING [v] ****************************** */
using std::cout;
using std::endl;
using std::string;
/* ***************************** [^] USING [^] ****************************** */

Zombie::Zombie(string name) /* CONSTRUCTOR */
{
	this->_name = name;
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
