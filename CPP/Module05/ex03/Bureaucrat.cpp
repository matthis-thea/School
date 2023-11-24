/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:31:53 by haze              #+#    #+#             */
/*   Updated: 2023/11/24 14:31:55 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("default")
{
	std::cout <<CYN<< "Default Bureaucrat constructor called" <<NC<< std::endl;
	setGrade(150);
	return;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout <<CYN<< this->_name << " bureaucrat destructor called" <<NC<< std::endl;
	return;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
	std::cout <<CYN<< "Copy Bureaucrat constructor called" <<NC<< std::endl;
	*this = src;
	return;
}

Bureaucrat::Bureaucrat(int grade) : _name("default")
{
	std::cout <<CYN<< "Default grade bureaucrat constructor called" <<NC<< std::endl;
	setGrade(grade);
	return;
}

Bureaucrat::Bureaucrat(const std::string name) : _name(name), _grade(150)
{
	std::cout <<CYN<< this->_name << " name bureaucrat constructor called" <<NC<< std::endl;
	return;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	std::cout <<CYN<< this->_name << " name & grade bureaucrat constructor called" <<NC<< std::endl;
	setGrade(grade);
	return;
}

void Bureaucrat::incrementGrade(int i)
{
	std::cout <<CYN<<"Incrementing " << this->_name << "'s grade" <<NC<< std::endl;
	setGrade(this->_grade - i);
}

void Bureaucrat::decrementGrade(int i)
{
	std::cout <<CYN<<"Decrementing " << this->_name << "'s grade" <<NC<< std::endl;
	setGrade(this->_grade + i);
}

int Bureaucrat::getGrade() const
{
	return(this->_grade);
}

std::string Bureaucrat::getName() const
{
	return(this->_name);
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = grade;
}

void Bureaucrat::signForm(AForm *f)
{
	f->beSigned(this);
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};

Bureaucrat& Bureaucrat::operator=( Bureaucrat const & hrs)
{
	if (this != &hrs)
	{
		this->_grade = hrs.getGrade();
	}
	return *this;
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat *a)
{
	o << "Bureaucrat " << a->getName() << " grade: " << a->getGrade() << std::endl;
	return (o);
}
