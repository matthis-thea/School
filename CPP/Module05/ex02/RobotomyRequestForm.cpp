/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:04:12 by haze              #+#    #+#             */
/*   Updated: 2023/11/25 14:32:11 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(void): AForm(72, "RobotomyRequestForm", "Personne", 45), _target("louis")
{
	std::cout << "RobotomyRequestForm constructor was created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm(72, "RobotomyRequestForm",target, 45), _target(target)
{
	std::cout << "RobotomyRequestForm constructor was created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src): AForm(src), _target(src._target)
{
	std::cout << "Copy RobotomyRequestForm constructor was created" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	std::cout << "RobotomyRequestForm surchage constructor was created" << std::endl;
	if (this == &src)
		return *this;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm deconstructor was created" << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	std::srand(time(NULL));

	if (executor.getGrade() > this->GetGradeExecute())
		throw (AForm::NotExecute());
	else if (this->GetSigned() == false)
		throw (AForm::NotSigned());
	if (rand() % 2 == 0)
		std::cout << this->GetTarget() << " has been robotomized !" << std::endl;
	else
		std::cout << this->GetTarget() << " robotomized failure !" << std::endl;
}