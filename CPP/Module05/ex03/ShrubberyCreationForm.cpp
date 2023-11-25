/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:08:22 by haze              #+#    #+#             */
/*   Updated: 2023/11/25 14:39:04 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm(145, "ShrubberyCreationForm", "Personne", 137), _target("louis")
{
	std::cout << "ShrubberyCreationForm constructor was created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm(145, "ShrubberyCreationForm",target,  137), _target(target)
{
	std::cout << "ShrubberyCreationForm constructor was created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src): AForm(src), _target(src._target)
{
	std::cout << "Copy ShrubberyCreationForm constructor was created" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	(void) src;
	std::cout << "ShrubberyCreationForm surchage constructor was created" << std::endl;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm deconstructor was created" << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->GetGradeExecute())
		throw (AForm::NotExecute());
	else if (this->GetSigned() == false)
		throw (AForm::NotSigned());
	std::cout << "Shrubbery tree called" << std::endl;
	std::ofstream file (this->GetTarget().append("_shrubbery").c_str());
	file << std::endl;
	file << "@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
	file << "@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
	file << "@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
	file << "@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
	file << "@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
	file << "@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
	file << "     |||||||||||||||" << std::endl;
	file << "     |||||||||||||||" << std::endl;
	file << "     |||||||||||||||" << std::endl;
	file << "     |||||||||||||||" << std::endl;
	file << "     |||||||||||||||" << std::endl;
	file << "     |||||||||||||||" << std::endl;
	file << "     |||||||||||||||" << std::endl;
	file << "     |||||||||||||||" << std::endl;
	file << "     |||||||||||||||" << std::endl;
	file << "     |||||||||||||||" << std::endl;
	file << "     |||||||||||||||" << std::endl;
	file << "     |||||||||||||||" << std::endl;
	file << "     |||||||||||||||" << std::endl;
	file << "	/|||||||||||||\\" << std::endl;
	file.close();
}