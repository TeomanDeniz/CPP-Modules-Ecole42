/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP 202402

/* **************************** [v] INCLUDES [v] **************************** */
# include "AMateria.hpp" /*
#   class AMateria;
# */
# include "IMateriaSource.hpp" /*
#   class IMateriaSource;
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

class MateriaSource : public IMateriaSource
{
public: /* ************************* [v] PUBLIC [v] ************************* */
	MateriaSource(void);
	MateriaSource(MateriaSource const &src);
	~MateriaSource(void);
	MateriaSource	&operator = (MateriaSource const &rhs);
	AMateria		*getMateria(string const &type);
	AMateria		*createMateria(string const &type);
	void			learnMateria(AMateria *m);
/* ***************************** [^] PUBLIC [^] ***************************** */

private: /* ************************ [v] PRIVATE [v] ************************ */
	AMateria	*materias[4];
/* **************************** [^] PRIVATE [^] ***************************** */
};

#endif /* MATERIASOURCE_HPP */
