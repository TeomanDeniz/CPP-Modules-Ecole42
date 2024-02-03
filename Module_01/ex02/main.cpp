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
#namespc std;
#*/
#include <cstdlib> /*
# define EXIT_SUCCESS;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USING [v] ****************************** */
using std::cout;
using std::string;
using std::endl;
/* ***************************** [^] USING [^] ****************************** */

int
	main(void)
{
	string str = "HI THIS IS BRAIN";
	string *stringPtr = &str;
	string &stringRef = str;

	cout << &str << ": " << str << endl;
	cout << stringPtr << ": " << *stringPtr << endl;
	cout << &stringRef << ": " << stringRef << endl;
	return (EXIT_SUCCESS);
}