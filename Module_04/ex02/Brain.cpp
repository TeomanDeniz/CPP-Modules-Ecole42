/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "Brain.hpp" /*
#  class Brain;
#*/
#include <iostream> /*
#namespc std;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USING [v] ****************************** */
using std::cout;
using std::endl;
/* ***************************** [^] USING [^] ****************************** */

/* ************************** [v] CONSTRUCTOR [v] *************************** */
Brain::Brain(void)
{
	cout << "Brain created." << endl;
}

Brain::Brain(const Brain &src)
{
	*this = src;
}
/* ************************** [^] CONSTRUCTOR [^] *************************** */

/* *************************** [v] DESTRUCTOR [v] *************************** */
Brain::~Brain(void)
{
	cout << "Brain destroyed." << endl;
}
/* *************************** [^] DESTRUCTOR [^] *************************** */

/* **************************** [v] OPERATOR [v] **************************** */
Brain
	&Brain::operator = (const Brain &src) /* OPERATOR "=" */
{
	register int	index;

	cout << "<Brain.cpp:32> Brain copy called." << endl;
	if (this != &src)
		for (index = 0; index < 100; ++index)
			this->_ideas[index] = src._ideas[index];
	return (*this);
}
/* **************************** [^] OPERATOR [^] **************************** */
