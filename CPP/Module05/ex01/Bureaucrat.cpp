/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:19:57 by haze              #+#    #+#             */
/*   Updated: 2023/11/21 14:30:20 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void):  _name("Francis"), _grade(5)
{
	std::cout << "Bureaucrat constructor was created" << std::endl;
}

Bureaucrat::Bureaucrat(int grade, const std::string name): _name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = grade;
	std::cout << "Bureaucrat constructor was created" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src):_name(src.getName())
{
	std::cout << "Bureaucrat Copy constructor called" << std::endl;
    *this = src;
}


Bureaucrat& Bureaucrat::operator=( const Bureaucrat &src) 
{
    if ( this != &src )
        _grade = src.getGrade();
    return *this;
}


Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat deconstructor was created" << std::endl;
}

const char * Bureaucrat::GradeTooHighException::what() const throw ()
{
	return ("Your Grade is too High");
}

const char * Bureaucrat::GradeTooLowException::what() const throw ()
{
	return ("Your Grade is too Low");
}

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &src)
{
	o << src.getName() << ", bureaucrat grade " << src.getGrade();
	return (o);
}

std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void Bureaucrat::inc_grade(void)
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = this->_grade - 1;
}

void Bureaucrat::dec_grade(void)
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = this->_grade + 1;
}

void Bureaucrat::signForm(Form &src)
{
	try 
	{
        src.beSigned( *this );
        std::cout << *this << " signed " << src.GetName() << std::endl;
    } catch (std::exception &e) 
	{
        std::cout << _name << " coulnd't sign " << src.GetName() << " because " << e.what() << std::endl;
    }
}