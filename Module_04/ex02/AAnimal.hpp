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

#ifndef AANIMAL_HPP
# define AANIMAL_HPP 202402

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

class AAnimal
{
public: /* ************************* [v] PUBLIC [v] ************************* */
	AAnimal(void);
	AAnimal(string type);
	AAnimal(const AAnimal &src);
	virtual ~AAnimal(void);
	AAnimal			&operator = (const AAnimal &rhs);
	virtual void	makeSound(void) const = 0;;
	string			getType(void) const; 
/* ***************************** [^] PUBLIC [^] ***************************** */

protected: /* ********************** [v] PROTECTED [v] ********************** */
	string	_type;
/* *************************** [^] PROTECTED [^] **************************** */
};

#endif /* AANIMAL_HPP */
