/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:55:30 by haze              #+#    #+#             */
/*   Updated: 2023/11/21 15:25:03 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm(25, "PresidentialPardonForm", 5), _target("louis")
{
	std::cout << "PresidentialPardonForm constructor was created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm(25, "PresidentialPardonForm", 5), _target(target)
{
	std::cout << "PresidentialPardonForm constructor was created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src): AForm(src), _target(src._target)
{
	std::cout << "Copy PresidentialPardonForm constructor was created" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	(void) src;
	std::cout << "PresidentialPardonForm surchage constructor was created" << std::endl;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm deconstructor was created" << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->GetGradeExecute())
		throw AForm::GradeTooLowException();
	else
		std::cout << _target << " has been pardoned by Zaphod Beeblerox" << std::endl;
}