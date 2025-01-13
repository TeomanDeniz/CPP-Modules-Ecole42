/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#	define BITCOINEXCHANGE_HPP 202402

/* **************************** [v] INCLUDES [v] **************************** */
#	include <iostream> /*
#	nmspace std;
#	        */
#	include <string> /*
#	  class std::string;
#	        */
#	include <map> /*
#	   T <> std::map;
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USINGS [v] ***************************** */
using std::string;
using std::map;
/* ***************************** [^] USINGS [^] ***************************** */

class BitcoinExchange
{
public: /* ************************* [v] PUBLIC [v] ************************* */
	BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange	&operator=(const BitcoinExchange &other);
	~BitcoinExchange(void);
	void	readData(void);
	void	readInput(const string &file);
	void	checkFileFormat(const string &format);
	string	trim(const string &str);
	int		checkInputFormat(const string &key, const string &value);
	int		checkDataSpecialFormat(int year, int month, int day);
	int		is_stod(const string &str);
	double	my_stod(const string &str);
	double	findRate(string date, map<string, double> data, double value);
/* ***************************** [^] PUBLIC [^] ***************************** */
private: /* ************************ [v] PRIVATE [v] ************************ */
	map<string, double> _data;
/* **************************** [^] PRIVATE [^] ***************************** */
};

#endif /* BITCOINEXCHANGE_HPP */
