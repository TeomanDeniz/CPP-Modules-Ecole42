/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP 202402

/* **************************** [v] INCLUDES [v] **************************** */
# include "ClapTrap.hpp" /*
#   class ClapTrap;
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

class ScavTrap : public ClapTrap
{
public: /* ************************* [v] PUBLIC [v] ************************* */
	ScavTrap(string name);
	~ScavTrap(void);
	void	attack(string const &target);
	void	guardGate(void);
/* ***************************** [^] PUBLIC [^] ***************************** */

private: /* ************************ [v] PRIVATE [v] ************************ */
	ScavTrap(void);
/* **************************** [^] PRIVATE [^] ***************************** */
};

#endif /* SCAVTRAP_HPP */
