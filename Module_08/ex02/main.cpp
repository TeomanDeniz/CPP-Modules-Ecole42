/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "MutantStack.hpp" /*
#  class MutantStack;
#        */
#include <iostream> /*
#nmspace std;
#        */
#include <stack> /*
#  class std::stack;
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USINGS [v] ***************************** */
using std::stack;
using std::cout;
using std::endl;
/* ***************************** [^] USINGS [^] ***************************** */

int
	main(void)
{
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);
	cout << mstack.top() << endl;
	mstack.pop();
	cout << mstack.size() << endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack <int>::iterator it = mstack.begin();
	MutantStack <int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		cout << *it << endl;
		++it;
	}

	stack<int> s(mstack);
	return (0);
}
