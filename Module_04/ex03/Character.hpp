/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP 202402

/* **************************** [v] INCLUDES [v] **************************** */
# include "ICharacter.hpp" /*
#   class ICharacter;
# */
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

class Character : public ICharacter
{
public: /* ************************* [v] PUBLIC [v] ************************* */
	Character(string const &name);
	Character(Character const &src);
	~Character(void);
	Character			&operator = (Character const &rhs);
	string const		&getName(void) const;
	void				equip(AMateria *m);
	void				unequip(int idx);
	void				use(int idx, ICharacter &target);
/* ***************************** [^] PUBLIC [^] ***************************** */

private: /* ************************ [v] PRIVATE [v] ************************ */
	string		_name;
	AMateria	*_inventory[4];
/* **************************** [^] PRIVATE [^] ***************************** */
};

#endif /* CHARACTER_HPP */
