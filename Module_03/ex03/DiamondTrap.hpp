/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP 202402

/* **************************** [v] INCLUDES [v] **************************** */
# include "FragTrap.hpp" /*
#   class FragTrap;
# */
# include "ScavTrap.hpp" /*
#   class ScavTrap;
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

class DiamondTrap : public FragTrap, public ScavTrap
{
public: /* ************************* [v] PUBLIC [v] ************************* */
	DiamondTrap(string name);
	~DiamondTrap(void);
	using	ScavTrap::attack;
	void	whoAmI(void);
/* ***************************** [^] PUBLIC [^] ***************************** */

private: /* ************************ [v] PRIVATE [v] ************************ */
	string	_name;
/* **************************** [^] PRIVATE [^] ***************************** */
};

#endif /* DIAMONDTRAP_HPP */
