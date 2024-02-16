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
#include <string> /*
#  class std::string;
#istream &std::getline(istream&, string&);
#*/
#include <cstdio> /*
#   FILE *freopen(char *, char *, FILE *);
#*/
#include <cstdlib> /*
#    int atoi(char *);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USING [v] ****************************** */
using std::cout;
using std::cin;
using std::endl;
/* ***************************** [^] USING [^] ****************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
static bool	isValidNumber(const string &stringArg);
/* *************************** [^] PROTOTYPES [^] *************************** */

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
	if (this->_contacts[index % 8].error)
	{
		this->_contacts[index % 8].error = false;
		return ;
	}
	this->_contacts[index % 8].setIndex(index % 8);
	++index;
}

void
	PhoneBook::printContacts(void) const
{
	register int	index;

	cout << "------------- PHONEBOOK CONTACTS -------------" << endl;
	for (index = 0; index < 8; ++index)
		this->_contacts[index].view(index);
	cout << endl;
}

int
	PhoneBook::_readInput(void) const
{
	string	input;
	bool	valid;
	int		result;

	valid = false;
	do
	{
		cout << "Please enter the contact index: " << endl;
		std::getline(cin, input);
		if (cin.eof()) /* CTRL + D */
		{
			cin.clear(); /* ON ERROR: RESET BUFFER */
			if (freopen("/dev/tty", "r", stdin) == NULL) /* FIX STDIO */
			{
				std::cerr << "Error: stdin fucked up!" << endl;
				return (-2); /* MOTHERFUCKER */
			}
			return (-1);
		}
		if (isValidNumber(input))
			result = atoi(input.c_str());
		else if (cin.good())
		{
			valid = true; /* OUT FROM LOOP */
			cin.clear(); /* ON ERROR: RESET BUFFER */
			cout << endl;
			cout << " \"" << input <<  "\" is not a number!" << endl;
			return (-1);
		}
		if (cin.good() && (result >= 0 && result <= 8))
			valid = true; /* OUT FROM LOOP */
		else
		{
			cin.clear(); /* ON ERROR: RESET BUFFER */
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid index; please re-enter." << endl;
		}
	} while (!valid);
	return (result);
}

void
	PhoneBook::search(void)
{
	register int	index;

	index = this->_readInput();
	if (index == -1)
		return ;
	if (index == -2)
	{
		this->stdio_error = true;
		return ;
	}
	this->_contacts[index].display(index);
}

static bool
	isValidNumber(const string &stringArg)
{
	register int	ecx;

	if (stringArg.empty())
		return (false);
	for (ecx = 0; !!stringArg[ecx]; ecx++)
		if (!std::isdigit(stringArg[ecx]))
			return (false);
	return (true);
}