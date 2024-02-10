/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "Harl.hpp" /*
#  class Harl;
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

Harl::Harl(void) /* CONSTRUCTOR */
{
	(void)0;
}

Harl::~Harl(void) /* DESTRUCTOR */
{
	(void)0;
}

void
	Harl::debug(void)
{
	cout << "[ DEBUG ]" << endl;
	cout << "love having extra bacon for my \
		7XL-double-cheese-triple-pickle-special-ketchup burger. \
		I really do!" << endl;
	cout << endl;
}

void
	Harl::info(void)
{
	cout << "[ INFO ]" << endl;
	cout << "I cannot believe adding extra bacon costs more money. \
		You didn't put enough bacon in my burger! \
		If you did, I wouldn't be asking for more!" << endl;
	cout << endl;
}

void
	Harl::warning(void)
{
	cout << "[ WARNING ]" << endl;
	cout << "I think I deserve to have some extra bacon for free. \
		I've been coming foryears whereas you started working here \
		since last month." << endl;
	cout << endl;
}

void
	Harl::error(void)
{
	cout << "[ ERROR ]" << endl;
	cout << "This is unacceptable! I want to speak to the manager now." << endl;
	cout << endl;
}

void
	Harl::complain(string level)
{
	register int	ecx;
	string			levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	ecx = 0;
	while (ecx < 4 && levels[ecx].compare(level))
		++ecx;
	switch (ecx)
	{
		case    0: 
			this->debug();
		case    1: 
			this->info();
		case    2: 
			this->warning();
		case    3: 
			this->error();
			break ;
		default:
			cout << "[ Probably complaining about \
				insignificant problems ]" << endl;
	}
}
