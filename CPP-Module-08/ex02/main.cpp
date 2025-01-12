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
#include <list> /*
#  class std::list;
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
	{
		cout << endl << "-- Mutant Stack:" << endl;

		MutantStack<int> mstack;

		mstack.push(5); mstack.push(17);
		cout << "Stack top (expecting 17): " << mstack.top() << endl;
		mstack.pop();
		cout << "Stack size (expecting 1): " << mstack.size() << endl;
		mstack.push(3); mstack.push(5);
		mstack.push(737); mstack.push(0);
		cout << "Iterating over mstack from begin() to end() (expecting 5, 3, 5, 737, 0): " << endl;
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it; --it;

		while (it != ite)
		{
			cout << *it << " ";
			++it;
		}

		cout << endl;
	}

	{
		cout << endl << "-- List:" << endl;

		list<int> mstack;

		mstack.push_back(5); mstack.push_back(17);
		cout << "List \"top\" (back) (expecting 17): " << mstack.back() << endl;
		mstack.pop_back();
		cout << "Stack size (expecting 1): " << mstack.size() << endl;
		mstack.push_back(3); mstack.push_back(5);
		mstack.push_back(737); mstack.push_back(0);
		cout << "Iterating over mstack list from begin() to end() (expecting 5, 3, 5, 737, 0): " << endl;
		list<int>::iterator it = mstack.begin();
		list<int>::iterator ite = mstack.end();
		++it; --it;

		while (it != ite)
		{
			cout << *it << " ";
			++it;
		}

		cout << endl;
	}

	return (cout << endl, 0);
}
