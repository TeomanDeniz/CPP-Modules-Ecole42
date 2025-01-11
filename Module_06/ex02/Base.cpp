/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



/* **************************** [v] INCLUDES [v] **************************** */
#include "Base.hpp" /*
#  class Base;
#typedef t_cast;
#        */
#include <iostream> /*
#nmspace std;
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USINGS [v] ***************************** */
using std::cout;
using std::endl;
/* ***************************** [^] USINGS [^] ***************************** */

/* *************************** [v] DESTRUCTOR [v] *************************** */
Base::~Base(void){}
/* *************************** [^] DESTRUCTOR [^] *************************** */

static int
	ft_rand(int min, int max)
{
	static unsigned long	address;
	static int				seed;
	char					pointer[8192];
	t_cast					cast;

	seed = seed + 0;

	if (!seed)
	{
		cast.ptr = &pointer[seed];
		address = cast.integer + \
			((unsigned long)__TIME__[0] \
			* (unsigned long)__TIME__[1] \
			+ (unsigned long)__TIME__[3] \
			* (unsigned long)__TIME__[4] \
			+ (unsigned long)__TIME__[6]) \
			* (unsigned long)__TIME__[7];
	}

	address = (address * 1103515245 + 12345) & 0x7fffffff;
	seed++;
	return (min + (int)((double)address / (0x7fffffff / (max - min + 1))));
}

Base
	*generate(void)
{
	const unsigned char	n = ft_rand(1, 10000) % 3;

	if (n == 0)
		return (new A());
	else if (n == 1)
		return (new B());

	return (new C());
}

void
	identify(Base *p)
{
	if (dynamic_cast <A *>(p) != ((void *)0))
	{
		cout << "\'A\' class was identified!" << endl;
		return ;
	}
	else if (dynamic_cast <B *>(p) != ((void *)0))
	{
		cout << "\'B\' class was identified!" << endl;
		return ;
	}
	else if (dynamic_cast <C *>(p) != ((void *)0))
	{
		cout << "\'C\' class was identified!" << endl;
		return ;
	}

	cout << "Can't identify the class!" << endl;
}

void
	identify(Base &p)
{
	try
	{
		(void)dynamic_cast <A &>(p);
		cout << "\'A\' class was identified!" << endl;
		return ;
	}
	catch (...) {}

	try
	{
		(void)dynamic_cast <B &>(p);
		cout << "\'B\' class was identified!" << endl;
		return ;
	}
	catch (...) {}

	try
	{
		(void)dynamic_cast <C &>(p);
		cout << "\'C\' class was identified!" << endl;
		return ;
	}
	catch (...) {}

	cout << "Can't identify the class!" << endl;
}
