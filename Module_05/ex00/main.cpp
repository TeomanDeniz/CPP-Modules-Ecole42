/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 09:29:11 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/02 02:07:23 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "Bureaucrat.hpp" /*
#  class Bureaucrat;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USING [v] ****************************** */
using std::cout;
using std::endl;
/* ***************************** [^] USING [^] ****************************** */

int
	main(void)
{
	try
	{
		Bureaucrat	bureaucrat("ash", 1);

		cout << bureaucrat << endl;
		bureaucrat.incrementGrade();
		// bureaucrat.decrementGrade();
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		cout << e.what() << endl;
	}
	return (EXIT_SUCCESS);
}
