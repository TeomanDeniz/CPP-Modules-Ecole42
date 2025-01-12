/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "ScalarConverter.hpp" /*
# define UNION_SPECIAL
# define UNION_CHAR
# define UNION_INT
# define UNION_FLOAT
# define UNION_DOUBLE
# define UNION_ERROR
# define DIGIT_SET
# define DOUBLE_SET
# define FLOAT_SET
#  class ScalarConverter;
#        */
#include <iostream> /*
#nmspace std;
#        */
#include <limits.h> /*
# define UCHAR_MAX
# define INT_MIN
# define INT_MAX
#        */
#include <iomanip> /*
#  class std::setprecision;
#        */
#include <sstream> /*
#  class std::stringstream;
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] USINGS [v] ***************************** */
using std::string;
using std::cout;
using std::endl;
/* ***************************** [^] USINGS [^] ***************************** */

/* ************************** [v] CONSTRUCTOR [v] *************************** */
ScalarConverter::ScalarConverter(void){}

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
	*this = other;
}
/* ************************** [^] CONSTRUCTOR [^] *************************** */

/* *************************** [v] DESTRUCTOR [v] *************************** */
ScalarConverter::~ScalarConverter(void){}
/* *************************** [^] DESTRUCTOR [^] *************************** */

/* **************************** [v] OPERATOR [v] **************************** */
ScalarConverter
	&ScalarConverter::operator = (ScalarConverter const &other)
{ /* OPERATOR "=" */
	(void)other;
	return (*this);
}
/* **************************** [^] OPERATOR [^] **************************** */

void
	ScalarConverter::convert(const string &input)
{
	const int	type = ScalarConverter::parseInput(input);

	switch (type)
	{
		case (UNION_SPECIAL):
		{
			ScalarConverter::fromDouble(type, input);
			break ;
		}
		case (UNION_CHAR):
		{
			ScalarConverter::fromChar(type, input);
			break ;
		}
		case (UNION_INT):
		{
			ScalarConverter::fromInt(type, input);
			break ;
		}
		case (UNION_FLOAT):
		{
			ScalarConverter::fromFloat(type, input);
			break ;
		}
		case (UNION_DOUBLE):
		{
			ScalarConverter::fromDouble(type, input);
			break ;
		}
		default:
		{
			cout << "Error: Impossible to print or input not convertable";
			cout << endl;
			break ;
		}
	}
}

int
	ScalarConverter::parseInput(const string &input)
{
	if (isSpecial(input))
		return (UNION_SPECIAL);
	else if (isSpecialChar(input))
		return (UNION_CHAR);
	else if (hasInvalidSignal(input))
		return (UNION_ERROR);
	else if (isInt(input))
		return (UNION_INT);
	else if (isDouble(input))
	{
		if (isInvalidDouble(input))
			return (UNION_ERROR);

		return (UNION_DOUBLE);
	}
	else if (isFloat(input))
	{
		if (isInvalidFloat(input))
			return (UNION_ERROR);

		return (UNION_FLOAT);
	}
	else if (isChar(input))
		return (UNION_CHAR);

	return (UNION_ERROR);
}

int
	ScalarConverter::isSpecial(const string &input)
{
	return (
		input == "nan" ||
		input == "nanf" ||
		input == "+inf" ||
		input == "-inf" ||
		input == "+inff" ||
		input == "-inff" ||
		input == "inf" ||
		input == "inff"
	);
}

int
	ScalarConverter::isSpecialChar(const string &input)
{
	return (
		input.length() == 1 &&
		(
			input[0] == '+' ||
			input[0] == '-' ||
			input[0] == '.' ||
			input[0] == 'f'
		)
	);
}

int
	ScalarConverter::hasInvalidSignal(const string &input)
{
	return (input.find_first_of("+-") != input.find_last_of("+-"));
}

int
	ScalarConverter::isInt(const string &input)
{
	return (input.find_first_not_of(DIGIT_SET) == string::npos);
}

int
	ScalarConverter::isDouble(const string &input)
{
	return (input.find_first_not_of(DOUBLE_SET) == string::npos);
}

int
	ScalarConverter::isInvalidDouble(const string &input)
{
	return (
		input.find_first_of(".") != input.find_last_of(".") ||
		isdigit(input[input.find_first_of(".") + 1]) == 0 ||
		input.find_first_of(".") == 0
	);
}
int
	ScalarConverter::isFloat(const string &input)
{
	return (input.find_first_not_of(FLOAT_SET) == string::npos);
}

int
	ScalarConverter::isInvalidFloat(const string &input)
{
	return (
		input.find_first_of("f") != input.find_last_of("f") ||
		input.find_first_of(".") != input.find_last_of(".") ||
		input.find_first_of("f") - input.find_first_of(".") == 1 ||
		isdigit(input[input.find_first_of(".") + 1]) == 0 ||
		input.find_first_of(".") == 0
	);
}

int
	ScalarConverter::isChar(const string &input)
{
	return (input.length() == 1 && isprint(input[0]));
}

void
	ScalarConverter::fromChar(int type, const string &input)
{
	std::stringstream	ss(input.c_str());
	char				c;

	ss >> c;

	const int		i = static_cast <int>(c);
	const float		f = static_cast <float>(c);
	const double	d = static_cast <double>(c);

	ScalarConverter::print(type, input, c, i, f, d);
}

void
	ScalarConverter::fromInt(int type, const string &input)
{
	std::stringstream	ss(input.c_str());
	int					i;

	ss >> i;

	const char		c = static_cast <unsigned char>(i);
	const float		f = static_cast <float>(i);
	const double	d = static_cast <double>(i);

	ScalarConverter::print(type, input, c, i, f, d);
}

void
	ScalarConverter::fromFloat(int type, const string &input)
{
	std::stringstream	ss(input.c_str());
	float				f;

	ss >> f;

	const int		i = static_cast <int>(f);
	const char		c = static_cast <unsigned char>(f);
	const double	d = static_cast <float>(f);

	ScalarConverter::print(type, input, c, i, f, d);
}

void
	ScalarConverter::fromDouble(int type, const string &input)
{
	std::stringstream	ss(input.c_str());
	double				d;

	ss >> d;

	const int		i = static_cast <int>(d);
	const char		c = static_cast <unsigned char>(d);
	const float		f = static_cast <float>(d);

	ScalarConverter::print(type, input, c, i, f, d);
}

void
	ScalarConverter::printChar(int type, int i, char c)
{
	if (type == UNION_SPECIAL || i < 0 || i > UCHAR_MAX)
	{
		cout << "char: impossible" << endl;
		return ;
	}

	if (isprint(i))
		cout << "char: \'" << c << "\'" << endl;
	else
		cout << "char: Non displayable" << endl;
}

void
	ScalarConverter::printInt(int type, const string &input, int i)
{
	std::stringstream	ss(input.c_str());
	double				check;

	ss >> check;

	if (
		!ss.fail() ||
		(
			type != UNION_SPECIAL && (check >= INT_MIN && check <= INT_MAX)
		)
	)
		cout << "int: " << i << endl;
	else
		cout << "int: impossible" << endl;
}

void
	ScalarConverter::printSpecial(const string type, const string &input)
{
	if (input == "nan" || input == "nanf")
	{
		cout << type << ": nan";

		if (type == "float")
			cout << "f";

		cout << endl;
	}
	else if (input == "+inf" || input == "+inff")
	{
		cout << type << ": +inf";

		if (type == "float")
			cout << "f";

		cout << endl;
	}
	else if (input == "-inf" || input == "-inff")
	{
		cout << type << ": -inf";

		if (type == "float")
			cout << "f";

		cout << endl;
	}
	else if (input == "inf" || input == "inff")
	{
		cout << type << ": inf";

		if (type == "float")
			cout << "f";

		cout << endl;
	}
}

void
	ScalarConverter::printFloat(int type, const string &input, float f, int i)
{
	std::stringstream	ss(input.c_str());
	double				check;

	if (type == UNION_SPECIAL)
	{
		printSpecial("float", input);
		return ;
	}

	if (type == UNION_CHAR)
		check = static_cast <double> (i);
	else
		ss >> check;

	if (
		ss.fail() ||
		(
			type == UNION_INT && (check < INT_MIN || check > INT_MAX)
		)
	)
		cout << "float: impossible" << endl;
	else
		cout << "float: " << std::fixed << std::setprecision(1) << f << "f" \
			<< endl;
}

void
	ScalarConverter::printDouble(int type, const string &input, double d, int i)
{
	std::stringstream	ss(input.c_str());
	double				check;

	if (type == UNION_SPECIAL)
	{
		printSpecial("double", input);
		return ;
	}

	if (type == UNION_CHAR)
		check = static_cast <double> (i);
	else
		ss >> check;

	if (
		ss.fail() ||
		(
			type == UNION_INT && (check < INT_MIN || check > INT_MAX)
		)
	)
		cout << "double: impossible" << endl;
	else
		cout << "double: " << std::fixed << std::setprecision(1) << d << endl;
}

void
	ScalarConverter::print(int type, const string &input, char c, int i, \
float f, double d)
{
	printChar(type, i, c);
	printInt(type, input, i);
	printFloat(type, input, f, i);
	printDouble(type, input, d, i);
}
