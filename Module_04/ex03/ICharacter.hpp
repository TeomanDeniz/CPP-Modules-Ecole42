/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP 202402

/* **************************** [v] INCLUDES [v] **************************** */
# include "AMateria.hpp" /*
#   class AMateria;
# */
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

class AMateria;

class ICharacter
{
public: /* ************************* [v] PUBLIC [v] ************************* */
	virtual ~ICharacter(void)
	{
		(void)0;
	}
	virtual string const	&getName(void) const = 0;
	virtual void			equip(AMateria *m) = 0;
	virtual void			unequip(int idx) = 0;
	virtual void			use(int idx, ICharacter &target) = 0;
/* ***************************** [^] PUBLIC [^] ***************************** */

private: /* ************************ [v] PRIVATE [v] ************************ */
/* **************************** [^] PRIVATE [^] ***************************** */
};

#endif /* ICHARACTER_HPP */
