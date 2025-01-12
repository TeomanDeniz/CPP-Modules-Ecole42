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
#include <iostream> /*
#nmspace std;
#        */
#include <vector> /*
#  class std::vector;
#        */
#include <list> /*
#  class std::list;
#        */
#include <deque> /*
#  class std::deque;
#        */
#include "easyfind.hpp" /*
#   T <> void easyfind(const T &, int);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USINGS [v] ***************************** */
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::exception;
using std::vector;
using std::list;
using std::deque;
/* ***************************** [^] USINGS [^] ***************************** */

void
	pressEnter(void)
{
	cout << endl << "press ENTER to continue" << endl;
	cin.ignore();
}

void
	titleHeader(const string msg)
{
	int	standartSize;
	int	messageSize;
	int	spaces;

    standartSize = 34;
    messageSize = msg.length();
    spaces = (standartSize - messageSize) / 2;

    cout << "------------------------------------" << endl << "-";

	for (i = 0; i < spaces; i++)
		cout << " ";

	cout << msg;

	for (i = 0; i < spaces; i++)
		cout << " ";

	cout << "-" << endl << "------------------------------------" << endl;
}

int
	main(void)
{
	int	i;

	{
		titleHeader("TEST WITH VECTOR TYPE");

		vector <int>	vec;

		for (i = 0; i < 10; i++)
			vec.push_back(i * i);

		cout << endl << "Status" << "> " << endl;
		cout << "print the created vector content" << endl;

		for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
			cout << "[" << *it << "] ";

		cout << endl;

		try
		{
			cout << endl << "Action" << "> " << endl;
			::easyfind(vec, 25);
		}
		catch (const exception &e)
		{
			cerr << e.what() << endl;
		}

		try
		{
			cout << endl << "Action" << "> " << endl;
			::easyfind(vec, 100);
		}
		catch (const exception &e)
		{
			cerr << "\t" << e.what() << endl;
		}
	}

	pressEnter();

	{
		titleHeader("TEST WITH DEQUE TYPE");

		deque <int>	deq;

		for (i = 0; i < 10; i++)
			deq.push_back(i * (i / 2));

		cout << endl << "Status" << "> " << endl;
		cout << "print the created deque content" << endl;

		for (deque<int>::iterator it = deq.begin(); it != deq.end(); it++)
			cout << "[" << *it << "] ";

		cout << endl;

		try
		{
			cout << endl << "Action" << "> " << endl;
			::easyfind(deq, 0);
		}
		catch (const exception &e)
		{
			cerr << "\t" << e.what() << endl;
		}

		try
		{
			cout << endl << "Action" << "> " << endl;
			::easyfind(deq, 7);
		}
		catch (const exception &error)
		{
			cerr << "\t" << error.what() << endl;
		}
	}

	pressEnter();

	{
		list <int>	lst;

		titleHeader("TEST WITH LIST TYPE");

		for (i = 0; i < 10; i++)
			lst.push_back(i * (i + 1));

		cout << endl << "Status" << "> " << endl;
		cout << "print the created list content" << endl;

		for (list<int>::iterator it = lst.begin(); it != lst.end(); it++)
			cout << "[" << *it << "] ";

		cout << endl;

		try
		{
			cout << endl << "Action" << "> " << endl;
			::easyfind(lst, 56);
		}
		catch (const exception &error)
		{
			cerr << "\t" << error.what() << endl;
		}

		try
		{
			cout << endl << "Action" << "> " << endl;
			::easyfind(lst, 91);
		}
		catch (const exception &error)
		{
			cerr << "\t" << error.what() << endl;
		}
	}

	pressEnter();
	return (0);
}
