/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#	define EASYFIND_HPP 202402

/* **************************** [v] INCLUDES [v] **************************** */
#	include <iostream> /*
#	nmspace std;
#	        */
#	include <vector> /*
#	  class std::vector;
#	        */
#	include <list> /*
#	  class std::list;
#	        */
#	include <deque> /*
#	  class std::deque;
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USINGS [v] ***************************** */
using std::out_of_range;
using std::find;
using std::cout;
using std::endl;
/* ***************************** [^] USINGS [^] ***************************** */

template <typename T>
void
	easyfind(const T &container, int value)
{
	typename T::const_iterator	it;
	typename T::const_iterator	end;

	end = container.end();
	it = find(container.begin(), container.end(), value);

	if (it == end)
		throw out_of_range("Not Found");
	else
		cout << "value " << *it << " found" << endl;
}

#endif /* EASYFIND_HPP */
