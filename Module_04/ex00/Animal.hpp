/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Virtual destructor:
	A virtual destructor is used to free up the memory space allocated by 
	the derived class object or instance while deleting instances of the derived
	class using a base class pointer object. A base or parent class destructor
	use the virtual keyword that ensures both base class and the derived class 
	destructor will be called at run time, but it called the derived class first
	and then base class to release the space occupied by both destructors.
	Every destructor down gets called no matter what. virtual makes sure it
	starts at the top instead of the middle.
	Virtual destructors are useful when you might potentially delete an instance 
	of a derived class through a pointer to base class:
*/

#ifndef ANIMAL_HPP
# define ANIMAL_HPP 202402

/* **************************** [v] INCLUDES [v] **************************** */
# include <iostream> /*
# namespc std;
# */
# include <string> /*
#   class std::string;
# */
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USING [v] ****************************** */
using std::string;
/* ***************************** [^] USING [^] ****************************** */

class Animal
{
public: /* ************************* [v] PUBLIC [v] ************************* */
	Animal(void);
	Animal(string type);
	Animal(const Animal &src);
	virtual			~Animal(void);
	Animal			&operator = (const Animal &rhs);
	virtual void	makeSound(void) const;
	string			getType(void) const;
/* ***************************** [^] PUBLIC [^] ***************************** */

protected: /* ********************** [v] PROTECTED [v] ********************** */
	string	_type;
/* *************************** [^] PROTECTED [^] **************************** */

};

#endif /* ANIMAL_HPP */
