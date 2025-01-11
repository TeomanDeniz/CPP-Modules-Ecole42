/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:00:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/02/01 18:00:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#	define ARRAY_TPP 202402

/* **************************** [v] INCLUDES [v] **************************** */
#	include <iostream> /*
#	nmspace std;
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
class Array;
/* *************************** [^] PROTOTYPES [^] *************************** */

/* ***************************** [v] USINGS [v] ***************************** */
using std::cout;
using std::endl;
using std::ostream;
/* ***************************** [^] USINGS [^] ***************************** */

/* ************************** [v] CONSTRUCTOR [v] *************************** */
template <typename T>
Array <T>::Array(void)
	: _array(0), _size(0)
{
	cout << "Default constructor called (Array<T>)" << endl;
}

template <typename T>
Array <T>::Array(unsigned int n)
	: _array(new T[n]), _size(n)
{
	cout << "Parameterized constructor called (Array<T>)" << endl;
}

template <typename T>
Array <T>::Array(const Array<T> &copy)
	: _array(new T[copy.size()]), _size(copy.size())
{
	unsigned int	i;

	cout << "Copy constructor called (Array<T>)" << endl;

	for (i = 0; i < copy.size(); i++)
		this->_array[i] = copy._array[i];
}
/* ************************** [^] CONSTRUCTOR [^] *************************** */

/* *************************** [v] DESTRUCTOR [v] *************************** */
template <typename T>
Array <T>::~Array(void)
{
	cout << "Destructor called (Array<T>)" << endl;
	delete[] this->_array;
}
/* *************************** [^] DESTRUCTOR [^] *************************** */

/* **************************** [v] OPERATOR [v] **************************** */
template <typename T>
Array <T>
	&Array<T>::operator = (const Array <T> &other) /* OPERATOR "=" */
{
	unsigned int	i;

	cout << "Assignment operator called (Array <T>)" << endl;

	if (this != &other)
	{
		delete[] this->_array;
		this->_array = new T[other.size()];
		this->_size = other.size();

		for (i = 0; i < other.size(); i++)
			this->_array[i] = other._array[i];
	}

	return (*this);
}

template <typename T>
T
	&Array<T>::operator [] (const unsigned int index) /* OPERATOR "[]" */
{
	if (index >= this->_size)
		throw Array <T>::OutOfBoundsException();

	return (this->_array[index]);
}

template<typename T>
ostream
	&operator << (ostream &out, const Array<T> &arr) /* OPERATOR "<<" */
{
	int	i;

	for (i = 0; i < arr.size(); i++)
		out << "[" << arr[i] << "]";

	return (out);
}
/* **************************** [^] OPERATOR [^] **************************** */

/* ************************ [v] THROW EXPECTIONS [v] ************************ */
template <typename T>
const char
	*Array<T>::OutOfBoundsException::what() const throw()
{
	return ("index out of bounds");
}
/* ************************ [^] THROW EXPECTIONS [^] ************************ */

template <typename T>
const int
	&Array<T>::size(void) const
{
	return (this->_size);
}

#endif /* ARRAY_TPP */
