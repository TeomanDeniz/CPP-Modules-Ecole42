/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 09:29:11 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/02 02:07:23 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( const std::string& name, int gradeToSign, int gradeToExecute ) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if ( gradeToSign < 1 || gradeToExecute < 1 )
        throw Form::GradeTooHighException();
    if ( gradeToSign > 150 || gradeToExecute > 150 )
        throw Form::GradeTooLowException();
}

Form::Form( const Form& src ) : _name( src.getName() ), _gradeToSign( src.getGradeToSign() ), _gradeToExecute( src.getGradeToExecute() ) {}

Form::~Form() {}

Form&   Form::operator=( const Form& rhs ) {
    if ( this != &rhs )
        _signed = rhs.getSigned();
    return *this;
}

std::string Form::getName() const {
    return _name;
}

bool   Form::getSigned() const {
    return _signed;
}

int   Form::getGradeToSign() const {
    return _gradeToSign;
}

int   Form::getGradeToExecute() const {
    return _gradeToExecute;
}

void    Form::beSigned(const Bureaucrat& bureaucrat) {
    if ( bureaucrat.getGrade() > _gradeToSign ) {
        throw Form::GradeTooLowException();
    }
    _signed = true;
}

std::ostream&   operator<<( std::ostream &o, const Form& rhs ) {
    o << "------------- Form Info -------------" << std::endl;
    o << "Form name: " << rhs.getName() << std::endl
      << "Grade to sign: " << rhs.getGradeToSign() << std::endl
      << "Grade to execute: " << rhs.getGradeToExecute() << std::endl;;
    return o;
}