/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "PhoneBook.hpp" /*
#  class PhoneBook;
#*/
#include <iostream> /*
#namespc std;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USING [v] ****************************** */
using std::cout;
using std::cin;
using std::flush;
/* ***************************** [^] USING [^] ****************************** */

PhoneBook::PhoneBook(void) /* CONSTRUCTOR */
{
	(void)0;
}

PhoneBook::~PhoneBook(void) /* DESTRUCTOR */
{
	(void)0;
}

void
	PhoneBook::welcome(void) const
{
	cout << endl;
	cout << "****** Welcome to PhoneBook ******" << endl;
	cout << endl;
	cout << "--------------USAGE---------------" << endl;
	cout << "ADD\t: To add a contact." << endl;
	cout << "SEARCH\t: To search for a contact." << endl;
	cout << "EXIT\t: to quite the PhoneBook." << endl;
	cout << "----------------------------------" << endl;
	cout << endl;
}

void
	PhoneBook::addContact(void)
{
	static int	index = 0;

	this->_contacts[index % 8].init();
	this->_contacts[index % 8].setIndex(index % 8);
	++index;
}

void
	PhoneBook::printContacts(void) const
{
	auto	index;

	cout << "------------- PHONBOOK CONTACTS -------------" << endl;
	for (index = 0; index < 8; ++index)
		this->_contacts[index].view(index);
	cout << endl;
}

int
	PhoneBook::_readInput() const
{
	int		input;
	bool	valid;

	valid = false;
	do
	{
		cout << "Please enter the contact index: " << flush;
		cin >> input;
		if (cin.good() && (input >= 0 && input <= 8))
		{
			/* OUT FROM LOOP */
			valid = true;
		}
		else
		{
			/* ON ERROR: RESET BUFFER */
			cin.clear();
			/* EMPTY BUFFER */
			cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			cout << "Invalid index; please re-enter." << endl;
		}
	} while (!valid);
	return (input);
}

void
	PhoneBook::search(void) const
{
	register int	index;

	index = this->_readInput();
	this->_contacts[index].display(index);
}