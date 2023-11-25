/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:55:30 by haze              #+#    #+#             */
/*   Updated: 2023/11/25 14:27:03 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm(25, "PresidentialPardonForm", "Personne", 5), _target("Personne")
{
	std::cout << "PresidentialPardonForm constructor was created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm(25, "PresidentialPardonForm",target, 5), _target(target)
{
	std::cout << "PresidentialPardonForm constructor was created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src): AForm(src), _target(src._target)
{
	std::cout << "Copy PresidentialPardonForm constructor was created" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	std::cout << "PresidentialPardonForm surchage constructor was created" << std::endl;
	if (this == &src)
		return *this;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm deconstructor was created" << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->GetGradeExecute())
		throw (AForm::NotExecute());
	else if (this->GetSigned() == false)
		throw (AForm::NotSigned());
	else
		std::cout << this->GetTarget() << " has been pardoned by Zaphod Beeblerox" << std::endl;
}