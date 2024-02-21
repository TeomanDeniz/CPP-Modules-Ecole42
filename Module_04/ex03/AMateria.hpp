/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP 202402

/* **************************** [v] INCLUDES [v] **************************** */
# include "ICharacter.hpp" /*
#   class ICharacter;
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

class ICharacter;

class AMateria
{
public: /* ************************* [v] PUBLIC [v] ************************* */
	AMateria(void);
	AMateria(string const &type);
	AMateria(AMateria const &src);
	virtual ~AMateria(void);
	string const		&getType(void) const;
	virtual AMateria	*clone(void) const = 0;
	virtual void		use(ICharacter &target);
/* ***************************** [^] PUBLIC [^] ***************************** */

protected: /* ********************** [v] PROTECTED [v] ********************** */
	string	_type;
/* *************************** [^] PROTECTED [^] **************************** */
};

#endif /* AMATERIA_HPP */
