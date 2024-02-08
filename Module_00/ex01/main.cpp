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
#include "PhoneBook.hpp" /*
#  class PhoneBook;
#*/
#include <iostream> /*
#namespc std;
#*/
#include <cstdlib> /*
# define EXIT_SUCCESS;
#*/
#include <string> /*
#  class string;
#istream &std::getline(istream&, string&);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USING [v] ****************************** */
using std::cout;
using std::cin;
using std::flush;
using std::string;
/* ***************************** [^] USING [^] ****************************** */

static void
	toLowercase(string &stringArg)
{
	register int	ecx;

	if (stringArg.empty())
		return ;
	for (ecx = 0; !!stringArg[ecx]; ecx++)
		if (stringArg[ecx] >= 'A' && stringArg[ecx] <= 'Z')
			stringArg[ecx] += 'a' - 'A';
}

int
	main(void)
{
	PhoneBook	book;
	string		input;

	book.stdio_error = false;
	book.welcome();
	loop:
		cout << "> " << flush;
		std::getline(cin, input);
		toLowercase(input);
		if (!input.compare("add"))
			book.addContact();
		else if (!input.compare("search"))
		{
			book.printContacts();
			book.search();
		}
		if (!input.compare("exit") || (!std::cin.good() && input.empty()) || \
			book.stdio_error)
			goto exit;
	goto loop;
	exit:
	return (EXIT_SUCCESS);
}