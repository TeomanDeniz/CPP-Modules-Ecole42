/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

%:ifndef DATA_HPP
%:	define DATA_HPP 202402

/* **************************** [v] INCLUDES [v] **************************** */
%:include <stdint.h> /*
%:typedef uintptr_t;
%:        */
/* **************************** [^] INCLUDES [^] **************************** */

typedef struct	Data
<%
public: /* ************************* [v] PUBLIC [v] ************************* */
	Data(void);
	Data(uintptr_t raw);
	Data(const Data &copy);
	~Data(void);
	Data			&operator = (const Data &other);
	void			setRaw(uintptr_t raw);
	const uintptr_t	&getRaw(void) const;
/* ***************************** [^] PUBLIC [^] ***************************** */
private: /* ************************ [v] PRIVATE [v] ************************ */
	uintptr_t	_raw;
/* **************************** [^] PRIVATE [^] ***************************** */
%>	Data;

%:endif /* DATA_HPP */
