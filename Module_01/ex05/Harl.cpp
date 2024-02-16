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
	cout << "love having extra bacon for my \
7XL-double-cheese-triple-pickle-special-ketchup burger. \
I really do!" << endl;
}

void
	Harl::info(void)
{
	cout << "I cannot believe adding extra bacon costs more money. You didn't \
put enough bacon in my burger! If you did, I wouldn't be asking for \
more!" << endl;
}

void
	Harl::warning(void)
{
	cout << "I think I deserve to have some extra bacon for free. \
I've been coming foryears whereas you started working here \
since last month." << endl;
}

void
	Harl::error(void)
{
	cout << "This is unacceptable! I want to speak to the manager now." << endl;
}

void
	Harl::complain(string level)
{
	register int	ecx;
	void			(Harl::*funcs[4])();
	string			levels[4] = {"debug", "info", "warning", "error"};

	funcs[0] = &Harl::debug;
	funcs[1] = &Harl::info;
	funcs[2] = &Harl::warning;
	funcs[3] = &Harl::error;
	ecx = 0;
	while (ecx < 4 && levels[ecx].compare(level))
		++ecx;
	if (ecx < 4)
		(this->*funcs[ecx])();
}
