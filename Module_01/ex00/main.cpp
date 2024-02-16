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
#include "Zombie.hpp" /*
#  class Zombie;
# Zombie *newZombie(string);
#   voie randomChump(string);
#*/
#include <iostream> /*
#namespc std;
#*/
#include <cstdlib> /*
# define EXIT_SUCCESS;
#*/
#include <string> /*
#  class std::string;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USING [v] ****************************** */
using std::cout;
using std::cin;
using std::flush;
using std::string;
using std::endl;
/* ***************************** [^] USING [^] ****************************** */

int
	main(void)
{
	string	name;

	cout << "Creating zombie on the stack." << endl;
	cout << "Zombie name: " << flush;
	cin >> name;
	{
		Zombie zombi1(name);
	}
	cout << "Creating zombie on the heap." << endl;
	cout << "Zombie name: " << flush;
	cin >> name;
	Zombie *zombie2 = newZombie(name);
	zombie2->announce();
	delete zombie2;
	cout << "Calling randomChump()." << endl;
	randomChump("randi");
	return (EXIT_SUCCESS);
}