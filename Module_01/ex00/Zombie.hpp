/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP 202402

/* **************************** [v] INCLUDES [v] **************************** */
# include <iostream> /*
# namespc std;
# */
# include <string> /*
#   class string;
# */
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USING [v] ****************************** */
using std::string;
/* ***************************** [^] USING [^] ****************************** */

class Zombie
{
public: /* ************************* [v] PUBLIC [v] ************************* */
	Zombie(string name);
	~Zombie(void);
	void	announce(void);
	Zombie	*newZombie(string name);
	void	randomChump(string name);
/* ***************************** [^] PUBLIC [^] ***************************** */

private: /* ************************ [v] PRIVATE [v] ************************ */
	string	_name;
/* **************************** [^] PRIVATE [^] ***************************** */
};

/* *************************** [v] PROTOTYPES [v] *************************** */
extern Zombie	*newZombie(string name);
extern void		randomChump(string name);
/* *************************** [^] PROTOTYPES [^] *************************** */

#endif /* ZOMBIE_HPP */