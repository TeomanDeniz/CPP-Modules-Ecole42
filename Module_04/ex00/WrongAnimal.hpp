/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP 202402

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

class WrongAnimal
{
public: /* ************************* [v] PUBLIC [v] ************************* */
	WrongAnimal(void);
	WrongAnimal(string type);
	WrongAnimal(const WrongAnimal &src);
	~WrongAnimal(void);
	WrongAnimal	&operator = (const WrongAnimal &rhs);
	void		makeSound(void) const;
	string		getType(void) const;
/* ***************************** [^] PUBLIC [^] ***************************** */

protected: /* ********************** [v] PROTECTED [v] ********************** */
	string	_type;
/* *************************** [^] PROTECTED [^] **************************** */
};

#endif /* WRONGANIMAL_HPP */
