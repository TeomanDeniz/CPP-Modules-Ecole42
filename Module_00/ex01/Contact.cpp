/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "Contact.hpp" /*
#  class Contact;
#*/
#include <iostream> /*
#namespc std;
#*/
# include <iomanip> /*
#     ??? std::setw(int);
#*/
#include <string> /*
#  class string;
#istream &std::getline(istream&, string&);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USING [v] ****************************** */
using std::cout;
using std::flush;
using std::endl;
using std::string;
/* ***************************** [^] USING [^] ****************************** */

Contact::Contact(void) /* CONSTRUCTOR */
{
	(void)0;
}

Contact::~Contact(void) /* DESTRUCTOR */
{
	(void)0;
}

string
	Contact::_getInput(string argString) const
{
	string	input;
	bool	valid;

	valid = false;
	input = string(1, '\0');
	do
	{
		cout << argString << flush;
		std::getline(std::cin, input);
		if (std::cin.good() && !input.empty())
			valid = true;
		else
		{
			std::cin.clear();
			cout << "Invalid input; please try again." << endl;
		}
	} while (!valid);
	return (input);
}

void
	Contact::init(void)
{
	std::cin.ignore();
	this->_firstName = this->_getInput("Please enter you first name: ");
	this->_lastName = this->_getInput("Please enter your last name: ");
	this->_nickname = this->_getInput("Please enter your nickname: ");
	this->_nickname = this->_getInput("Please enter your phone number: ");
	this->_nickname = this->_getInput("Please enter your darkest secret: ");
	cout << endl;
}

string
	Contact::_printLen(string argString) const
{
	if (argString.length() > 10)
		return (argString.substr(0, 9) + ".");
	return (argString);
}

void
	Contact::setIndex(int index)
{
	this->_index = index;
}

void
	Contact::view(int index) const
{
	if (this->_firstName.empty() || \
		this->_lastName.empty() || \
		this->_nickname.empty())
		return ;
	cout << "|" << std::setw(10) << index << flush;
	cout << "|" << std::setw(10) << this->_printLen(this->_firstName) << flush;
	cout << "|" << std::setw(10) << this->_printLen(this->_lastName) << flush;
	cout << "|" << std::setw(10) << this->_printLen(this->_nickname) << flush;
	cout << "|" << endl;
}

void
	Contact::display(int index) const
{
	if (this->_firstName.empty() || \
		this->_lastName.empty() || \
		this->_nickname.empty())
		return ;
	cout << endl;
	cout << "---->> CONTACT #" << index << " <<----" << endl;
	cout << "First Name:\t" << this->_firstName << endl;
	cout << "Last Name:\t" << this->_lastName << endl;
	cout << "Nickname:\t" << this->_nickname << endl;
	cout << endl;
}