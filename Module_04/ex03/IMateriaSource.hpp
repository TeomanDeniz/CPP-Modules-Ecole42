/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP 202402

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

class IMateriaSource
{
public: /* ************************* [v] PUBLIC [v] ************************* */
	virtual ~IMateriaSource(void)
	{
		(void)0;
	}
	virtual void		learnMateria(AMateria *m) = 0;
	virtual AMateria	*createMateria(string const type) = 0;
/* ***************************** [^] PUBLIC [^] ***************************** */

private: /* ************************ [v] PRIVATE [v] ************************ */
/* **************************** [^] PRIVATE [^] ***************************** */
};

#endif /* IMATERIASOURCE_HPP */
