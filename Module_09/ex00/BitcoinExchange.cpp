/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "BitcoinExchange.hpp" /*
#  class BitcoinExchange;
#        */
#include <iostream> /*
#nmspace std;
#        */
#include <string> /*
#  class std::string;
#istream &std::getline(istream &, string &, char);
#        */
#include <sstream> /*
#   T <> stringstream;
#        */
#include <fstream> /*
#   T <> ifstream;
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USINGS [v] ***************************** */
using std::string;
using std::cout;
using std::endl;
using std::stringstream;
using std::getline;
using std::ifstream;
/* ***************************** [^] USINGS [^] ***************************** */

/* ************************** [v] CONSTRUCTOR [v] *************************** */
BitcoinExchange::BitcoinExchange(void)
{
	readData();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	*this = copy;
}
/* ************************** [^] CONSTRUCTOR [^] *************************** */

/* *************************** [v] DESTRUCTOR [v] *************************** */
BitcoinExchange::~BitcoinExchange(void){}
/* *************************** [^] DESTRUCTOR [^] *************************** */

/* **************************** [v] OPERATOR [v] **************************** */
BitcoinExchange
	&BitcoinExchange::operator = (const BitcoinExchange &other)
{ /* OPERATOR "=" */
	if (this != &other)
		this->_data = other._data;

	return (*this);
}
/* **************************** [^] OPERATOR [^] **************************** */

void
	BitcoinExchange::readData(void)
{
	ifstream		dataFile("data.csv");
	string			line;
	string			key;
	string			value;
	int				pos;

	if (!dataFile.is_open())
		throw std::runtime_error("File not found");

	getline(dataFile, line);

	while (getline(dataFile, line))
	{
		pos = line.find(",");
		if (pos == (int)string::npos)
			throw std::runtime_error("Invalid data format");
		key = line.substr(0, pos);
		value = line.substr(pos + 1);
		this->_data[key] = my_stod(value);
	}

	dataFile.close();
}

void
	BitcoinExchange::readInput(const string &file)
{
	ifstream	inputFile(file.c_str());
	string		line;
	string		key;
	string		value;
	int			pos;

	if (!inputFile.is_open())
		throw std::runtime_error("File not found");

	getline(inputFile, line);
	checkFileFormat(line);

	while (getline(inputFile, line))
	{
		pos = line.find("|");

		if (pos == (int)string::npos)
		{
			cout << "Error: bad input => " << line << endl;
			continue ;
		}

		key = trim(line.substr(0, pos));

		if (key.length() == 0)
		{
			cout << "Error: bad input => " << line << endl;
			continue ;
		}

		value = trim(line.substr(pos + 1));

		if (value.length() == 0)
		{
			cout << "Error: bad input => " << key << endl;
			continue ;
		}

		if (!checkInputFormat(key, value))
			continue ;

		double	mult = findRate(key, this->_data, my_stod(value));
		cout << key << " => " << value << " = " << mult << endl;
	}

	inputFile.close();
}

void
	BitcoinExchange::checkFileFormat(const string &format)
{
	if (format != "date | value")
		throw std::runtime_error("Invalid file format");
}

string
	BitcoinExchange::trim(const string &str)
{
	int	first;
	int	last;

	first = str.find_first_not_of(" \t\n\r");
	last = str.find_last_not_of(" \t\n\r");

	if (first == (int)string::npos || last == (int)string::npos)
		return "";

	return (str.substr(first, last - first + 1));
}

int
	BitcoinExchange::checkInputFormat(const string &key, const string &value)
{
	int				year;
	int				month;
	int				day;
	char			separator1;
	char			separator2;
	stringstream	ss(key);

	if (key.length() != 10)
	{
		cout << "Error: bad input => " << key << endl;
		return (0);
	}

	if (key.find_first_not_of("0123456789-") != string::npos)
	{
		cout << "Error: bad input => " << key << endl;
		return (0);
	}

	ss >> year >> separator1 >> month >> separator2 >> day;

	if (
		ss.fail() ||
		separator1 != '-' ||
		separator2 != '-' ||
		(year == 2009 && month == 1 && day == 1) ||
		year < 2009 ||
		month < 1 || month > 12 ||
		day < 1 || day > 31
	)
	{
		cout << "Error: bad input => " << key << endl;
		return (0);
	}

	if (!checkDataSpecialFormat(year, month, day))
	{
		cout << "Error: bad input => " << key << endl;
		return (0);
	}

	if (value.find_first_not_of("0123456789.-+") != string::npos)
	{
		cout << "Error: bad input => " << value << endl;
		return (0);
	}

	if (is_stod(value))
	{
		cout << "Error: bad input => " << value << endl;
		return (0);
	}

	if (my_stod(value) < 0)
	{
		cout << "Error: not a positive number. " << endl;
		return (0);
	}

	if (my_stod(value) > 1000)
	{
		cout << "Error: too large a number." << endl;
		return (0);
	}

	return (1);
}

int
	BitcoinExchange::checkDataSpecialFormat(int year, int month, int day)
{
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
	{
		if (month == 2 && day > 29)
			return (0); // FALSE
	}
	else
	{
		if (month == 2 && day > 28)
			return (0); // FALSE
	}

	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return (0); // FALSE

	return (1);
}

int
	BitcoinExchange::is_stod(const string &str)
{
	stringstream	ss(str);
	double			result;

	ss >> result;
	return (ss.fail() || !ss.eof());
}

double
	BitcoinExchange::my_stod(const string &str)
{
	double			result;
	stringstream	ss(str);

	ss >> result;
	return (result);
}

double
	BitcoinExchange::findRate(string date, map <string, double> data, \
double value)
{
	map <string, double>::iterator it = data.upper_bound(date);

	if (it != data.begin())
		return ((--it)->second * value);

	return(0);
}
