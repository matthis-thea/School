/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:43:16 by haze              #+#    #+#             */
/*   Updated: 2023/11/21 14:42:05 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void):  _name("Francis"),_Issigned(false), _grade_sign(50), _grade_execute(50)
{
	std::cout << "Form constructor was created" << std::endl;
}

Form::Form(const int grade_sign, const std::string name, const int grade_exec):_name(name), _grade_sign(grade_sign), _grade_execute(grade_exec)
{
	if (grade_exec > 150)
		throw Form::GradeTooLowException();
	if (grade_exec < 1)
		throw Form::GradeTooHighException();
	if (grade_sign > 150)
		throw Form::GradeTooLowException();
	if (grade_sign < 1)
		throw Form::GradeTooHighException();
	std::cout << "Form constructor was created" << std::endl;
	this->_Issigned = false;
}

Form::Form(const Form &src): _name(src.GetName()), _grade_sign(src.GetGradeSign()), _grade_execute(src.GetGradeExecute())
{
	std::cout << "Form Copy constructor called" << std::endl;
}


Form& Form::operator=( const Form &src) 
{
    if ( this != &src )
        _Issigned = src.GetSigned();
    return *this;
}


Form::~Form(void)
{
	std::cout << "Form deconstructor was created" << std::endl;
}


std::string Form::GetName() const 
{
    return _name;
}

bool   Form::GetSigned() const {
    return _Issigned;
}

int   Form::GetGradeSign() const 
{
    return _grade_sign;
}

int   Form::GetGradeExecute() const 
{
    return _grade_execute;
}

void    Form::beSigned(const Bureaucrat &src) {
    if ( src.getGrade() > this->_grade_sign)
        throw Form::GradeTooLowException();
    _Issigned = true;
}

std::ostream&   operator<<( std::ostream& o, const Form& src) 
{
    o << "------------- Form Info -------------" << std::endl;
    o << "Form name: " << src.GetName() << std::endl
      << "Grade to sign: " << src.GetGradeSign() << std::endl
      << "Grade to execute: " << src.GetGradeExecute();
    return o;
}

const char * Form::GradeTooHighException::what() const throw ()
{
	return ("Your Grade is too High");
}

const char * Form::GradeTooLowException::what() const throw ()
{
	return ("Your Grade is too Low");
}