/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:32:21 by haze              #+#    #+#             */
/*   Updated: 2023/11/24 14:32:22 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "RobotomyRequestForm.hpp"

static int half_time = 0;

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("DefaultRobotomyRequestForm", 72, 45, "Default")
{
	std::cout <<CYN<< "Default RobotomyRequestForm constructor called" <<NC<< std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string name, std::string target): AForm(name, 72, 45, target)
{
	std::cout <<CYN<< name <<" AForm RobotomyRequestForm constructor called" <<NC<< std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src) : AForm(src)
{
	std::cout <<CYN<< "Copy RobotomyRequestForm constructor called" <<NC<< std::endl;
	*this = src;
	return;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout <<CYN<< "Default RobotomyRequestForm destructor called" <<NC<< std::endl;
	return;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() < this->getGradeExec() && this->getSigned() == 1)
	{
		std::cout <<"Bureaucrat "<< executor.getName() <<  " executed RobotomyRequestForm" << std::endl;
		std::cout <<RED<< "---DRILLING NOISE---" <<NC<< std::endl;
		if (half_time++ % 2 == 0)
			std::cout << this->getTarget() << " has been robotomized" << std::endl;
		else
			std::cout << this->getTarget() << " robotomy failed" << std::endl;
	}
	else
		std::cout << "Bureaucrat " << executor.getName() <<  " cannot execute RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=( RobotomyRequestForm const & hrs)
{
	std::cout << "RobotomyRequestForm Assignation operator called" << std::endl;
	if (this == &hrs)
		return *this;
	return *this;
}

std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm *a)
{
	o << "AForm " << a->getName() << ", signed: " << a->getSigned()
		<< ", grade to sign: " << a->getGradeSign() << ", grade to exec: " << a->getGradeExec()<< ", target: "
		<< a->getTarget() << std::endl;
	return (o);
}
