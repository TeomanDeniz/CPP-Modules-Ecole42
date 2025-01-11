/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#	define SCALARCONVERTER_HPP 202402

/* **************************** [v] INCLUDES [v] **************************** */
#	include <iostream> /*
#	nmspace std;
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] MACROS [v] ***************************** */
#	define UNION_SPECIAL  1
#	define UNION_CHAR     2
#	define UNION_INT      3
#	define UNION_FLOAT    4
#	define UNION_DOUBLE   5
#	define UNION_ERROR    6
#	define DIGIT_SET  "+-0123456789"
#	define DOUBLE_SET "+-0123456789."
#	define FLOAT_SET  "+-0123456789.f"
/* ***************************** [^] MACROS [^] ***************************** */

/* ***************************** [v] USINGS [v] ***************************** */
using std::string;
/* ***************************** [^] USINGS [^] ***************************** */

class ScalarConverter
{
public: /* ************************* [v] PUBLIC [v] ************************* */
	static void	convert(const string &arg);
/* ***************************** [^] PUBLIC [^] ***************************** */
private: /* ************************ [v] PRIVATE [v] ************************ */
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter &copy);
	ScalarConverter	&operator = (const ScalarConverter &other);
	~ScalarConverter(void);
	static int	parseInput(const string &input);
	static int	isSpecial(const string &input);
	static int	isSpecialChar(const string &input);
	static int	hasInvalidSignal(const string &input);
	static int	isChar(const string &input);
	static int	isInt(const string &input);
	static int	isDouble(const string &input);
	static int	isInvalidDouble(const string &input);
	static int	isFloat(const string &input);
	static int	isInvalidFloat(const string &input);
	static void	fromChar(int type, const string &input);
	static void	fromInt(int type, const string &input);
	static void	fromFloat(int type, const string &input);
	static void	fromDouble(int type, const string &input);
	static void	printChar(int type, int i, char c);
	static void	printInt(int type, const string &input, int i);
	static void	printFloat(int type, const string &input, float f);
	static void	printDouble(int type, const string &input, double d);
	static void	printSpecial(const string type, const string &input);
	static void	print(int type, const string &input, char c, int i, \
		float f, double d);
/* **************************** [^] PRIVATE [^] ***************************** */
};

#endif /* SCALARCONVERTER_HPP */
