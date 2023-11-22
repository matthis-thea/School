/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thib <thib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:05:12 by tserdet           #+#    #+#             */
/*   Updated: 2023/11/17 13:45:14 by thib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("DefaultPresidentialPardonForm", 25, 5, "Default")
{
	std::cout <<CYN<< "Default PresidentialPardonForm constructor called" <<NC<< std::endl;
	return;
}

PresidentialPardonForm::PresidentialPardonForm(std::string name, std::string target): AForm(name, 25, 5, target)
{
	std::cout <<CYN<< name <<" AForm PresidentialPardonForm constructor called" <<NC<< std::endl;
	return;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & src) : AForm(src)
{
	std::cout <<CYN<< "Copy PresidentialPardonForm constructor called" <<NC<< std::endl;
	*this = src;
	return;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout <<CYN<< "Default PresidentialPardonForm destructor called" <<NC<< std::endl;
	return;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() < this->getGradeExec() && this->getSigned() == 1)
	{
		std::cout <<"Bureaucrat "<< executor.getName() <<  " executed PresidentialPardonForm" << std::endl;
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox"<< std::endl;
	}
	else
		std::cout << "Bureaucrat " << executor.getName() <<  " cannot execute PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=( PresidentialPardonForm const & hrs)
{
	std::cout << "PresidentialPardonForm Assignation operator called" << std::endl;
	if (this == &hrs)
		return *this;
	return *this;
}

std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm *a)
{
	o << "AForm " << a->getName() << ", signed: " << a->getSigned()
		<< ", grade to sign: " << a->getGradeSign() << ", grade to exec: " << a->getGradeExec()<< ", target: "
		<< a->getTarget() << std::endl;
	return (o);
}
