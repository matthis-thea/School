/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:04:12 by haze              #+#    #+#             */
/*   Updated: 2023/11/21 16:07:12 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm(25, "RobotomyRequestForm", 5), _target("louis")
{
	std::cout << "RobotomyRequestForm constructor was created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm(25, "RobotomyRequestForm", 5), _target(target)
{
	std::cout << "RobotomyRequestForm constructor was created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src): AForm(src), _target(src._target)
{
	std::cout << "Copy RobotomyRequestForm constructor was created" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	(void) src;
	std::cout << "RobotomyRequestForm surchage constructor was created" << std::endl;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm deconstructor was created" << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->GetGradeExecute())
		throw AForm::GradeTooLowException();
	else
	{
		static int	i;
		if (i % 2 == 0)
			std::cout << _target << " has been robotomized !" << std::endl;
		else
			std::cout << _target << " robotomized failure !" << std::endl;
	}
}