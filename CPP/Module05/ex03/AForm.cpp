/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thib <thib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:18:48 by thib              #+#    #+#             */
/*   Updated: 2023/11/17 12:27:38 by thib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void): _name("default"), _isSigned(0), _gradeToSign(150), _gradeToExec(150), _target("default_target")
{
	std::cout <<CYN<< "Default AForm constructor called" <<NC<< std::endl;
	return;
}

AForm::~AForm(void)
{
	std::cout <<CYN<< this->_name << " AForm destructor called" <<NC<< std::endl;
	return;
}

AForm::AForm(AForm const & src): _name(src.getName()), _isSigned(false), _gradeToSign(src.getGradeSign()), _gradeToExec(src.getGradeExec()), _target(src.getTarget())
{
	std::cout <<CYN<< "Copy AForm constructor called" <<NC<< std::endl;
	*this = src;
	return;
}

AForm::AForm(std::string name, const int gradeToSign, const int _gradeToExec, std::string target): _name(name), _isSigned(0), _gradeToSign(gradeToSign), _gradeToExec(_gradeToExec), _target(target)
{
	std::cout <<CYN<< name <<" AForm constructor called" <<NC<< std::endl;
	return;
}

void AForm::execute(Bureaucrat const & executor) const
{
	std::cout << "AForm execute function called" << std::endl;
	(void) executor;
}

std::string AForm::getName() const
{
	return(this->_name);
}

std::string AForm::getTarget() const
{
	return(this->_target);
}

bool AForm::getSigned() const
{
	return(this->_isSigned);
}

int AForm::getGradeSign() const
{
	return(this->_gradeToSign);
}

int AForm::getGradeExec() const
{
	return(this->_gradeToExec);
}

void AForm::beSigned(Bureaucrat *b)
{
	if (b->getGrade() <= this->getGradeSign() && b->getGrade() > 0)
	{
		this->_isSigned = 1;
		std::cout << "Bureaucrat " << b->getName() << " signed " << this->getName() << " form" << std::endl;
	}
	else if(b->getGrade() > this->getGradeSign() || b->getGrade() > 150)
	{
		this->_isSigned = 0;
		std::cout << "Bureaucrat " << b->getName() << " couldn't sign " << this->getName() << " form because grade is too low" << std::endl;
		throw AForm::GradeTooLowException();
	}
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};

AForm& AForm::operator=( AForm const & hrs)
{
	std::cout << "AForm Assignation operator called" << std::endl;
	if (this == &hrs)
	{
		return *this;
	}
	return *this;
}


std::ostream	&operator<<(std::ostream &o, AForm *a)
{
	o << "AForm " << a->getName() << ", signed: " << a->getSigned()
		<< ", grade to sign: " << a->getGradeSign() << ", grade to exec: " << a->getGradeExec()<< ", target: "
		<< a->getTarget() << std::endl;
	return (o);
}
