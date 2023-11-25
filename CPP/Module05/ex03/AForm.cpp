/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:43:16 by haze              #+#    #+#             */
/*   Updated: 2023/11/25 14:26:49 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void):  _name("Francis"), _target("Personne"), _Issigned(false), _grade_sign(50), _grade_execute(50)
{
	std::cout << "AForm constructor was created" << std::endl;
}

AForm::AForm(const int grade_sign, const std::string name,  const std::string target, const int grade_exec):_name(name), _target(target), _grade_sign(grade_sign), _grade_execute(grade_exec)
{
	if (grade_exec > 150)
		throw AForm::GradeTooLowException();
	if (grade_exec < 1)
		throw AForm::GradeTooHighException();
	if (grade_sign > 150)
		throw AForm::GradeTooLowException();
	if (grade_sign < 1)
		throw AForm::GradeTooHighException();
	std::cout << "AForm constructor was created" << std::endl;
	this->_Issigned = false;
}

AForm::AForm(const AForm &src): _name(src.GetName()), _grade_sign(src.GetGradeSign()), _grade_execute(src.GetGradeExecute())
{
	std::cout << "AForm Copy constructor called" << std::endl;
}


AForm& AForm::operator=( const AForm &src) 
{
    if ( this != &src )
        _Issigned = src.GetSigned();
    return *this;
}


AForm::~AForm(void)
{
	std::cout << "AForm deconstructor was created" << std::endl;
}


std::string AForm::GetName() const 
{
    return _name;
}

bool   AForm::GetSigned() const {
    return _Issigned;
}

int   AForm::GetGradeSign() const 
{
    return _grade_sign;
}

int   AForm::GetGradeExecute() const 
{
    return _grade_execute;
}

void    AForm::beSigned(const Bureaucrat &src) {
    if ( src.getGrade() > this->_grade_sign)
        throw AForm::GradeTooLowException();
    _Issigned = true;
}

std::ostream&   operator<<( std::ostream& o, const AForm& src) 
{
    o << "------------- AForm Info -------------" << std::endl;
    o << "AForm name: " << src.GetName() << std::endl
      << "Grade to sign: " << src.GetGradeSign() << std::endl
      << "Grade to execute: " << src.GetGradeExecute();
    return o;
}

const char * AForm::GradeTooHighException::what() const throw ()
{
	return ("Your Grade is too High");
}

const char * AForm::GradeTooLowException::what() const throw ()
{
	return ("Your Grade is too Low");
}

const char * AForm::NotExecute::what() const throw ()
{
	return ("Your grade execution is too Low !");
}

const char * AForm::NotSigned::what() const throw ()
{
	return ("Formulaire Not signed !");
}


std::string AForm::GetTarget() const 
{
	return this->_target;
}
