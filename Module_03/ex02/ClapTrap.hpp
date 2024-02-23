/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP 202402

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

class ClapTrap
{
public: /* ************************* [v] PUBLIC [v] ************************* */
	ClapTrap(string name);
	~ClapTrap(void);
	ClapTrap(const ClapTrap &rhs);
	ClapTrap	&operator = (const ClapTrap &rhs);
	void		attack(string const &target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
/* ***************************** [^] PUBLIC [^] ***************************** */

protected: /* ********************** [v] PROTECTED [v] ********************** */
	string			_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;
	ClapTrap(void);
/* *************************** [^] PROTECTED [^] **************************** */
};

#endif /* CLAPTRAP_HPP */
